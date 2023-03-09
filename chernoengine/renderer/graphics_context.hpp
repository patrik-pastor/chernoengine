//
// Created by shepherd on 8.3.23.
//

#ifndef CHERNOENGINE_GRAPHICS_CONTEXT_HPP
#define CHERNOENGINE_GRAPHICS_CONTEXT_HPP

namespace chernoengine {

class GraphicsContext {
public:
    virtual ~GraphicsContext() = default;

    virtual void Init() = 0;

    static GraphicsContext *Create(void *window);
};

} // chernoengine

#endif //CHERNOENGINE_GRAPHICS_CONTEXT_HPP
