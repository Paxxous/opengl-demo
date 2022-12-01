#include <iostream>

#include "Window.hpp"

void windowInit(window &win) {
  // Prepare window
  win.width = 800;
  win.height = 600;
  win.title = "Hello, window!";

  win.initWindow();
  if (win.window == NULL) {
    std::cout << "Err: failed creating opengl window.\n";
    glfwTerminate();
  }
  glfwMakeContextCurrent(win.window);
}
