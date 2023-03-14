//
// Created by shepherd on 9.3.23.
//

#ifndef CHERNOENGINE_LAYER_HPP
#define CHERNOENGINE_LAYER_HPP

#include <string>

#include <chernoengine/events/event.hpp>

namespace chernoengine {

class Layer {
public:
    explicit Layer(const std::string &name = "Layer");

    virtual ~Layer() = default;

    virtual void OnAttach() {}

    virtual void OnDetach() {}

    virtual void OnUpdate() {}

    virtual void OnImguiRender() {}

    virtual void OnEvent(Event &event) {}

private:
    std::string name_;
};

class ExampleLayer : public Layer {
public:
    void OnImguiRender() override;
};

} // chernoengine

#endif //CHERNOENGINE_LAYER_HPP
