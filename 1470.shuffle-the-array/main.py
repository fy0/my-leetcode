class Solution(object):
    def shuffle(self, nums, n):
        """
        :type nums: List[int]
        :type n: int
        :rtype: List[int]
        """
        ret = []
        for x, y in zip(nums[:n], nums[n:]):
            ret.append(x)
            ret.append(y)
        return ret

