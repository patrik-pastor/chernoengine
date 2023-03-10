include_directories(${THIRD_PARTY_DIRECTORY}/imgui)

add_executable(imgui
        ${THIRD_PARTY_DIRECTORY}/glad/glad.c

        ${THIRD_PARTY_DIRECTORY}/imgui/imgui.cpp
        ${THIRD_PARTY_DIRECTORY}/imgui/imgui_demo.cpp
        ${THIRD_PARTY_DIRECTORY}/imgui/imgui_draw.cpp
        ${THIRD_PARTY_DIRECTORY}/imgui/imgui_tables.cpp
        ${THIRD_PARTY_DIRECTORY}/imgui/imgui_widgets.cpp
        ${THIRD_PARTY_DIRECTORY}/imgui/backends/imgui_impl_glfw.cpp
        ${THIRD_PARTY_DIRECTORY}/imgui/backends/imgui_impl_opengl3.cpp
        imgui.cpp)
target_link_libraries(imgui glfw)