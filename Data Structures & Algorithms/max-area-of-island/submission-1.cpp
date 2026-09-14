#include <vector>
using namespace std;
class Solution
{
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int row, cols;
    int result = 0;

public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        row = grid.size();
        cols = grid[0].size();
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    result = max(result, dfs(grid, r, c));  
                }
            }
        }
        return result;
    }
    int dfs(vector<vector<int>> &grid, int r, int c)
    {
        if (r < 0 || c < 0 || r >= row || c >= cols || grid[r][c] == 0)
        {
            return 0;
        }
        grid[r][c] = 0;
        int area = 1;
        for (int dr = 0; dr < 4; dr++)
        {
            area += dfs(grid, r + directions[dr][0], c + directions[dr][1]);
        }
        return area;
    }
};