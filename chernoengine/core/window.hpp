//
// Created by shepherd on 8.3.23.
//

#ifndef CHERNOENGINE_WINDOW_HPP
#define CHERNOENGINE_WINDOW_HPP

#include <string>
#include <functional>

#include <chernoengine/events/event.hpp>

namespace chernoengine {

struct WindowProps {
    std::string title;
    int width;
    int height;

    WindowProps(const std::string &title = "Cherno Engine",
                int width = 800,
                int height = 600);
};

class Window {
public:
    using EventCallbackFn = std::function<void(Event &)>;

    virtual ~Window() = default;

    virtual void OnUpdate() = 0;

    virtual int GetWidth() const = 0;

    virtual int GetHeight() const = 0;

    virtual void SetEventCallback(const EventCallbackFn callback) = 0;
    //TODO: rest
};

} // chernoengine

#endif //CHERNOENGINE_WINDOW_HPP
