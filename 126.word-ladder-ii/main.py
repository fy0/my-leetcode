class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        # 首先，获取一个字符对应wordList index的映射
        word_dict = {}
        wordListSet = set(wordList)
        if endWord not in wordListSet:
            return []

        for val in wordList:
            for index, j in enumerate(val):
                word_dict.setdefault(j, {})
                word_dict[j].setdefault(index, set())
                word_dict[j][index].add(val)

        convert_table = {}
        def build_table(start):
            convert = set()
            # 逐个试图替换每一个字符
            for index0, i in enumerate(start):
                # 把当前字符抽掉，求剩下字符可以拼出的词
                ret = wordListSet

                for index, j in enumerate(start):
                    if index == index0:
                        continue

                    # 如果留下的字符中的某个不在字典中，那么这一组数据必然都无法继续了
                    if j not in word_dict:
                        ret = set()
                        break
                    if index not in word_dict[j]:
                        ret = set()
                        break

                    # 留下可能的转换
                    ret = ret & word_dict[j][index]

                convert |= ret

            if start in convert:
                convert.remove(start)
            return convert

        for i in wordList:
            convert_table[i] = build_table(i)

        convert_table[beginWord] = build_table(beginWord)

        # 优化：如果输入字符串有两个以上不在字典中的字符，那么直接返回空值
        unknown = 0
        # for i in start:
        #     pass

        best = []
        best_len = len(wordList)

        cache = {}

        # 从输入开始穷举，试图换掉其中每一个字
        def solve(path, start, limit):
            nonlocal best, best_len
            # path = path[:]
            # print('solve', path, start)
            # 中止条件：匹配上结果
            if start == endWord:
                # print(path)
                return path

            if len(path) > limit:
                return

            # 如果长度超出最佳纪录，那么没有必要计算
            if len(path) >= best_len:
                return

            next_round = convert_table[start] - set(path)

            for j in next_round:
                path2 = path[:]
                path2.append(j)
                r = solve(path2, j, limit)
                if r:
                    if len(r) < best_len:
                        best = [r]
                        best_len = len(r)
                    elif best_len == len(r):
                        if r not in best:
                            best.append(r)

        for i in range(1, len(wordList) + 1):
            print(i)
            solve([beginWord], beginWord, i)
            if best:
                break

        return best
