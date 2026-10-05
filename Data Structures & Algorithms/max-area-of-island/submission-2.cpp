class Solution {
private:
    int rows;
    int cols;
    int dfs(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= rows ||
            col < 0 || col >= cols ||
            grid[row][col] == 0) {
            return 0;
        }
        // Mark as visited
        grid[row][col] = 0;
        int area = 1;
        area += dfs(grid, row - 1, col);
        area += dfs(grid, row + 1, col);
        area += dfs(grid, row, col - 1);
        area += dfs(grid, row, col + 1);
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int maxArea = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1) {
                    int area = dfs(grid, row, col);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};