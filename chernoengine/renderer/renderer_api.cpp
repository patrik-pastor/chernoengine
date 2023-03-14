//
// Created by shepherd on 14.3.23.
//

#include <chernoengine/renderer/renderer_api.hpp>

namespace chernoengine {

RendererApi::API RendererApi::api_ = RendererApi::API::Opengl;

RendererApi::API RendererApi::GetApi() {
    return api_;
}
} // chernoengine