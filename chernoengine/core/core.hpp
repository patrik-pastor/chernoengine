//
// Created by shepherd on 8.3.23.
//

#ifndef CHERNOENGINE_CORE_HPP
#define CHERNOENGINE_CORE_HPP

#include <functional>

#define BIT(x) (1 << x)

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
#define IMGUI_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

#endif //CHERNOENGINE_CORE_HPP