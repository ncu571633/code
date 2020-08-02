 Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.



class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[k])
            return false;
        
        char c = board[i][j];
        board[i][j] = '#';
        
        if(k == word.size()-1)
            return true;
        if(dfs(board, word, i-1, j, k+1) || dfs(board, word, i, j-1, k+1) 
        || dfs(board, word, i+1, j, k+1) || dfs(board, word, i, j+1, k+1)) {
            return true;
        }
        
        board[i][j] = c;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==0 || board[0].size()==0 || word.size()==0)
            return false;
        
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};
