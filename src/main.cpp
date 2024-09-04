#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <vector>





std::string numberLoop(int newDigit, std::string currentNumber) {
    currentNumber += std::to_string(newDigit);

    return currentNumber;
}

std::vector<int> Add;

void AddnumberToArray(std::string number) {
    if (!number.empty()) {
        int Number = std::stoi(number);
        Add.push_back(Number);
    } else {
        std::cout << number << " is empty" << std::endl;
    }
}





int main() {
    std::string currentNumber = "";
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




        if (ImGui::Button("1"))
            currentNumber = numberLoop(1, currentNumber);
        ImGui::SameLine(); if (ImGui::Button("2"))
            currentNumber = numberLoop(2, currentNumber);
        ImGui::SameLine(); if (ImGui::Button("3"))
            currentNumber = numberLoop(3, currentNumber);
        if (ImGui::Button("4"))
            currentNumber = numberLoop(4, currentNumber);
        ImGui::SameLine(); if (ImGui::Button("5"))
            currentNumber = numberLoop(5, currentNumber);
        ImGui::SameLine(); if (ImGui::Button("6"))
            currentNumber = numberLoop(6, currentNumber);
        if (ImGui::Button("7"))
            currentNumber = numberLoop(7, currentNumber);
        ImGui::SameLine(); if (ImGui::Button("8"))
            currentNumber = numberLoop(8, currentNumber);
        ImGui::SameLine(); if (ImGui::Button("9"))
            currentNumber = numberLoop(9, currentNumber);
        if (ImGui::Button("0"))
            currentNumber = numberLoop(0, currentNumber);



        if (ImGui::Button("+")) {
            if (!currentNumber.empty()) {
                AddnumberToArray(currentNumber);
                currentNumber = "";  // Clear the current number
            }
        }







        ImGui::SameLine(); if (ImGui::Button("-"))
            glfwDestroyWindow(window);
        ImGui::SameLine(); if (ImGui::Button("/"))
            glfwDestroyWindow(window);
        ImGui::SameLine(); if (ImGui::Button("*"))
            glfwDestroyWindow(window);
        ImGui::SameLine(); if (ImGui::Button("Enter"))
            glfwDestroyWindow(window);



        ImGui::Text("Numbers:");
        for (size_t i = 0; i < Add.size(); i++) {
            ImGui::Text("%d", Add[i]);
        }



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



