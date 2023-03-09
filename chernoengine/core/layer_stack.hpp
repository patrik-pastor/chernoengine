//
// Created by shepherd on 9.3.23.
//

#ifndef CHERNOENGINE_LAYER_STACK_HPP
#define CHERNOENGINE_LAYER_STACK_HPP

#include <vector>

#include <chernoengine/core/layer.hpp>

namespace chernoengine {

class LayerStack {
public:
    LayerStack() = default;

    void PushLayer(Layer *layer);

    void PushOverlay(Layer *overlay);
    // TODO: rest of stack operations

    std::vector<Layer *>::iterator begin();

    std::vector<Layer *>::iterator end();

    std::vector<Layer *>::const_iterator begin() const;

    std::vector<Layer *>::const_iterator end() const;

private:
    std::vector<Layer *> layers_;
    int layer_insert_index_ = 0;
};

} // chernoengine

#endif //CHERNOENGINE_LAYER_STACK_HPP
