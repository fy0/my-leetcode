
import itertools

table = {
    '2': 'abc',
    '3': 'def',
    '4': 'ghi',
    '5': 'jkl',
    '6': 'mno',
    '7': 'pqrs',
    '8': 'tuv',
    '9': 'wxyz',
}

def product(a, b):
    ret = []
    for i in a:
        for j in b:
            ret.append(i + j)
    return ret


class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if not digits:
            return []
        ret = []
        for i in digits:
            ret.append(table[i])

        last = ret[0]
        for i in ret[1:]:
            last = product(last, i)
        return list(last)
        
        # 尴尬：Exception: Type <type 'itertools.product'>: Not implemented
        #return itertools.product(ret)
        # 另外生成器函数（yield）也不能用，更加尴尬了

