# 最开始的想法有严重问题，没往动态规划去
# 因为是双重动态规划，所以最后实现出来也失败了
# 后来按官方解法，先做了递归版，超时，又写了非递归版本
# 但发现对执行时间卡的很死，最后改了dp的数组长度才过，我想可能是LeetCode上malloc很慢吧


class Solution:
    def new21Game(self, N: int, K: int, W: int) -> float:
        dp = [None] * ((K + 1) * W)

        def solve3(x):
            if dp[x] is not None:
                return dp[x]
            # 若在边界
            if x > N:
                return 0
            if K <= x <= N:
                return 1
        
            dp[x] = sum([solve3(x+i) for i in range(1, W + 1)]) / W
            return dp[x]

        return solve3(0)
