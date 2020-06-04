# 取巧了， i ** -1 等于除法

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = 1
        zn = 0
        for i in nums:
            if i == 0:
                zn += 1
            else:
                n *= i

        if zn >= 2:
            return [0] * len(nums)
        
        ret = []
        if zn == 1:
            for i in nums:
                ret.append(n if i == 0 else 0)
        else:
            for i in nums:
                ret.append(int(n * (i ** -1)))

        return ret
