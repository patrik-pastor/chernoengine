add_executable(main
        ${THIRD_PARTY_DIRECTORY}/glad/glad.c

        ../renderer/graphics_context.cpp
        ../renderer/opengl_context.cpp

        ../events/event.cpp
        ../events/application_event.cpp
        ../events/key_event.cpp
        ../events/mouse_event.cpp

        ../core/window.cpp
        ../core/linux_window.cpp

        ../core/layer.cpp
        ../core/layer_stack.cpp

        ../core/application.cpp
        main.cpp)
target_link_libraries(main glfw)