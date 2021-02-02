#include <iostream>
#include <stack>
#include <vector>

class Histogram{
        std::vector<unsigned int> my_data;
        
    public:
        Histogram(std::vector<unsigned int> data) : my_data(data) {};
        unsigned int getArea() {
            std::stack<unsigned int> st;
            unsigned int currentMaxArea = 0;
            unsigned int temp, tempArea ,top, i = 0;
            while(i < my_data.size()) {
                if(st.empty() || my_data[i] >= (my_data[st.top()] )) st.push(i++);
                else {
                    top = st.top();
                    st.pop();
                    if(st.empty()) temp = i;
                    else temp = (i - st.top() - 1);
                    tempArea = my_data[top] * temp;

                    if(tempArea > currentMaxArea) currentMaxArea = tempArea;
                }
            }
            while (!st.empty()) {
                top = st.top();
                st.pop();

                if(st.empty()) temp = i;
                else temp = i - st.top() - 1;

                tempArea = my_data[top] * temp;

                if (currentMaxArea < tempArea) currentMaxArea = tempArea;
            }

            return currentMaxArea;
        }


};


int main() {
    std::vector<unsigned int> hist = {5,5,0,4,3,3,3};

    std::cout<<Histogram(hist).getArea()<<std::endl;
}