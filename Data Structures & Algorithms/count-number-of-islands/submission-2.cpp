class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int column) {
        int rows = grid.size();
        int columns = grid[0].size();
        if (row < 0 || row >= rows ||
            column < 0 || column >= columns ||
            grid[row][column] != '1') {
            return;
        }
        grid[row][column] = '0';
        dfs(grid, row - 1, column); // up
        dfs(grid, row + 1, column); // down
        dfs(grid, row, column - 1); // left
        dfs(grid, row, column + 1); // right
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int islandCount = 0;
        for (int row = 0; row < rows; ++row) {
            for (int column = 0; column < columns; ++column) {
                if (grid[row][column] == '1') {
                    ++islandCount;
                    dfs(grid, row, column);
                }
            }
        }
        return islandCount;
    }
};