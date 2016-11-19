Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution. 

class Solution {
private:
    bool checkSudokuValid(const vector<vector<char>>& board, int m, int n) {
        for(int i=0; i<board.size(); i++) {
            if(i!=m && board[i][n] == board[m][n])
                return false;
            if(i!=n && board[m][i] == board[m][n])
                return false;
        }
        for(int i=3*(m/3); i<3*(m/3)+3; i++) {
            for(int j=3*(n/3); j<3*(n/3)+3; j++) {
                if(i!=m && j!=n && board[i][j] == board[m][n])
                    return false;
            }
        }
        return true;
        
    }
    bool solver(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j] == '.') {
                    for(int m=1; m<=9; m++) {
                        board[i][j] = m+'0';
                        if(checkSudokuValid(board, i, j) && solver(board))
                            return true;
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solver(board);
    }
};
