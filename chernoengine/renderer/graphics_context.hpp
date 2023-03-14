//
// Created by shepherd on 8.3.23.
//

#ifndef CHERNOENGINE_GRAPHICS_CONTEXT_HPP
#define CHERNOENGINE_GRAPHICS_CONTEXT_HPP

namespace chernoengine {

class GraphicsContext {
public:
    static GraphicsContext *Create(void *window);

    virtual ~GraphicsContext() = default;

    virtual void Init() = 0;

    virtual void SwapBuffers() = 0;
};

} // chernoengine

#endif //CHERNOENGINE_GRAPHICS_CONTEXT_HPP
