include_directories(${THIRD_PARTY_DIRECTORY}/spdlog/include)

add_executable(core
        ${THIRD_PARTY_DIRECTORY}/glad/glad.c

        ../renderer/graphics_context.cpp
        ../renderer/opengl_context.cpp

        ../events/event.cpp
        ../events/application_event.cpp

        window.cpp
        linux_window.cpp

        application.cpp
        core.cpp)
target_link_libraries(core glfw)