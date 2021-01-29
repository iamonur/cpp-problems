#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#ifdef MEASURE
#include "../../Utils/timer.h"
#endif

std::set<std::set<unsigned int>> quads;

void findQuads(unsigned int input[], unsigned int size, unsigned int sum=20) {
	std::unordered_map<unsigned int, std::vector<std::pair<unsigned int, unsigned int>>> theMap;

	for (unsigned int i = 0; i < size - 1; i++)
		for(unsigned int j = i + 1; j < size; j++){
			theMap[input[i]+input[j]].push_back(std::make_pair(i, j));
					
			if (theMap.find(sum-(input[i]+input[j])) != theMap.end()) {//If there is one
				for(auto pair: theMap.find(sum-(input[i]+input[j]))->second){
					if(pair.first != i && pair.first != j && pair.second != i && pair.second != j){
		unsigned int aa[]= {i,j,pair.first,pair.second};
		quads.insert(std::set<unsigned int>(aa,aa+4));			
					}
				}
			}
		}

}

int main(){
	unsigned int arr[] = { 2, 7, 4, 0, 9, 5, 1, 3 };
	unsigned int sum = 20;
 
    	unsigned int size = sizeof(arr) / sizeof(arr[0]);
#ifdef MEASURE
    timer t = timer();
#endif
    	findQuads(arr, size, sum);

	for(auto itr: quads){
		std::cout<<"[";
		for(unsigned int const& num : itr)
			std::cout<<arr[num]<<",";
		std::cout<<"\b]"<<std::endl;
	}
	std::cout<<quads.size()<<" quadruplet(s) exist."<<std::endl;
    #ifdef MEASURE
    std::cout<<t.time_end()<<std::endl;
    #endif
}
