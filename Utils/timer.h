#ifndef TIMER_H
#define TIMER_H
#include <chrono>
class timer{
        std::chrono::time_point<std::chrono::system_clock> last_measured;
        bool working;
    public:
        timer();
        double time_end();
};

#endif//TIMER_H