class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        m = []
        [m.extend(i) for i in matrix]
        m.sort()
        return m[k-1]

