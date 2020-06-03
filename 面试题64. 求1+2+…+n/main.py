class Solution:
    def sumNums(self, n: int) -> int:
        return (n == 1) or (n + self.sumNums(n-1))
