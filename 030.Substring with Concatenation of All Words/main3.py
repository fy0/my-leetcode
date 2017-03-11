
# 不知道是不是可行解，但内存爆了所以不能用

import itertools

class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if not words: return []
        word_len = len(words[0]) * len(words)
        if word_len > len(s): return []

        ret = []
        newwords = set(map(''.join, itertools.permutations(words)))

        for i in xrange(len(s)):
            txt = s[i:]
            if txt[:word_len] in newwords:
                ret.append(i)

        return ret
