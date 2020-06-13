# 简单的动态规划

class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1
        if n == 2:
            return 2
        dp = [0] * n
        dp[-1] = 1
        dp[-2] = 2

        for i in range(n - 3, -1, -1):
            dp[i] = dp[i+1] + dp[i+2]
        
        return dp[0]

