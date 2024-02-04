#include "GameSystem.h"

void GameSystem::processInput(GLFWwindow *window)
{
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

void GameSystem::framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
  glViewport(0, 0, width, height);
}

void GameSystem::startEngine(scene *game)
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, gameTitle.c_str(), NULL, NULL);
  if (window == NULL)
  {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
  }
  glfwMakeContextCurrent(window);
  // glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Failed to initialize GLAD" << std::endl;
  }

  // int monitorCount;
  // GLFWmonitor **monitors = glfwGetMonitors(&monitorCount);

  // if (monitorCount > 1)
  // {
  //   GLFWmonitor *secondMonitor = monitors[1];
  //   const GLFWvidmode *secondMode = glfwGetVideoMode(secondMonitor);

  //   glfwSetWindowMonitor(window, secondMonitor, 0, 0, secondMode->width, secondMode->height, GLFW_DONT_CARE);
  // }

  game->startScene();

  while (!glfwWindowShouldClose(window))
  {
    processInput(window);

    glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    calculateFPS(window);
    game->updateScene();
    glfwSwapBuffers(window);
    game->onSwapBuffer();
    glfwPollEvents();
  }

  glfwTerminate();
}
