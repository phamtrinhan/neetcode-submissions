class Solution:
    def combinationSum2(self, nums: List[int], target: int) -> List[List[int]]:
        #Sort to findout the duplicate number 
        #
        result = []
        tracking = []
        s = 0;
        nums.sort();# 1, 2, 2, 4, 5, 6, 9
        def backtrack(i, s: int, tracking: List[int]):
            if s == target:
                result.append(tracking.copy())
                return
            if i >= len(nums) or s > target:
                return 
            for j in range(i, len(nums)):
                if j > i and nums[j] == nums[j - 1]:
                    continue 
                tracking.append(nums[j])
                backtrack(j + 1, s + nums[j], tracking)
                tracking.pop()
        backtrack(0, 0, []) 
        return result;
