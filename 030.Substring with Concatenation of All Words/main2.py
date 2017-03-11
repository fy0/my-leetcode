
# coding: utf-8

# 超时咸鱼解的更换语言，稍微优化版本，仍然超时。


class Solution(object):
    def loopMatch(self, s, words, len2):
        if len2 * len(words) > len(s):
            return 0

        my_words = words[:]
        for i in words:
            found = 0
            sub = s[:len2]
            for j in my_words:
                if sub == j:
                    s = s[len2:]
                    my_words.remove(j)
                    found = 1
                    break
            if not found:
                return 0
        
        return 1

    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if not words:
            return []
        len2 = len(words[0])
        if len2 * len(words) > len(s):
            return []

        ret = []
        for i in xrange(len(s)):
            val = self.loopMatch(s[i:], words, len2)
            if val:
                ret.append(i)
        
        return ret
