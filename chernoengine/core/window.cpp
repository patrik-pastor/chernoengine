//
// Created by shepherd on 8.3.23.
//

#include <chernoengine/core/window.hpp>
#include <chernoengine/core/linux_window.hpp>

namespace chernoengine {

WindowProps::WindowProps(const std::string &title, int width, int height) : title(title), width(width),
                                                                            height(height) {}
} // chernoengine