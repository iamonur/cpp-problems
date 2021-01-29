#ifdef MEASURE
#include <iostream>
#include "../../Utils/timer.h"
#endif

void recurse_to_100(unsigned int current = 0){
    if(current == 100)
        return;

    else
        recurse_to_100(current + 1);
}

int main(){
    #ifdef MEASURE
    timer t = timer();
    #endif
    recurse_to_100();
    #ifdef MEASURE
    double time_elapsed = t.time_end();
    std::cout<<"Time elapsed: "<<time_elapsed<<" seconds."<<std::endl;
    #endif
}