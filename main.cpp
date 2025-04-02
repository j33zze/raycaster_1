#include <iostream>
#include "src/glad/glad.h"//pirms GLWF(obliagti) look at later | makes creating  easier
#include "GLFW/glfw3.h" //opengl library   |   opengl == API

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {

        glfwSetWindowShouldClose(window, true);
    }
}

int main(){

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(1024, 512, "gayme", NULL, NULL);  
    // "*" declares that a variable is a pointer

    if (!window) {

        std::cout << "Window creation failed\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {

        std::cout << "GLAD initialization failed!\n";
        glfwTerminate();
        return -1;
    }

    glViewport(0, 0, 1024, 512);

    while (!glfwWindowShouldClose(window)) {

        processInput(window);

        glfwPollEvents();

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}