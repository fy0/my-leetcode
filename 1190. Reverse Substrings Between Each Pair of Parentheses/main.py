class Solution:
    def reverseParentheses(self, s: str) -> str:
        def solve(index, order=0):
            ret = []
            while index <= len(s) - 1:
                if s[index] == '(':
                    index, nret = solve(index + 1, order + 1)
                    ret.extend(nret)
                elif s[index] == ')':
                    break
                else:
                    ret.append(s[index])
                    index += 1
            
            # print(ret)
            if order >= 1:
                return index + 1, list(reversed(ret))
            else:
                return index + 1, ret

        index, ret = solve(0)
        # print(index, ret)
        return ''.join(ret)
