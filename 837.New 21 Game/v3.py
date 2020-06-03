# 人工稀疏矩阵加速
class MyDict(dict):
    def __getitem__(self, k):
        if k not in self:
            return 0.0
        else:
            return super().__getitem__(k)


class Solution:
    def new21Game(self, N: int, K: int, W: int) -> float:
        # dp[N+1:] = [0] * len(dp[N+1:])
        # dp[K:N+1] = [1] * len(dp[K:N+1])

        dp = MyDict()
        for i in range(K, N+1):
            dp[i] = 1

        s = 0
        for i in range(K, K+W):
            s += dp[i]
        # s = sum(dp[K:K+W])
        for i in range(K-1, -1, -1):
            dp[i] = s / W
            s += dp[i] - dp[i+W]

        return dp[0]
