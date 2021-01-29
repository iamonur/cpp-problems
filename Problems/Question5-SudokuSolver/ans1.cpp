#include <iostream>
#include <set>
#include <string.h>
#include <stack>

/*
Functions we implemented at Q4 becomes handy here.
*/
bool checkRow(unsigned char (&arr)[9]){
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

bool checkCol(unsigned char (&arr)[9][9], unsigned char column_index){
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

std::set<unsigned char> eligibles(unsigned char(&arr)[9][9], unsigned char index_1, unsigned char index_2){
    std::set<unsigned char> s {1,2,3,4,5,6,7,8,9};
    for(unsigned char i = 0; i < 9; i++) {
        s.erase(arr[i][index_2]);
        s.erase(arr[index_1][i]);
    }// TODO: erase with 3*3 matrices next.
    return s;
}

/*
    Coordinates of a matrix are:
    [x/3*3 + 0, x%3*3 + 0] [x/3*3 + 0, x%3*3 + 1] [x/3*3 + 0, x%3*3 + 2]
    [x/3*3 + 1, x%3*3 + 0] [x/3*3 + 1, x%3*3 + 1] [x/3*3 + 1, x%3*3 + 2]
    [x/3*3 + 2, x%3*3 + 0] [x/3*3 + 2, x%3*3 + 1] [x/3*3 + 2, x%3*3 + 2]
*/
bool checkMat(unsigned char (&arr)[9][9], unsigned char matrix_index){
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

bool checkSudoku(unsigned char (&arr)[9][9]){
    for(unsigned char i = 0; i < 9; i++){
        if( !checkMat(arr, i)) return false;
        if( !checkCol(arr, i)) return false;
        if( !checkRow(arr[i])) return false;
    }
    return true;
}

void printSudoku(unsigned char (&arr)[9][9]) {

    for(unsigned char i = 0; i < 9; i++) {
        for(unsigned char j = 0; j < 9; j++){
            std::cout<<(int)arr[i][j];
            if(j%3 == 2) std::cout<<"\t";
        }
        std::cout<<std::endl;
        if(i%3 == 2) std::cout<<std::endl;
    }

}

class sudoku_puzzle{
    unsigned char my_puzzle[9][9];
    public:
        unsigned char get_val(unsigned char i, unsigned char j){
            return my_puzzle[i][j];
        }
        bool set_val(unsigned char i, unsigned char j, unsigned char val){
            unsigned char temp = my_puzzle[i][j];
            my_puzzle[i][j] = val;
            if(val == 0) return true;
            if(checkSudoku(my_puzzle) == true) return true;
            my_puzzle[i][j] = temp;
            return false; 
        }
        sudoku_puzzle(unsigned char puzzle[9][9]){
            memcpy(my_puzzle, puzzle, 81*sizeof(unsigned char));
            //std::copy(puzzle, puzzle+9*9, my_puzzle);
        }
        bool check_my_puzzle(){
            return checkSudoku(my_puzzle);
        }
        std::set<unsigned char> check_eligbles(unsigned char i, unsigned char j){
           
            std::set<unsigned char> s {1,2,3,4,5,6,7,8,9};
            for(unsigned char ii = 0; ii < 9; ii++) {
                s.erase(my_puzzle[ii][j]);
                s.erase(my_puzzle[i][ii]);
            }

            unsigned char matrix_index = (i/3)*3+j/3;
            for(unsigned char q = (matrix_index/3)*3; q <= (matrix_index/3)*3+2; q++)
                for(unsigned char w = (matrix_index%3)*3; w <= (matrix_index%3)*3+2; w++) 
                    s.erase(my_puzzle[q][w]);
            
            return s;
        }
        void printPuzzle(){
            for(unsigned char i = 0; i < 9; i++) {
                for(unsigned char j = 0; j < 9; j++){
                    std::cout<<(int)my_puzzle[i][j];
                    if(j%3 == 2) std::cout<<"\t";
                }
                std::cout<<std::endl;
                if(i%3 == 2) std::cout<<std::endl;
            }
        }


};

void logFromStack(std::stack<std::string> logStack){

}

bool solveSudoku(sudoku_puzzle* sudoku) {
    std::stack<std::string> logStack;
    //Check if valid
    if(sudoku->check_my_puzzle() == false) return false;
    //Find next 0
    for(unsigned char i = 0; i < 9; i++) {
        for(unsigned char j = 0; j < 9; j++){
            if(sudoku->get_val(i,j) == 0) {
                auto eligs = sudoku->check_eligbles(i,j);
                for(unsigned char elig: eligs){
                    if(sudoku->set_val(i,j,elig) == false) continue;
                    //sudoku->printPuzzle();
                    if ( solveSudoku(sudoku)) return true;
                }


                sudoku->set_val(i,j,0);
                logFromStack(logStack);

                return false;
                /*auto asd = eligs.begin();
                while(asd != eligs.end()) {
                    arr[i][j] = asd->value;

                    if(solveSudoku(arr) == true) return true;
                    else if(asd == 9) {
                        arr[i][j] = 0;
                        return false;
                    }
                    asd++;
                }*/
            }
        }
    }
    std::cout<<"Solved"<<std::endl;
    return true;
}

int main() {
    /*unsigned char arr[9][9] = 
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
    };*/
    /*unsigned char arr[9][9] = 
    {
        {0,0,0, 0,0,0, 2,0,0},
        {0,8,0, 0,0,7, 0,9,0},
        {6,0,2, 0,0,0, 5,0,0},

        {0,7,0, 0,6,0, 0,0,0},
        {0,0,0, 9,0,1, 0,0,0},
        {0,0,0, 0,2,0, 0,4,0},

        {0,0,5, 0,0,0, 6,0,3},
        {0,9,0, 4,0,0, 0,7,0},
        {0,0,6, 0,0,0, 0,0,0}
    };*/

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
    sudoku_puzzle* s = new sudoku_puzzle(arr);
    bool asd = solveSudoku(s);
    if(asd == true){
        s->printPuzzle();
    }
    else std::cout<<"Nope"<<std::endl;//printSudoku(arr);
} 