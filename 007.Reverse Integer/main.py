class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x < 0:
            r = -int(str(x)[:0:-1])
            if r < -2147483648:
                return 0
        else:
            r = int(str(x)[::-1])
            if r > 2147483647:
                return 0
        return r
