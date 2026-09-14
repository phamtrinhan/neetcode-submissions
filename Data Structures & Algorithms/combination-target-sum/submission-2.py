class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        result = []
        tracking = []
        s = 0;
        def backtrack(i, s: int, tracking: List[int]):
            if s == target:
                result.append(tracking.copy())
                return
            if i >= len(nums) or s > target:
                return 
            tracking.append(nums[i])
            backtrack(i, s + nums[i], tracking)
            tracking.pop()
            backtrack(i + 1, s, tracking )   
        backtrack(0, 0, []) 
        return result;
