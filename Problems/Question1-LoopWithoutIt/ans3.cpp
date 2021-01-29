//I cannot time this.
#include <iostream>
#if __INCLUDE_LEVEL__ == 0
int main(){
#endif
#if __INCLUDE_LEVEL__ < 100
#include "ans3.cpp"
#else
std::cout<<100<<std::endl;
    return 0;
}
#endif
