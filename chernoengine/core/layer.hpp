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

    virtual void OnUpdate() {}

    virtual void OnEvent(Event &event) {}

    //TODO: rest of "On*" callbacks

private:
    std::string name_;
};

class ExampleLayer : public Layer {
public:
    ExampleLayer();

    void OnUpdate() override;

    void OnEvent(Event &event) override;
};

} // chernoengine

#endif //CHERNOENGINE_LAYER_HPP
