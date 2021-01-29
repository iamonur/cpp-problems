#include <string>
#include <iostream>
#ifdef MEASURE
#include "../../Utils/timer.h"
#endif
void printAllPerm(std::string input, std::string ans=""){
    if(input == "") std::cout<<ans<<std::endl;
    for(int i = 0; i < input.size(); i++) printAllPerm(input.substr(0,i)+input.substr(i+1,input.size()-i), ans+input[i]);
}

int main() {
    #ifdef MEASURE
    timer t = timer();
    #endif
    printAllPerm("ABC", "");
    #ifdef MEASURE
    std::cout<<t.time_end()<<std::endl;
    #endif
}