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

    EVENT_CLASS_CATEGORY(EventCategoryApplication)

private:
    int width, height;
};

} // chernoengine

#endif //CHERNOENGINE_APPLICATION_EVENT_HPP
