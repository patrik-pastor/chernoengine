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

    void OnDetach() override;

    void Begin() const;

    void End() const;

    void OnImguiRender() override;
};

} // chernoengine

#endif //CHERNOENGINE_IMGUI_LAYER_HPP
