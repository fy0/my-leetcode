class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        pb = []

        for index in range(len(prices)):
            info = []
            for i in range(index + 1, len(prices)):
                val = prices[i] - prices[index]
                if val > 0:
                    info.append([i, val])
            pb.append(info)

        cache = {}
        def solve(index):
            if index >= len(prices):
                return 0
            if index in cache:
                return cache[index]
            vals = []
            for i in pb[index]:
                val = i[1] + solve(i[0] + 2)
                vals.append(val)
            vals.append(solve(index + 1))

            ret = max(vals or [0])
            cache[index] = ret
            return ret

        return solve(0)
