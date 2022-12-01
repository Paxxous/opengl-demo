#pragma once

#include <GLFW/glfw3.h>

// Window struct.
struct window {
  GLFWwindow* window;
  const char* title;
  int width;
  int height;

  // Mama
  inline void initWindow() {
    window = glfwCreateWindow(height, width, title, NULL, NULL);
  }
};

void windowInit(window &win);
