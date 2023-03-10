#include <chernoengine/core/application.hpp>
#include <chernoengine/imgui/imgui_layer.hpp>

int main() {
    chernoengine::Application app;
    app.PushLayer(new chernoengine::ImguiLayer());
    app.Run();
}
