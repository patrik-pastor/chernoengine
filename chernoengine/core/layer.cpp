//
// Created by shepherd on 9.3.23.
//

#include <chernoengine/core/layer.hpp>

#include <imgui/imgui.h>

#include <iostream>

namespace chernoengine {

Layer::Layer(const std::string &name) : name_(name) {}

void ExampleLayer::OnImguiRender() {
    ImGui::Begin("Test");
    ImGui::Text("Hello World");
    ImGui::End();
}

} // chernoengine