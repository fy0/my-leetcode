# 官方解法

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        L = []

        val = 1
        for i in nums:
            L.append(val)
            val *= i

        ret = []
        val = 1
        lindex = len(L) - 1
        for i in reversed(nums):
            ret.append(val * L[lindex])
            val *= i
            lindex -= 1

        return ret[::-1]
