#include <iostream>
#include <set>

bool checkRow(unsigned char arr[9]){
    std::set<unsigned char> counter;
    unsigned char total = 0;
    for(unsigned char a = 0; a < 9; a++) {
        if(arr[a] != 0){
            total++;
            counter.insert(arr[a]);
        }
    }

    if(total != counter.size()) return false; return true;
}

bool checkCol(unsigned char arr[9][9], unsigned char column_index){
    std::set<unsigned char> counter;
    unsigned char total = 0;
    for(unsigned char a = 0; a < 9; a++){
        if(arr[a][column_index] != 0){
            total++;
            counter.insert(arr[a][column_index]);
        }
    }

    if(total != counter.size()) return false; return true;
}

/*
Matrices are:
    0   1   2

    3   4   5

    6   7   8
*/


/*
    Coordinates of a matrix are:
    [x/3*3 + 0, x%3*3 + 0] [x/3*3 + 0, x%3*3 + 1] [x/3*3 + 0, x%3*3 + 2]
    [x/3*3 + 1, x%3*3 + 0] [x/3*3 + 1, x%3*3 + 1] [x/3*3 + 1, x%3*3 + 2]
    [x/3*3 + 2, x%3*3 + 0] [x/3*3 + 2, x%3*3 + 1] [x/3*3 + 2, x%3*3 + 2]
*/
bool checkMat(unsigned char arr[9][9], unsigned char matrix_index){
    std::set<unsigned char> counter;
    unsigned char total = 0;
    for(unsigned char i = (matrix_index/3)*3; i <= (matrix_index/3)*3+2; i++)
        for(unsigned char j = (matrix_index%3)*3; j <= (matrix_index%3)*3+2; j++) {
            if(arr[i][j] != 0) {
                total++;
                counter.insert(arr[i][j]);
            }
        }
    if( total!= counter.size()) return false;
    return true;
}

bool checkSudoku(unsigned char arr[9][9]){
    for(unsigned char i = 0; i < 9; i++){
        if( !checkMat(arr, i)) return false;
        if( !checkCol(arr, i)) return false;
        if( !checkRow(arr[i])) return false;
    }
    return true;
}

int main() {
    unsigned char arr[9][9] = 
    {
        {5,3,0, 0,7,0, 0,0,0},
        {6,0,0, 1,9,5, 0,0,0},
        {0,9,8, 0,0,0, 0,6,0},

        {8,0,0, 0,6,0, 0,0,3},
        {4,0,0, 8,0,3, 0,0,1},
        {7,0,0, 0,2,0, 0,0,6},

        {0,6,0, 0,0,0, 2,8,0},
        {0,0,0, 4,1,9, 0,0,5},
        {0,0,0, 0,8,0, 0,7,9}
    };
    
    std::cout<<checkSudoku(arr)<<std::endl;
} 