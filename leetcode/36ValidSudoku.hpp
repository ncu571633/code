Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated. 

class Solution {
public:
    bool isValidMatrix(vector<vector<char>>& board, int m, int n) {
        vector<bool> v(9, false);
        for(int i=m; i<m+3; i++) {
            for(int j=n; j<n+3; j++) {
                if(board[i][j] == '.')
                    continue;
                if(!v[board[i][j]-'1'])
                    v[board[i][j]-'1'] = true;
                else
                    return false;
            }
        }
        return true;
    }
    bool isValidColumn(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++) {
            vector<bool> v(9, false);
            for(int j=0; j<board.size(); j++) {
                if(board[i][j] == '.')
                    continue;
                if(!v[board[i][j]-'1'])
                    v[board[i][j]-'1'] = true;
                else
                    return false;
            }
        }
        return true;
    }
    bool isValidRow(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++) {
            vector<bool> v(9, false);
            for(int j=0; j<board.size(); j++) {
                if(board[j][i] == '.')
                    continue;
                if(!v[board[j][i]-'1'])
                    v[board[j][i]-'1'] = true;
                else
                    return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i=i+3)
            for(int j=0; j<board[0].size(); j=j+3)
                if(!isValidMatrix(board, i, j))
                    return false;
        return isValidColumn(board) && isValidRow(board);
    }
};
