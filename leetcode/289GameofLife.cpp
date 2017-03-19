/*  According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

    Any live cell with fewer than two live neighbors dies, as if caused by under-population.
    Any live cell with two or three live neighbors lives on to the next generation.
    Any live cell with more than three live neighbors dies, as if by over-population..
    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Write a function to compute the next state (after one update) of the board given its current state.
*/

#include "main.hpp"

// Easy version: Build a new board, using extra space
// Time: O(m*n), Space: O(m*n)
class Solution {
public:
    int countNeighbor(vector<vector<int>>& board, int i, int j) {
        int count = 0;
        for(int a=max(i-1, 0); a<=min(i+1, (int)board.size()-1); a++) {
            for(int b=max(j-1, 0); b<=min(j+1, (int)board[0].size()-1); b++) {
                if(!(a==i && b==j))
                    count += board[a][b];
            }
        }
        return count;
    }
    int getNextValue(vector<vector<int>>& board, int i, int j) {
        int count = countNeighbor(board, i, j);
        if(board[i][j] && count<2) 
            return 0;
        if(board[i][j] && (count==2 || count==3)) 
            return 1;
        if(board[i][j] && count>3)
            return 0;
        if(!board[i][j] && count==3)
            return 1;
        return board[i][j];
    }
    void gameOfLife(vector<vector<int>>& board) {
        if(!board.size() || !board[0].size())
            return ;
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> nextBoard(m, vector<int>(n, 0));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                nextBoard[i][j] = getNextValue(board, i, j);
            }
        }
        board = nextBoard;
    }
};


// In place, use two bits to store (next state, current state)
class Solution {
public:
    int countNeighbor(vector<vector<int>>& board, int i, int j) {
        int count = 0;
        for(int a=max(i-1, 0); a<=min(i+1, (int)board.size()-1); a++) {
            for(int b=max(j-1, 0); b<=min(j+1, (int)board[0].size()-1); b++) {
                if((board[a][b]==1 || board[a][b]==3) && !(i==a && j==b))
                    count++;
            }
        }
        return count;
    }
    int getNextValue(vector<vector<int>>& board, int i, int j) {
        int count = countNeighbor(board, i, j);
        // states: 
        // 0->0: 0; 1->1: 1;
        // 0->1: 2; 1->0: 3;
        if(board[i][j] && count<2)
            return 3;
        if(board[i][j] && (count==2 || count==3))
            return 1;
        if(board[i][j] && count>3)
            return 3;
        if(!board[i][j] && count==3)
            return 2;
        return board[i][j];
    }
    void gameOfLife(vector<vector<int>>& board) {
        if(!board.size() || !board[0].size())
            return ;
        int m = board.size();
        int n = board[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                board[i][j] = getNextValue(board, i, j);
            }
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j]==2) board[i][j] = 1;
                if(board[i][j]==3) board[i][j] = 0;
            }
        }
    }
};

//Follow up: what if the board size is very large, say 100 million * 100 million? We have to store the board data on local disk.
// Idea: we do not store the whole board. We only store the live cells in a set and other cells are dead by default.
// We read in the board data line by line and compute the new cell state using 3 lines each time. Then throw away the top line and read in a new line.
// I/O API: int[] readLine(), void writeLine(int[] array)

class Solution {
public:
    int countNeighbor(vector<vector<int>>& board, int i, int j) {
        int count = 0;
        for(int a=max(i-1, 0); a<=min(i+1, (int)board.size()-1); a++) {
            for(int b=max(j-1, 0); b<=min(j+1, (int)board[0].size()-1); b++) {
                if((board[a][b]==1 || board[a][b]==3) && !(i==a && j==b))
                    count++;
            }
        }
        return count;
    }
    int getNextValue(vector<vector<int>>& board, int i, int j) {
        int count = countNeighbor(board, i, j);
        // states: 
        // 0->0: 0; 1->1: 1;
        // 0->1: 2; 1->0: 3;
        if(board[i][j] && count<2)
            return 3;
        if(board[i][j] && (count==2 || count==3))
            return 1;
        if(board[i][j] && count>3)
            return 3;
        if(!board[i][j] && count==3)
            return 2;
        return board[i][j];
    }
    // update the first row of temp matrx: row 0, 1, 2
    void updateBoard(vector<vector<int>>& temp) {
        for(int j=0; j<temp[0].size(); j++)
            temp[1][j] = getNextValue(board, 1, j);
        for(int j=0; j<n; j++) {
            if(temp[i][j]==2) temp[i][j] = 1;
            if(temp[i][j]==3) temp[i][j] = 0;
        }
        writeLine(temp);
    }
    void gameOfLife() {
        vector<vector<int>> temp(3, vector<int>(n,0));
        temp[2] = readLine();
        while(true){
            temp[0] = temp[1];
            temp[1] = temp[2];
            temp[2] = readLine();
            updateBoard(temp);
            if(temp[2].empty())
                break;
        }
    }
};

// Sparse Matrix Multiplcation
// doesn't store whole line, but the 1 element.
// 3 row matrix becomes
// vector with size 3, each element is a map
// m[i].count(j)
// m[i][j] == 1

 
int main()
{
    Solution s;
    vector<vector<int>> b;
    vector<int> v(1, 1);
    b.push_back(v);
    v[1] = 0;
    b.push_back(v);
    s.gameOfLife(b);
    return 1;
}


