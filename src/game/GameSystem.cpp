#include "GameSystem.h"

GLFWwindow *GameSystem::window = nullptr;

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

  const double target_fps = 60.0;
  const double target_frame_time = 1.0 / target_fps;

  double lastFrameTime = glfwGetTime();
  double accumulatedTime = 0.0;

  while (!glfwWindowShouldClose(window))
  {
    double currentFrameTime = glfwGetTime();
    double deltaTime = currentFrameTime - lastFrameTime;
    lastFrameTime = currentFrameTime;

    accumulatedTime += deltaTime;

    processInput(window);

    // Renderizar solo si ha pasado suficiente tiempo desde el último cuadro
    if (accumulatedTime >= target_frame_time)
    {
      glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);

      calculateFPS(window);
      game->updateScene(static_cast<float>(deltaTime));
      glfwSwapBuffers(window);
      game->onSwapBuffer();

      accumulatedTime -= target_frame_time; // Restar el tiempo utilizado para renderizar
    }

    glfwPollEvents();
  }
  glfwTerminate();
}
