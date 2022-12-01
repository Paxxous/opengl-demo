cmake_minimum_required(VERSION 3.25.0)
project("opengl")

find_package(OpenGL REQUIRED)

# link cpp files
add_executable(${PROJECT_NAME}
  "src/glad.c"
  "src/main.cpp"
)

# setup glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory("include/glfw-3.3.8")
add_subdirectory("src")

target_include_directories(${PROJECT_NAME} PUBLIC
  ${PROJECT_SOURCE_DIR}/include
)

# include_directories("include")

# link to executable
target_link_libraries(${PROJECT_NAME}
  WINDOW

  OpenGL
  glfw
)

# configure some options
add_compile_options(
  -Wall -Werror # If warnings are error mybad, remove Werror
)
