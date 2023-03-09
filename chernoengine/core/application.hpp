//
// Created by shepherd on 8.3.23.
//

#ifndef CHERNOENGINE_APPLICATION_HPP
#define CHERNOENGINE_APPLICATION_HPP

#include <chernoengine/core/window.hpp>

#include <memory>

#include <chernoengine/events/event.hpp>

namespace chernoengine {

class Application {
public:
    Application();
    void OnEvent(const Event& e);
    void Run();

private:
    std::unique_ptr<Window> window;
    bool is_running;
};

} // chernoengine

#endif //CHERNOENGINE_APPLICATION_HPP
