#include "timer.h"
#include <thread>

Timer::Timer() {
}
void Timer::add(std::chrono::milliseconds delay, std::function<void()> callback, bool asynchronous) 
{
    if (asynchronous) 
    {
        isEnabled = true;
        std::thread([=]() 
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
            callback();
        }
        ).detach();
    }
    else 
    {
        isEnabled = true;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        callback();
    }
}