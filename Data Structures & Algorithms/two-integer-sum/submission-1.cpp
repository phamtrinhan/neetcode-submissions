class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> setIter;
        for (int i = 0; i < nums.size(); i++){
            setIter[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if (setIter.count(diff) && setIter[diff] != i){
                return {i, setIter[diff]};
            }
        }
        return {};
    }
};
