class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);
        for (int n : nums) {
            ++count[n];
        }
        for (const auto& [num, frequency] : count) {
            freq[frequency].push_back(num);
        }
        vector<int> ans;
        ans.reserve(k);
        for (int i = static_cast<int>(freq.size()) - 1; i > 0; --i) {
            for (int n : freq[i]) {
                ans.push_back(n);

                if (ans.size() == k) {
                    return ans;
                }
            }
        }
        return ans;
    }
};