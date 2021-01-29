#include "inputGenerator.h"

int InputGenerator<int>::generateOne(){
    srand((unsigned) time(NULL));
    return rand();
}

int* InputGenerator<int>::generateArray(unsigned int const count){
    int* ret = new int[count];
    for(unsigned int i = 0; i < count; i++) ret[i] = generateOne();
    return ret;
}

std::vector<int> InputGenerator<int>::generateVector(unsigned int const count){
    std::vector<int> ret;
    for(unsigned int i = 0; i < count; i++) ret.push_back(generateOne());
    return ret;
}

char InputGenerator<std::string>::generateOne(){
    std::string ret;
    static const char alphaNumerics[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    srand((unsigned) time(NULL));

    return alphaNumerics[(rand() % sizeof(alphaNumerics) - 1)];
}

std::string InputGenerator<std::string>::generateString(unsigned int const size){
    std::string ret;
    ret.reserve(size);

    for(unsigned int i = 0; i < size; i++) ret += generateOne();

    return ret;
}