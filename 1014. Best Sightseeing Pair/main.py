class Solution:
    def maxScoreSightseeingPair(self, A: List[int]) -> int:
        # 我是个傻子
        mx = 0
        best = 0
        for i in range(0, len(A)-1):
            mx = max(A[i] + i, mx)
            j = i + 1
            val = mx + A[j] - j
            if val > best:
                best = val
        return best

        # 优化了一些
        best = -len(A)-1
        best_i = -1
        a = A[0]
        for i in range(1, len(A)):
            val = A[i] + a - i
            if val >= best:
                best = val
                best_i = i

        best2 = best
        for j in range(1, best_i):
            val = best + j - a + A[j]
            best2 = max(val, best2)

        if best_i != len(A) -1:
            return max(best, best2, self.maxScoreSightseeingPair(A[best_i:]))
        return max(best, best2)

        # 暴力
        best = -len(A)-1
        for i in range(len(A)):
            for j in range(i+1, len(A)):
                val = A[i] + A[j] + i - j
                best = max(val, best)
        return best
