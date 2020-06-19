class Solution:
    def longestPalindrome(self, s: str) -> int:
        m = {}
        for i in s:
            m.setdefault(i, 0)
            m[i] += 1
        odd = False

        count = 0
        for k, v in m.items():
            count += v
            if v % 2 == 1:
                count -= 1
                odd = True

        return count + (1 if odd else 0)
