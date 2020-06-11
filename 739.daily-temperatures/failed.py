class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        # 多了一个没有卵用的排序
        ret = [0] * len(T)
        match = []

        last = 0
        def match_insert(index, i):
            match.append([index, i])
            match.sort(key=lambda x: x[1])

        for index, i in enumerate(T):
            if match:
                match_insert(index, i)
                # 如果上升，才进行比对
                if i > last:
                    # 比对match中的每一项，match是从小到大的，如果命中，则清除出去
                    count = 0
                    for index2, val in match:
                        if i > val:
                            ret[index2] = index - index2
                            count += 1
                        else:
                            # 因为match是顺序的，所以一旦不能命中，则立即清除
                            break
                    del match[:count]

            match_insert(index, i)
            last = i

        return ret

        # 暴力解法，超时
        for index, i in enumerate(T):
            find = False
            for index2, j in enumerate(T[index + 1:]):
                # print(index, index2, i, j)
                if j > i:
                    find = True
                    ret.append(index2 + 1)
                    break
            if not find:
                ret.append(0)
        return ret
