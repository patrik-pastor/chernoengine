//
// Created by shepherd on 8.3.23.
//

#ifndef CHERNOENGINE_EVENT_HPP
#define CHERNOENGINE_EVENT_HPP

#include <string>

#include <chernoengine/core/core.hpp>

namespace chernoengine {

enum EventCategory {
    NONE = 1,
    EventCategoryApplication = BIT(0),
    EventCategoryInput = BIT(1),
    EventCategoryKeyboard = BIT(2),
    EventCategoryMouse = BIT(3),
    EventCategoryMouseButton = BIT(4)
};

#define EVENT_CLASS_CATEGORY(category) int GetCategoryFlags() const override { return category; }

class Event {
public:
    virtual ~Event() = default;

    virtual std::string ToString() const = 0;

    virtual int GetCategoryFlags() const = 0;

    bool IsInCategory(EventCategory category) const;
};

} // chernoengine

#endif //CHERNOENGINE_EVENT_HPP
