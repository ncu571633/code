/*  According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

    Any live cell with fewer than two live neighbors dies, as if caused by under-population.
    Any live cell with two or three live neighbors lives on to the next generation.
    Any live cell with more than three live neighbors dies, as if by over-population..
    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Write a function to compute the next state (after one update) of the board given its current state.
*/
#include <vector>
using namespace std;
class Solution {
public:
    int getNextValue(vector<vector<int>>& board, int m, int n) {
        int nums0=0, nums1=0;
        for(int i=max(m-1, 0); i<=min(m+1, (int)board.size()-1); i++) {
            for(int j=max(n-1, 0); j<=min(n+1, (int)board[0].size()-1); j++) {
                if((board[i][j]==0 || board[i][j]==2) && !(i==m && j==n))
                    nums0++;
                if((board[i][j]==1 || board[i][j]==3) && !(i==m && j==n))
                    nums1++;
            }
        }
        // states: 
        // 0->0: 0; 1->1: 1;
        // 0->1: 2; 1->0: 3;
        if(board[m][n] && nums1<2)
            return 3;
        if(board[m][n] && (nums1==2 || nums1==3))
            return 1;
        if(board[m][n] && nums1>3)
            return 3;
        if(!board[m][n] && nums1==3)
            return 2;
        return board[m][n];
    }
    void gameOfLife(vector<vector<int>>& board) {
        if(!board.size() || !board[0].size())
            return ;
        for(int i=0; i<board.size(); i++)
            for(int j=0; j<board[0].size(); j++)
                board[i][j] = getNextValue(board, i, j);
        for(int i=0; i<board.size(); i++)
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j]==2) board[i][j] = 1;
                if(board[i][j]==3) board[i][j] = 0;
            }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> b;
    vector<int> v(2, 1);
    b.push_back(v);
    v[1] = 0;
    b.push_back(v);
    s.gameOfLife(b);
    return 1;
}
