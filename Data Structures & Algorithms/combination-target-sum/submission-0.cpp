class Solution {
private:
void backtrack(vector<int>& nums, int target, vector<int>& path, vector<vector<int>>& result, int start) {
    if (target == 0) {
        result.push_back(path);
        return;
    }
    if (target < 0) return;

    for (int i = start; i < nums.size(); ++i) {
        path.push_back(nums[i]);
        backtrack(nums, target - nums[i], path, result, i);
        path.pop_back();
    }
}
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(nums, target, path, result, 0);
        return result;
    }
};
