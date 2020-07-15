class Solution:
    def numTrees(self, n: int) -> int:
        table = {0:1, 1:1, 2:2, 3:5}

        def calc(n):
            if n in table:
                return table[n]
            num = 0
            for i in range(1, n+1):
                left = i - 1
                right = n+1 - (i+1)

                num += table[left] * table[right]
            table[n] = num
            return num

        for i in range(4, n + 1):
            calc(i)

        return calc(n)
