//
// Created by shepherd on 6.3.23.
//

#include <chernoengine/logging/log.hpp>

int main(){
    chernoengine::Log::Init();
    int a = 5;
    CORE_WARN("Initialized Log!");
    CORE_INFO("Hello! Var={0}", a);
}
