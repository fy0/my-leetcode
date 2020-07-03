# 简单易懂的 lexer

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        brace_stack = []
        best = 0

        hits = {}
        for index, i in enumerate(s):
            if i == '(':
                brace_stack.append(index)
            elif i == ')':
                if len(brace_stack) == 0:
                    continue
                start_pos = brace_stack.pop()

                if start_pos in hits:
                    hits[index + 1] = hits[start_pos]
                else:
                    hits[index + 1] = start_pos

                best = max(best, index + 1 - hits[index + 1])

        return best
