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

    virtual void OnAttach() = 0;

    virtual void OnUpdate() = 0;

    virtual void OnEvent(Event &event) = 0;

    //TODO: rest of "On*" callbacks

private:
    std::string name_;
};

} // chernoengine

#endif //CHERNOENGINE_LAYER_HPP
