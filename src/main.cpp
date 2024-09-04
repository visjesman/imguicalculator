#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>



std::string numberLoop() {
    int mainnumber1 = 0;
    char digit[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    mainnumber1++;
    char aChar = digit[mainnumber1];
    if (mainnumber1 > 9) {
        mainnumber1 = 0;
    }
    return &aChar;
}

int main() {
    // Initialize GLFW
    if (!glfwInit())
        return -1;

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(1920, 1080, "calculator experiment", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);  // Enable vsync

    // Initialize GLEW
    glewExperimental = GL_TRUE;  // Enable experimental features
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW!" << std::endl;
        return -1;
    }

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Poll and handle events (inputs, window resize, etc.)
        glfwPollEvents();

        // Start the ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Your ImGui code here
        ImGui::Text("calculator");
        ImGui::Text(numberLoop().c_str());
        if (ImGui::Button("1"))
            glfwDestroyWindow(window);
        ImGui::SameLine();
        if (ImGui::Button("2"))
            glfwDestroyWindow(window);
        ImGui::SameLine();
        if (ImGui::Button("3"))
            glfwDestroyWindow(window);
        if (ImGui::Button("4"))
            glfwDestroyWindow(window);
        ImGui::SameLine();
        if (ImGui::Button("5"))
            glfwDestroyWindow(window);
        ImGui::SameLine();
        if (ImGui::Button("6"))
            glfwDestroyWindow(window);
        if (ImGui::Button("7"))
            glfwDestroyWindow(window);
        ImGui::SameLine();
        if (ImGui::Button("8"))
            glfwDestroyWindow(window);
        ImGui::SameLine();
        if (ImGui::Button("9"))
            glfwDestroyWindow(window);
        if (ImGui::Button("0"))
            glfwDestroyWindow(window);
        ImGui::End();


        // Rendering
        ImGui::Render();
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}



