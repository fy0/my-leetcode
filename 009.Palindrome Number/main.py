class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        s = str(x)
        n = len(s) // 2
        for i in xrange(n+1):
            if s[i] != s[-i-1]:
                return False
        return True
        