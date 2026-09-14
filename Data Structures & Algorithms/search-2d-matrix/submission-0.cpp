class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> v;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                v.push_back(matrix[i][j]);
            }
        }

        int l = 0;
        int r = v.size() - 1;

        while (l <= r) {
            int m = l + ((r - l) / 2);
            if (v[m] < target)
                l = m + 1;     
            else if (v[m] > target)
                r = m - 1;    
            else
                return true;
        }
        return false;
    }
};
