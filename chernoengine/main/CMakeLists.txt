include_directories(${THIRD_PARTY_DIRECTORY}/imgui)

add_executable(main
        ${THIRD_PARTY_DIRECTORY}/glad/glad.c

        ${THIRD_PARTY_DIRECTORY}/imgui/imgui.cpp
        ${THIRD_PARTY_DIRECTORY}/imgui/imgui_demo.cpp
        ${THIRD_PARTY_DIRECTORY}/imgui/imgui_draw.cpp
        ${THIRD_PARTY_DIRECTORY}/imgui/imgui_tables.cpp
        ${THIRD_PARTY_DIRECTORY}/imgui/imgui_widgets.cpp
        ${THIRD_PARTY_DIRECTORY}/imgui/backends/imgui_impl_glfw.cpp
        ${THIRD_PARTY_DIRECTORY}/imgui/backends/imgui_impl_opengl3.cpp

        ../renderer/graphics_context.cpp
        ../renderer/opengl_context.cpp

        ../events/event.cpp
        ../events/application_event.cpp
        ../events/key_event.cpp
        ../events/mouse_event.cpp

        ../imgui/imgui_layer.cpp

        ../core/window.cpp
        ../core/linux_window.cpp

        ../core/layer.cpp
        ../core/layer_stack.cpp

        ../core/input.cpp

        ../core/application.cpp
        main.cpp)
target_link_libraries(main glfw)