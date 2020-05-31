class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        max_candies = max(candies)
        ret = []
        for val in candies:
            ret.append(val + extraCandies >= max_candies)
        return ret
