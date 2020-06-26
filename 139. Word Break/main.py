# 应该算是深度优先搜索 + 结果记忆，不过我不太喜欢这个

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        index = 0
        jumpTable = {}
        for w in wordDict:
            p = jumpTable
            for c in w:
                p.setdefault(c, {})
                p = p[c]
            p['end'] = True

        p = jumpTable

        state = [None] * len(s)
        failed_record = {}

        i = 0
        stack = []
        while i < len(s):
            ch = s[i]
            failed = False

            if (i, id(p)) in failed_record:
                failed = True
            else:
                # 尝试前进
                if ch in p:
                    state[i] = p
                    p = p[ch]

                    # 匹配成功时，若可退出，打下标记
                    if 'end' in p:
                        stack.append(i + 1)
                        # print(stack)
                    elif i + 1 == len(s):
                        # 如果匹配成功，字符串被消耗完，但是pattern没有，算作失败
                        failed = True

                else:
                    failed = True

            if failed:
                failed_record[i, id(p)] = True
                if stack:
                    i2 = stack.pop()
                    for j in range(i2, i):
                        failed_record[j, id(state[j])] = True

                    i = i2
                    p = jumpTable
                    continue
                else:
                    break

            i += 1

        return i == len(s)
