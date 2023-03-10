//
// Created by shepherd on 10.3.23.
//

#include <chernoengine/imgui/imgui_layer.hpp>

#include <iostream>

#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_opengl3.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <chernoengine/core/application.hpp>
#include <chernoengine/core/core.hpp>

namespace chernoengine {

ImguiLayer::ImguiLayer() : Layer("ImguiLayer") {}

void ImguiLayer::OnAttach() {
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGuiIO &io = ImGui::GetIO();
    // mousemapping
    io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
    io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

    // keymapping should be here as well

    ImGui_ImplOpenGL3_Init("#version 330");
}

void ImguiLayer::OnUpdate() {
    Application &app = Application::GetApplicationInstance();
    ImGuiIO &io = ImGui::GetIO();
    io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

    float time = (float) glfwGetTime();
    io.DeltaTime = time_ > 0.0f ? (time - time_) : (1.0f / 60.0f);
    time_ = time;

    ImGui_ImplOpenGL3_NewFrame();
    ImGui::NewFrame();

    static bool show = true;
    ImGui::ShowDemoWindow(&show);

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void ImguiLayer::OnEvent(Event &event) {
    EventDispatcher dispatcher(event);
    dispatcher.Dispatch<WindowResizeEvent>(IMGUI_BIND_EVENT_FN(ImguiLayer::OnWindowResizeEvent));
    dispatcher.Dispatch<MouseButtonPressedEvent>(IMGUI_BIND_EVENT_FN(ImguiLayer::OnMouseButtonPressedEvent));
    dispatcher.Dispatch<MouseButtonReleasedEvent>(IMGUI_BIND_EVENT_FN(ImguiLayer::OnMouseButtonReleaseEvent));
    dispatcher.Dispatch<MouseScrolledEvent>(IMGUI_BIND_EVENT_FN(ImguiLayer::OnMouseScrolledEvent));
    dispatcher.Dispatch<MouseMovedEvent>(IMGUI_BIND_EVENT_FN(ImguiLayer::OnMouseMovedEvent));
    dispatcher.Dispatch<KeyPressedEvent>(IMGUI_BIND_EVENT_FN(ImguiLayer::OnKeyPressedEvent));
    dispatcher.Dispatch<KeyReleasedEvent>(IMGUI_BIND_EVENT_FN(ImguiLayer::OnKeyReleasedEvent));
    dispatcher.Dispatch<KeyTypedEvent>(IMGUI_BIND_EVENT_FN(ImguiLayer::OnKeyTypedEvent));
}

bool ImguiLayer::OnWindowResizeEvent(WindowResizeEvent &e) {
    ImGuiIO& io = ImGui::GetIO();
    io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
    io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
    glViewport(0, 0, e.GetWidth(), e.GetHeight());
    return false;
}

bool ImguiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent &e) {
    ImGuiIO &io = ImGui::GetIO();
    io.MouseDown[e.GetMouseButton()] = true;
    return false;
}

bool ImguiLayer::OnMouseButtonReleaseEvent(MouseButtonReleasedEvent &e) {
    ImGuiIO &io = ImGui::GetIO();
    io.MouseDown[e.GetMouseButton()] = false;
    return false;
}

bool ImguiLayer::OnMouseScrolledEvent(MouseScrolledEvent &e) {
    ImGuiIO& io = ImGui::GetIO();
    io.MouseWheelH += e.GetXoffset();
    io.MouseWheel += e.GetYoffset();
    return false;
}

bool ImguiLayer::OnMouseMovedEvent(MouseMovedEvent &e) {
    ImGuiIO &io = ImGui::GetIO();
    io.MousePos = ImVec2(e.GetXpos(), e.GetYpos());
    return false;
}

bool ImguiLayer::OnKeyPressedEvent(KeyPressedEvent &e) {
    ImGuiIO& io = ImGui::GetIO();
    io.KeysDown[e.GetKeyCode()] = true;
    io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
    io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
    io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
    io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
    return false;
}

bool ImguiLayer::OnKeyReleasedEvent(KeyReleasedEvent &e) {
    ImGuiIO& io = ImGui::GetIO();
    io.KeysDown[e.GetKeyCode()] = false;
    return false;
}

bool ImguiLayer::OnKeyTypedEvent(KeyTypedEvent &e) {
     ImGuiIO& io = ImGui::GetIO();
     int keycode = e.GetKeyCode();
     if(keycode > 0 && keycode < 0x10000){
            io.AddInputCharacter(keycode);
     }
    return false;
}


} // chernoengine