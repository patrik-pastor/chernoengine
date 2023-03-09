//
// Created by shepherd on 8.3.23.
//

#include <iostream>

#include <chernoengine/events/application_event.hpp>

int main() {

    chernoengine::WindowResizeEvent e(1280, 720);
    if (e.IsInCategory(chernoengine::EventCategoryApplication)) {
        std::cout << "it is in EventCategoryApplication" << std::endl;
    }
    if (e.IsInCategory(chernoengine::EventCategoryInput)) {
        std::cout << "it is in EventCategoryInput" << std::endl;
    }
}