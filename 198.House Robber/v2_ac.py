from typing import List
# 动态规划是弱项
# 解答还可以优化

class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        if len(nums) == 1:
            return nums[0]
        if len(nums) == 2:
            return max(nums[0], nums[1])

        best = [0] * len(nums)
        best[0] = nums[0]
        best[1] = nums[1]

        for i in range(2, len(nums)):
            not_choice = best[i-1]
            choice = max(best[:i-1]) + nums[i]
            best[i] = max(not_choice, choice)

        print(best)
        return max(best)
