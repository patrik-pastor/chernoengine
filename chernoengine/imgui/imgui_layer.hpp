//
// Created by shepherd on 10.3.23.
//

#ifndef CHERNOENGINE_IMGUI_LAYER_HPP
#define CHERNOENGINE_IMGUI_LAYER_HPP

#include <chernoengine/core/layer.hpp>
#include <chernoengine/events/application_event.hpp>
#include <chernoengine/events/mouse_event.hpp>
#include <chernoengine/events/key_event.hpp>

namespace chernoengine {

class ImguiLayer : public Layer {
public:
    ImguiLayer();

    void OnAttach() override;

    void OnUpdate() override;

    void OnEvent(Event &event) override;

private:
    bool OnWindowResizeEvent(WindowResizeEvent &e);

    bool OnMouseButtonPressedEvent(MouseButtonPressedEvent &e);

    bool OnMouseButtonReleaseEvent(MouseButtonReleasedEvent &e);

    bool OnMouseScrolledEvent(MouseScrolledEvent &e);

    bool OnMouseMovedEvent(MouseMovedEvent &e);

    bool OnKeyPressedEvent(KeyPressedEvent &e);

    bool OnKeyReleasedEvent(KeyReleasedEvent &e);

    bool OnKeyTypedEvent(KeyTypedEvent& e);

    float time_ = 0.0f;
};

} // chernoengine

#endif //CHERNOENGINE_IMGUI_LAYER_HPP
