//
// Created by shepherd on 8.3.23.
//

#include <chernoengine/events/event.hpp>

namespace chernoengine {

bool Event::IsInCategory(EventCategory category) const {
    return GetCategoryFlags() & category;
}

std::string Event::ToString() const {
    return GetName();
}

EventDispatcher::EventDispatcher(Event &event) : event_(event) {}

} // chernoengine