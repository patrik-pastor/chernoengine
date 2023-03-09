#include <iostream>

#include <chernoengine/core/application.hpp>

int main() {
    chernoengine::Application app;
    app.PushLayer(new chernoengine::ExampleLayer());
    app.Run();
}
