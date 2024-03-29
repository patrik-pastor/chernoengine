//
// Created by shepherd on 8.3.23.
//

#ifndef CHERNOENGINE_KEY_EVENT_HPP
#define CHERNOENGINE_KEY_EVENT_HPP

#include <chernoengine/events/event.hpp>

namespace chernoengine {

class KeyEvent : public Event {
public:
    int GetKeyCode() const;

    EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput);

protected:
    explicit KeyEvent(int key_code);

    int key_code_;
};

class KeyPressedEvent : public KeyEvent {
public:
    KeyPressedEvent(int key_code, bool repeat = false);

    bool IsRepeat() const;

    std::string ToString() const override;

    EVENT_CLASS_TYPE(KeyPressed);

private:
    bool repeat_;
};

class KeyReleasedEvent : public KeyEvent {
public:
    explicit KeyReleasedEvent(int key_code);

    std::string ToString() const override;

    EVENT_CLASS_TYPE(KeyReleased);
};

class KeyTypedEvent : public KeyEvent {
public:
    explicit KeyTypedEvent(int key_code);

    std::string ToString() const override;

    EVENT_CLASS_TYPE(KeyTyped)
};

} // chernoengine

#endif //CHERNOENGINE_KEY_EVENT_HPP
