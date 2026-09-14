class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> tracking;
        backtrack(0, 0, nums, tracking, target, result);
        return result;
    }
    void backtrack(int i, int sum, vector<int>& nums, vector<int>& tracking, int target,vector<vector<int>>& result){
        if (sum == target){

            result.push_back(tracking);
            return;
        }
        if (i >= nums.size() || sum > target)
            return;
        tracking.push_back(nums[i]);
        backtrack(i, sum + nums[i], nums, tracking, target, result);
        
        tracking.pop_back();
        backtrack(i + 1, sum, nums, tracking, target, result);
    }
};
