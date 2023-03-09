//
// Created by shepherd on 9.3.23.
//

#include <chernoengine/core/layer.hpp>

#include <iostream>

namespace chernoengine {

Layer::Layer(const std::string &name) : name_(name) {}

ExampleLayer::ExampleLayer() : Layer("Example") {}

void ExampleLayer::OnUpdate() {
    std::cout << "ExampleLayer::Update\n";
}

void ExampleLayer::OnEvent(Event &event) {
    std::cout << event.ToString() << std::endl;
}

} // chernoengine