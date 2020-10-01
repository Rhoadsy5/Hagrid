#include <iostream>
#include <math.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


#define EXIT_BAD 1
#define EXIT_GOOD 0
#define DEFAULT_WIDTH 800
#define DEFAULT_HEIGHT 600

GLFWwindow* GameWindow = nullptr;
float wand = 0;

void Render() {
    wand = wand + 0.01f;

    glClearColor(sinf(wand), sinf(wand + 2.0f * M_PI / 3.0f), sinf(wand + 4.0f * M_PI / 3.0f), 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char** argv) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GameWindow = glfwCreateWindow(DEFAULT_WIDTH, DEFAULT_HEIGHT, "Project Hagrid", nullptr, nullptr);
    if (GameWindow == nullptr) {
        std::cout << "o no" << std::endl;
        return EXIT_BAD;
    }
    glfwMakeContextCurrent(GameWindow);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    // Specify the are of the window to draw into
    glViewport(0, 0, DEFAULT_WIDTH, DEFAULT_HEIGHT);

    // Main Loop - keep running until the user closes the window
    while (!glfwWindowShouldClose(GameWindow)) {
       
        Render();

        // Show our graphics on the screen
        glfwSwapBuffers(GameWindow);

        // Process events
        glfwPollEvents();
    }

    glfwTerminate();
    return EXIT_GOOD;
}