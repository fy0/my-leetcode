class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        ret = [0] * len(T)
        match = []

        last = 0
        def match_insert(index, i):
            match.insert(0, [index, i])

        for index, i in enumerate(T):
            if match:
                # 如果上升，才进行比对
                if i > match[0][1]:
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
            # last = i

        return ret

