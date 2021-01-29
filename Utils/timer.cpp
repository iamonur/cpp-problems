#include "timer.h"

timer::timer(){
    last_measured = std::chrono::system_clock::now();
    working = true;
}

double timer::time_end(){
    if(!working) return 0.0;
    working = false;
    return  std::chrono::duration<double>(std::chrono::system_clock::now()-last_measured).count();
}