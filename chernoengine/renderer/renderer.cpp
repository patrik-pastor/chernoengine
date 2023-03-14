//
// Created by shepherd on 14.3.23.
//

#include <chernoengine/renderer/renderer.hpp>

namespace chernoengine {

RendererApi Renderer::renderer_api_ = RendererApi();

const RendererApi &Renderer::GetRendererApi() {
    return renderer_api_;
}

} // chernoengine