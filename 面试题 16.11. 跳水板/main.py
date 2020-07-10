class Solution:
    def divingBoard(self, shorter: int, longer: int, k: int) -> List[int]:
        if k == 0:
            return []

        n = shorter * k
        ret = [n]
        offset = longer - shorter
        if offset == 0:
            return ret

        for i in range(k):
            n += offset
            ret.append(n)

        return ret
