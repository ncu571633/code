Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3

class Solution {
public:
    void setGrid(vector<vector<char>>& grid, int m, int n) {
        if(m<0 || m>=grid.size() || n<0 || n>=grid[0].size() || grid[m][n]!='1')
            return ;
        grid[m][n] = '2';
        setGrid(grid, m-1, n);
        setGrid(grid, m, n-1);
        setGrid(grid, m+1, n);
        setGrid(grid, m, n+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    setGrid(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
