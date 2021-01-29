#ifndef INPUT_GENERATOR_H
#define INPUT_GENERATOR_H

#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <ctime>

template <typename T>
class InputGenerator{
        InputGenerator() = delete;
    protected:
        virtual T generateOne() = 0;
    public:
        static T* generateArray(unsigned int const count);
        //static T[] generateSortedArray(unsigned int const count, bool ascending=true);
        static std::vector<T> generateVector(unsigned int const count);
};

template <>
class InputGenerator<int> {
        static int generateOne();
    public:
        static int* generateArray(unsigned int const count);
        //static int* generateSortedArray(unsigned int const count, bool ascending=true);
        static std::vector<int> generateVector(unsigned int const count);
};

template <>
class InputGenerator<std::string> {
        static char generateOne();
    public:
        static std::string generateString(unsigned int const size);
};

#endif//INPUT_GENERATOR_H