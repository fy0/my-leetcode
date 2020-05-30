from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        # 思路是排列所有可能，取最大值
        if len(nums) == 0:
            return 0

        limit = len(nums)
        # lst = [0]
        max_result = -1
        num = nums[0]

        def solve(start):
            nonlocal max_result, num
            fired = False
            for i in range(start + 2, limit):
                # lst.append(i)
                num += nums[i]
                solve(i)
                num -= nums[i]
                # lst.pop()
                fired = True

            if not fired:
                # ret = sum(map(lambda x: nums[x], lst))
                # print(num)
                max_result = max(max_result, num)

        solve(0)
        if len(nums) > 1:
            num = nums[1]
            solve(1)
        print(max_result)
        return max_result