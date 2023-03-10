//
// Created by shepherd on 8.3.23.
//

#ifndef CHERNOENGINE_APPLICATION_HPP
#define CHERNOENGINE_APPLICATION_HPP

#include <chernoengine/core/window.hpp>

#include <memory>

#include <chernoengine/events/event.hpp>
#include <chernoengine/events/application_event.hpp>
#include <chernoengine/core/layer_stack.hpp>

namespace chernoengine {

class Application {
public:
    Application();

    void OnEvent(Event &e);

    void Run();

    bool IsRunning() const;

    void SetRunning(bool running);

    void PushLayer(Layer *layer);

    void PushOverlay(Layer *layer);

    static Application& GetApplicationInstance();

    Window &GetWindow() const;

private:
    static Application *application_instance_;

    bool OnWindowClose(WindowCloseEvent &e);

    Window *window_;
    bool running_;
    LayerStack layer_stack_;
};

} // chernoengine

#endif //CHERNOENGINE_APPLICATION_HPP
