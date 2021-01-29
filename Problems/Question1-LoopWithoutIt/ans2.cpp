#ifdef MEASURE
#include <iostream>
#include "../../Utils/timer.h"
#endif

int main() {
    #ifdef MEASURE
    timer t = timer();
    #endif
    unsigned int count = 0;
Label:
    if(count == 100) {
        #ifdef MEASURE
        double time_elapsed = t.time_end();
        std::cout<<"Time elapsed: "<<time_elapsed<<" seconds."<<std::endl;
        #endif
        return 0;
    }
    count++;
    goto Label;
}