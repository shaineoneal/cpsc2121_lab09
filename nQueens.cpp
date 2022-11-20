/*
 * Name:
 * Date Submitted:
 * Lab Section:
 * Assignment Name:
 */

#include <iostream>
#include <vector>

using namespace std;

struct Board {
    
    int const SIZE;
    int currRow = 0,
        currCol = 0;
    vector<vector<bool>> board;
    int solutionCount = 0;

    //constructor
    Board(int s, int c) : SIZE(s), solutionCount(c){
        //create 8x8 board filled with 0
        board.assign(SIZE, vector<bool>(SIZE, false));
    }
    void insert(int r, int c) {board.at(r).at(c) = true;}
    bool checkAround(int, int);

};

bool Board::checkAround(int r, int c) {

    //if in the top row
    if(r == 0) return false;

    //if square is occupied
    if(board.at(r).at(c) = true) return true;
    //otherwise
    else {
        //check upper left
        if(c > 0) {checkAround(r - 1, c - 1);}
        //check upper right
        if(c < SIZE) {checkAround(r - 1, c + 1);}
        //check above
        checkAround(r - 1, c);
    }
    return false;
    
}


Board checkByRow(Board board, int r, int c) {

    //if you checked all rows; end 
    if(r >= board.SIZE) {
        Board newBoard(board.SIZE, board.solutionCount + 1);    
        return newBoard;
    }
    //if you reached end of row; go to next row
    if (c >= board.SIZE) {
        checkByRow(board, r + 1, c);
    }
    //if above is empty
    else if(!(board.checkAround(r, c))) {
        board.insert(r, c);
        //go to next row and restart at col 0
        checkByRow(board, r + 1, 0);
    }
    else {checkByRow(board, r, c + 1);}

}
//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess board
int nQueens(int n)
{
    //Implement int nQueens(int n)
    //Feel free to implement any recursive helper functions
    struct Board board(n, 0);
checkByRow(board, 0, 0);
    return board.solutionCount;
    

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