class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        if len(triangle) == 0:
            return 0

        if len(triangle) == 1:
            return triangle[0][0]

        index = len(triangle) - 1
        best = triangle[-1][:]

        while index > 0:
            old_len = len(best)

            for i in range(len(triangle[index-1])):
                best.append(triangle[index-1][i] + min(best[i], best[i + 1]))

            best[:old_len] = []
            index -= 1

        return best[0]
