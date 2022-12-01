#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "window/Window.hpp"

#include <iostream>

// Callbacks
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
}


// Function handlers
void processInput(GLFWwindow* window) {
   if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}

int main() {

  // Initialize glfw and give some sick hints
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // we love you mac, mwa! XOXOXO

  window win;
  windowInit(win);

  // Prepare glad
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Err: failed initializing glad\n";
    return -1;
  }

  glViewport(0, 0, win.width, win.height);
  glfwSetFramebufferSizeCallback(win.window, framebuffer_size_callback);

  // Render loop
  while (!glfwWindowShouldClose(win.window))  {
    processInput(win.window);

    glfwSwapBuffers(win.window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}

// https://www.youtube.com/watch?v=B6DGB0oESzQ <- SICKEST ANIMATION AH
