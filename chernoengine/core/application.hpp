//
// Created by shepherd on 8.3.23.
//

#ifndef CHERNOENGINE_APPLICATION_HPP
#define CHERNOENGINE_APPLICATION_HPP

#include <chernoengine/core/window.hpp>

#include <memory>

#include <chernoengine/events/event.hpp>
#include <chernoengine/events/application_event.hpp>

namespace chernoengine {

class Application {
public:
    Application();
    virtual ~Application() = default;

    void OnEvent(Event &e);

    void Run();

    bool IsRunning() const;

    void SetRunning(bool running);

private:
    bool OnWindowClose(WindowCloseEvent& e);

    Window *window_;
    bool running_;
};

} // chernoengine

#endif //CHERNOENGINE_APPLICATION_HPP
