//
// Created by shepherd on 14.3.23.
//

#ifndef CHERNOENGINE_RENDERER_API_HPP
#define CHERNOENGINE_RENDERER_API_HPP

namespace chernoengine {

class RendererApi {
public:
    enum class API {
        None = 0, Opengl = 1
    };

    static API GetApi();

private:
    static API api_;
};

} // chernoengine

#endif //CHERNOENGINE_RENDERER_API_HPP
