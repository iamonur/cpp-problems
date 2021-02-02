#include <vector>
#include <iostream>
#include <algorithm>

class DataStream {
        std::vector<unsigned int> data;
        unsigned int size;//No need to get length every time.
        double getMedian() {
            const auto middleItr = data.begin() + size / 2;
            std::nth_element(data.begin(), middleItr, data.end());
            if (size % 2 == 0) {
                const auto leftMiddleItr = std::max_element(data.begin(), middleItr);
                return ((double)*leftMiddleItr + (double)*middleItr) / 2;
            } else {
                return *middleItr;
            }
        }
    public:
        DataStream() {size = 0;}
        double insert(unsigned int value){
            data.push_back(value);
            size++;
            return getMedian();
        }
};

int main() {
    DataStream ds;
    for(int i = 0; i < 10; i++) {
        std::cout<<ds.insert(i)<<std::endl;
    }
}