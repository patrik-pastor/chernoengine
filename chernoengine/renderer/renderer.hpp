//
// Created by shepherd on 14.3.23.
//

#ifndef CHERNOENGINE_RENDERER_HPP
#define CHERNOENGINE_RENDERER_HPP

#include <chernoengine/renderer/renderer_api.hpp>

namespace chernoengine {

class Renderer {
public:
    static const RendererApi &GetRendererApi();

private:
    static RendererApi renderer_api_;
};

} // chernoengine

#endif //CHERNOENGINE_RENDERER_HPP
