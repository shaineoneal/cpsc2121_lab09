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
    int lastRow = 0,
        lastCol = 0;
    vector<vector<bool>> board;
    int solutionCount = 0;

    //constructor
    Board(int s, int c) : SIZE(s), solutionCount(c){
        //create 8x8 board filled with 0
        board.assign(SIZE, vector<bool>(SIZE, false));
    }
    void insert(int r, int c) {
        board.at(r).at(c) = true;
        lastRow = r;
        lastCol = c;
    }
    bool checkAbove(int, int);

    void printBoard() {
        cout << endl << "  ";
        for (int c = 0; c < SIZE; c++) {
            cout << "  " << c << " ";
        }
        cout << endl;
        for (int r = 0; r < SIZE; r++) {
            printHorizontalLines();
            printBoardLines(r);
        }
        printHorizontalLines();
    }
    void printHorizontalLines();
    void printBoardLines(int);

    void moveRight() {
        board.at(lastRow).at(lastCol) = false;
        board.at(lastRow).at(lastCol + 1) = true;
    }

};


void Board::printHorizontalLines() {
    cout << "   ";
    for(int i = 0; i < SIZE; i ++) {
        cout << "--- ";
    }
    cout << endl;
}

void Board::printBoardLines(int row) {
    cout << row << " |";
    for(int c = 0; c < SIZE; c++) {
        if(board.at(row).at(c)) cout << " X |";
        else cout << "   |"; 
    }
    cout << endl;
}





bool Board::checkAbove(int r, int c) {

    bool notEmpty = false;

    //if in the top row
    if(r < 0 || c >= SIZE) return notEmpty;

    //if square is occupied
    if(board.at(r).at(c) == true) notEmpty = true;
    //otherwise
    else {
        //check upper left
        if(c > 0) {notEmpty = checkAbove(r - 1, c - 1);}
        //check upper right
        if(c < SIZE && !notEmpty) {notEmpty = checkAbove(r - 1, c + 1);}
        //check above
        if(!notEmpty) notEmpty = checkAbove(r - 1, c);
    }
    return notEmpty;
    
}

bool checkRow(Board &board, int row, int col) {
    
    //not at end of row
    if(col < board.SIZE) {
        //if something is above square, move to the right
        if(board.checkAbove(row, col)) checkRow(board, row, col + 1);
        else {
            board.insert(row, col);
            return true;
        }
    }
    else return false;
}


void checkByRow(Board board, int row, int col) {

    //at end of row
    if(!checkRow(board, row, col)) {
        cout << row << "end of row" << endl;
        return;
    }
    
    cout << "HERE";
    
    if(row < board.SIZE) {
        board.printBoard();
        Board newBoard = board;
        checkByRow(newBoard, row + 1, 0);
    }
board.printBoard();

    cout << "END\n";
    cout << "Last Row: " << board.lastRow << "\nLast Col: " << board.lastCol << endl;
    if(board.lastRow == 0) { 
        board.board.at(board.lastRow).at(board.lastCol) = false;
        //board.board.at(board.lastRow).at(board.lastCol + 1) = true;
       //board.moveRight();
        board.printBoard();
        cout << "HEREEEEEE" << endl;
        
        checkByRow(board, row, col + 1); 
    }
    return;
    
    
    
    
    
    
    
    /*//end of row 
    if(col >= boardRef->SIZE) {
        
        return;
    }
    
    //nothing above
    if(!boardRef->checkAbove(row, col)) {
        Board *newBoard = boardRef;
        newBoard->insert(row, col);
        cout << "NEW BOARD:\n";
        newBoard->printBoard();
        checkByRow(newBoard, row + 1, 0);
        cout << "RETURN:\n";
        boardRef->printBoard();
    }
    //if there is something above
    else checkByRow(boardRef, row, col + 1);
    
    if(row == boardRef->SIZE - 1 && col == boardRef->SIZE - 1) boardRef->solutionCount++;

    checkByRow(boardRef, 0, col + 1);
    
    
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
    else if(!(board.checkAbove(r, c))) {
        board.insert(r, c);
        //go to next row and restart at col 0
        checkByRow(board, r + 1, 0);
    }
    else {checkByRow(board, r, c + 1);}*/

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

    //cout << "1: " << nQueens(1) << endl;
    //cout << "2: " << nQueens(2) << endl;
    //cout << "3: " << nQueens(3) << endl;
    cout << "4: " << nQueens(4) << endl;
    //cout << "5: " << nQueens(5) << endl;
    //cout << "6: " << nQueens(6) << endl;
    //cout << "7: " << nQueens(7) << endl;
    //cout << "8: " << nQueens(8) << endl;
    //cout << "9: " << nQueens(9) << endl;
    //cout << "10: " << nQueens(10) << endl;
    //cout << "11: " << nQueens(11) << endl;
    //cout << "12: " << nQueens(12) << endl;
    return 0;
}