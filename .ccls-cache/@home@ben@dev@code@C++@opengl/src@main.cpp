#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Callbacks
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
}

// Window struct.
struct window {
  GLFWwindow* window;
  const char* title;
  int width;
  int height;

  // 
  inline void initWindow() {
    window = glfwCreateWindow(height, width, title, NULL, NULL);
  }
};

int main() {

  // Initialize glfw and give some sick hints
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // we love you mac, mwa! XOXOXO

  // Prepare window
  window win;
  win.width = 800;
  win.height = 600;
  win.title = "Hello, window!";

  win.initWindow();
  if (win.window == NULL) {
    std::cout << "Err: failed creating opengl window.\n";
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(win.window);

  // Prepare glad
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Err: failed initializing glad\n";
    return -1;
  }

  // Prepare opengl
  glViewport(0, 0, win.width, win.height);
  glfwSetFramebufferSizeCallback(win.window, framebuffer_size_callback);

  // Render loop
  while (!glfwWindowShouldClose(win.window))  {
    glfwSwapBuffers(win.window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}

// https://www.youtube.com/watch?v=B6DGB0oESzQ <- SICKEST ANIMATION AH
