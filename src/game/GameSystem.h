#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "scene.h"

#include <iostream>
#include <sstream>
#include <iomanip>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtx/normalize_dot.hpp>

class GameSystem
{
public:
  // Game Resolution
  unsigned int SCR_WIDTH = 800;
  unsigned int SCR_HEIGHT = 600;

  static GLFWwindow *window;

  string gameTitle = "Terra";

  GameSystem()
  {
    std::cout << "Game System Started" << std::endl;
  }

  ~GameSystem()
  {
    std::cout << "Game System Finished" << std::endl;
  }

  void startEngine(scene *game);
  void processInput(GLFWwindow *window);

  void framebuffer_size_callback(GLFWwindow *window, int width, int height);

  void calculateFPS(GLFWwindow *window)
  {
    static double lastTime = glfwGetTime();
    static int frameCount = 0;

    double currentTime = glfwGetTime();
    double deltaTime = currentTime - lastTime;
    frameCount++;

    if (deltaTime >= 1.0)
    {
      double fps = static_cast<double>(frameCount) / deltaTime;

      // Mostrar los FPS en la consola
      // std::cout << "FPS: " << std::fixed << std::setprecision(2) << fps << std::endl;

      // Actualizar el título de la ventana con los FPS
      std::ostringstream titleStream;
      titleStream << gameTitle + " | FPS: " << std::fixed << std::setprecision(2) << fps;
      glfwSetWindowTitle(window, titleStream.str().c_str());

      frameCount = 0;
      lastTime = currentTime;
    }
  }
};