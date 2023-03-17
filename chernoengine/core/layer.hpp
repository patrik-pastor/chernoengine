//
// Created by shepherd on 9.3.23.
//

#ifndef CHERNOENGINE_LAYER_HPP
#define CHERNOENGINE_LAYER_HPP

#include <memory>
#include <string>

#include <chernoengine/events/event.hpp>
#include <chernoengine/events/key_event.hpp>
#include <chernoengine/renderer/buffer.hpp>
#include <chernoengine/renderer/vertex_array.hpp>
#include <chernoengine/renderer/orthographic_camera.hpp>

namespace chernoengine {

class Layer {
public:
    explicit Layer(const std::string& name = "Layer");

    virtual ~Layer() = default;

    virtual void OnAttach() {}

    virtual void OnDetach() {}

    virtual void OnUpdate() {}

    virtual void OnImguiRender() {}

    virtual void OnEvent(Event& event) {}

private:
    std::string name_;
};

class ExampleLayer : public Layer {
public:
    ExampleLayer();

    void OnUpdate() override;

    void OnImguiRender() override;

private:
    std::shared_ptr<VertexArray> va_;
//    std::shared_ptr<VertexArray> square_va_;
    OrthographicCamera camera_;
};

} // chernoengine

#endif //CHERNOENGINE_LAYER_HPP
