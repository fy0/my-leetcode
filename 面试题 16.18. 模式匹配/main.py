# 一开始两处 lb 写错成 la 竟然能过一半的测试

class Solution:
    def patternMatching(self, pattern: str, value: str) -> bool:
        if not pattern and not value:
            return True
        if not pattern and value:
            return False

        ca = pattern.count('a')
        cb = pattern.count('b')

        def solve(la, lb):
            index = 0
            a, b = None, None
            for i in pattern:
                if i == 'a':
                    tmp = value[index:index+la]
                    index += la
                    if a is None:
                        a = tmp
                    else:
                        if tmp != a:
                            return False
                elif i == 'b':
                    tmp = value[index:index+lb]
                    index += lb
                    if b is None:
                        b = tmp
                    else:
                        if tmp != b:
                            return False
            # print('?', la, lb, index, len(value), a, b, index == len(value) and a != b)
            return index == len(value) and a != b

        for la in range(len(value) + 1):
            for lb in range(len(value) + 1):
                if la * ca + lb * cb > len(value):
                    continue
                if solve(la, lb):
                    return True

        return False
