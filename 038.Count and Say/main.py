
# 1, 11, 21, 1211, 111221, ...
# 玛德，原来是有 three 的。。


def solve(last):
    ret = []

    while last:
        i = last[0]
        count = 1
        while count < len(last) and i == last[count]:
            count += 1
            
        ret.extend([count, i])
        last = last[count:]

    return ret



class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        last = [1]
        for i in range(n-1):
            last = solve(last)
        return ''.join(map(str, last))
