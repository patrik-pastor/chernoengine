#include <chernoengine/core/application.hpp>
#include <chernoengine/core/layer.hpp>

int main() {
    chernoengine::Application app;
    app.PushLayer(new chernoengine::ExampleLayer);
    app.Run();
}
