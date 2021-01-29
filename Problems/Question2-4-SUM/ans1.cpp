#include <iostream>
#include <vector>
#ifdef MEASURE
#include "../../Utils/timer.h"
#endif
/*This algorithm is naive & uses recursion.*/
std::vector<unsigned int*> quadVec;
inline unsigned int sum_arr(unsigned int arr[4]){return arr[0]+arr[1]+arr[2]+arr[3];}
unsigned int goal;

void findQuads(unsigned int arr[], unsigned int arraySize, unsigned int elementsSoFar[4], unsigned int numberOfElements=0) {

	if (numberOfElements == 4) {
		if (sum_arr(elementsSoFar) == goal){

			quadVec.push_back(elementsSoFar);	
			std::cout<<"["<<elementsSoFar[0]<<", "<<elementsSoFar[1]<<", "<<elementsSoFar[2]<<", "<<elementsSoFar[3]<<"]"<<std::endl;

		}
		return;
	}

	if (arraySize+numberOfElements < 4) return;

	findQuads(arr, arraySize-1, elementsSoFar, numberOfElements);

	elementsSoFar[numberOfElements] = arr[arraySize-1];
	findQuads(arr, arraySize-1, elementsSoFar, numberOfElements+1);
}

int main() {
	unsigned int input[] = {2, 7, 4, 0, 9, 5, 1, 3};
	unsigned int size = sizeof(input)/sizeof(unsigned int);
	goal = 20;
	unsigned int quad[4]={0,0,0,0};
#ifdef MEASURE
    timer t = timer();
#endif
	findQuads(input, size,quad);
#ifdef MEASURE
    std::cout<<t.time_end()<<std::endl;
#endif
	std::cout<<quadVec.size()<<" quadruplet(s) exist."<<std::endl;

}

