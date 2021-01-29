#include <algorithm>
#include <iostream>
#ifdef MEASURE
#include "../../Utils/timer.h"
#endif

void printAllPerms(std::string input){
	std::sort(input.begin(), input.end());
	do{
		std::cout<<input<<std::endl;
	}while (std::next_permutation(input.begin(), input.end()));
}

int main() {
    #ifdef MEASURE
    timer t = timer();
    #endif
	printAllPerms("ABC");
    #ifdef MEASURE
    std::cout<<t.time_end()<<std::endl;
    #endif
}