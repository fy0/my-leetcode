# coding: utf-8
# 做了一个咸鱼解，脑子一团浆糊 回头再重新整理
# http://www.cnblogs.com/biyeymyhjob/archive/2012/10/04/2711527.html

class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(s) == 1:
            return s
        S = '$#' + '#'.join(s) + '#$'
        P = [1] * len(S)
        for i in xrange(1, len(S)-1):
            #print(S[i])
            P[i] = i+1
            for j in xrange(1, i+1):
                if S[i-j] != S[i+j]:
                    #print(S[i-j], S[i+j], i, j)
                    P[i] = j
                    break
                    
        #print(list(S))
        #print(map(str, P))
        P[0] = -1
        m = max(P)
        i = P.index(m)
        return ''.join(S[i-m+1:i+m].split('#')).replace('$', '')
