# Sudoku Checker
##### Modified from https://www.geeksforgeeks.org/check-if-given-sudoku-board-configuration-is-valid-or-not/
Given a sudoku starter board (an unsigned char 9*9 array), empty spots are marked with a 0xFF (255 decimal).
You don't need to check if the board is solvable, or valid. Only check if there are invalid entries already **exist** or not.

Example:
- Input:
        {{5,3,255,255,7,255,255,255,255},
        {6,255,255,1,9,5,255,255,255},
        {255,9,8,255,255,255,255,6,255},
        {8,255,255,255,6,255,255,255,3},
        {4,255,255,8,255,3,255,255,1},
        {7,255,255,255,2,255,255,255,6},
        {255,6,255,255,255,255,2,8,255},
        {255,255,255,4,1,9,255,255,5},
        {255,255,255,255,8,255,255,7,9}}
- Output:
        Valid

Hint: Just like solving sudoku, implement three functions to check 3*3 matrices, rows, and columns.