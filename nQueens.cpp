/*
 * Name: Shaine O'Neal
 * Date Submitted: 11/27/2022
 * Lab Section: 04
 * Assignment Name: Using Recursion to Solve the N-Queens Problem
 */

#include <iostream>
#include <vector>

using namespace std;

struct Board {
    
    int const SIZE;
    int lastInsRow = 0,
        lastInsCol = 0;
    vector<vector<bool>> board;

    //constructor
    Board(int s) : SIZE(s) {
        //create 8x8 board filled with 0
        board.assign(SIZE, vector<bool>(SIZE, false));
    }
    void place(int r, int c) {
        board.at(r).at(c) = true;
        lastInsRow = r;
        lastInsCol = c;
    }
    bool checkSurrounding(int, int);

};

bool Board::checkSurrounding(int r, int c) {

    int currRow, 
        currCol;

    for(currRow = r, currCol = c; currRow >= 0 && currCol >= 0; currRow--, currCol--) {
        //if there is a queen in upper left, return true
        if(board.at(currRow).at(currCol) == true) return true;
    }

    //check upper right
    for(currRow = r, currCol = c; currRow >= 0 && currCol < SIZE; currRow--, currCol++) {
        //if there is a queen in upper right, return true
        if(board.at(currRow).at(currCol) == true) return true;
    }

    //check above
    for(currRow = r, currCol = c; currRow >= 0; currRow--) {
        if(board.at(currRow).at(currCol) == true) return true;
    }
    return false;
}

//global solution variable
int solCount;

void checkByRow(Board board, int row, int col) {
    
    //if at end of row AND last insert row was previous row
    if(col >= board.SIZE && board.lastInsRow == row - 1) return;
    
    //if all rows contain queens
    if(row >= board.SIZE) {
        solCount++;
        return;
    }

    //iterate thru row
    for(int c = 0; c < board.SIZE; c++){
        //if nothing above
        if(!board.checkSurrounding(row, c)) {
            Board newBoard = board;     //create a new board
            newBoard.place(row, c);    //place queen
            checkByRow(newBoard, row + 1, 0);   //go to beginning of next row
        }
    }
}


//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess board
int nQueens(int n)
{
    //Implement int nQueens(int n)
    //Feel free to implement any recursive helper functions
    solCount = 0;
    struct Board board(n);
    checkByRow(board, 0, 0);
    return solCount++;

}



int main()
{    

    cout << "1: " << nQueens(1) << endl;
    cout << "2: " << nQueens(2) << endl;
    cout << "3: " << nQueens(3) << endl;
    cout << "4: " << nQueens(4) << endl;
    cout << "5: " << nQueens(5) << endl;
    cout << "6: " << nQueens(6) << endl;
    cout << "7: " << nQueens(7) << endl;
    cout << "8: " << nQueens(8) << endl;
    cout << "9: " << nQueens(9) << endl;
    cout << "10: " << nQueens(10) << endl;
    cout << "11: " << nQueens(11) << endl;
    cout << "12: " << nQueens(12) << endl;
    return 0;
}