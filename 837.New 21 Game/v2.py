# 非递归版本

class Solution:
    def new21Game(self, N: int, K: int, W: int) -> float:
        dp = [0.0] * (K + W)
        for i in range(K, min(N+1, K+W)):
            dp[i] = 1.0
        # dp[K:N+1] = [1] * len(dp[K:N+1])

        s = sum(dp[K:K+W])
        for i in range(K-1, -1, -1):
            dp[i] = s / W
            s += dp[i] - dp[i+W]

        return dp[0]
