#include <vector>
using namespace std;
class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int row, cols;
    int result = 0;
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        cols = grid[0].size();
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    dfs(grid, r, c);
                    result++;
                }
            }
        }
        return result;
    }
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0') {
            return;
        } 
        grid[r][c] = '0';
        for (int dr = 0; dr < 4; dr++) {
            dfs(grid, r + directions[dr][0], c + directions[dr][1]);
        }
    }
};
