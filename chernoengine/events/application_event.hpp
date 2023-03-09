//
// Created by shepherd on 8.3.23.
//

#ifndef CHERNOENGINE_APPLICATION_EVENT_HPP
#define CHERNOENGINE_APPLICATION_EVENT_HPP

#include <chernoengine/events/event.hpp>

namespace chernoengine {

class WindowResizeEvent : public Event {
public:
    WindowResizeEvent(int width, int height);

    std::string ToString() const override;

    EVENT_CLASS_TYPE(WindowResize);

    EVENT_CLASS_CATEGORY(EventCategoryApplication)

private:
    int width_, height_;
};

class WindowCloseEvent : public Event {
public:
    EVENT_CLASS_TYPE(WindowClose);

    EVENT_CLASS_CATEGORY(EventCategoryApplication);
};

} // chernoengine

#endif //CHERNOENGINE_APPLICATION_EVENT_HPP
