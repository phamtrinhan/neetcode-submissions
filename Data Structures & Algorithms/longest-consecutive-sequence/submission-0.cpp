class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        int longest = 0;
        for (int num : numsSet) {
            if (!numsSet.contains(num - 1)) {
                int current = num;
                int length = 1;
                while (numsSet.contains(current + 1)) {
                    ++current;
                    ++length;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};