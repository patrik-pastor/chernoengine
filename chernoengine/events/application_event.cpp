//
// Created by shepherd on 8.3.23.
//

#include <chernoengine/events/application_event.hpp>

#include <sstream>

namespace chernoengine {

WindowResizeEvent::WindowResizeEvent(int width, int height) : width(width), height(height) {}

std::string WindowResizeEvent::ToString() const {
    std::stringstream ss;
    ss << "WindowResizeEvent: " << width << ", " << height;
    return ss.str();
}

} // chernoengine