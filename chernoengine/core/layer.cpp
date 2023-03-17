//
// Created by shepherd on 9.3.23.
//

#include <chernoengine/core/layer.hpp>

#include <imgui/imgui.h>

#include <iostream>

#include <chernoengine/renderer/renderer.hpp>
#include <chernoengine/renderer/renderer_command.hpp>

namespace chernoengine {

Layer::Layer(const std::string& name) : name_(name) {}

ExampleLayer::ExampleLayer() : Layer("Example"), camera_(-1.6f, 1.6f, -0.9f, 0.9f) {
    va_ = VertexArray::Create();

    float vertices[] = {
            0.5f, 0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f
    };

    auto vb = std::shared_ptr<VertexBuffer>(VertexBuffer::Create(vertices, sizeof(vertices)));
    BufferLayout layout = {
            {ShaderDataType::Float3, "a_Position"}
    };
    vb->SetLayout(layout);
    va_->AddVertexBuffer(vb);

    int indices[] = {0, 1, 2};
    auto ib = std::shared_ptr<IndexBuffer>(IndexBuffer::Create(indices, sizeof(indices) / sizeof(int)));
    va_->SetIndexBuffer(ib);
}

void ExampleLayer::OnUpdate() {
    RendererCommand::SetClearColor({0.1f, 0.1f, 0.1f, 1.0f});
    RendererCommand::Clear();

    camera_.SetPosition({0.5f, 0.5f, 0.0f});
    camera_.SetRotation(45.0f);

    Renderer::BeginScene(camera_);
    Renderer::Submit(va_);
    Renderer::EndScene();
}

void ExampleLayer::OnImguiRender() {
    ImGui::Begin("Test");
    ImGui::Text("Hello World");
    ImGui::End();
}

} // chernoengine