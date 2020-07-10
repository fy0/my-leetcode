class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if len(obstacleGrid) == 0:
            return 0

        # 起点终点相同
        if len(obstacleGrid) == 1 and len(obstacleGrid[0]) == 1:
            if obstacleGrid[0][0]:
                return 0
            return 1

        # 起点不能走
        if obstacleGrid[0][0]:
            return 0

        # 终点不能走
        if obstacleGrid[len(obstacleGrid) - 1][len(obstacleGrid[0]) - 1]:
            return 0

        cache = {}
        def solve(pos) -> int:
            pos = tuple(pos)
            nonlocal cache
            if pos in cache:
                return cache[pos]

            ret = 0
            npos = (pos[0] + 1, pos[1])
            if npos[0] == len(obstacleGrid) - 1 and npos[1] == len(obstacleGrid[0]) - 1:
                return 1
            if npos[0] < len(obstacleGrid) and not obstacleGrid[npos[0]][npos[1]]:
                # 可以向下走
                ret += solve(npos)

            npos = (pos[0], pos[1] + 1)
            if npos[0] == len(obstacleGrid) - 1 and npos[1] == len(obstacleGrid[0]) - 1:
                return 1

            if npos[1] < len(obstacleGrid[0]) and not obstacleGrid[npos[0]][npos[1]]:
                # 可以向右走
                ret += solve(npos)

            cache[pos] = ret
            return ret

        return solve([0, 0])
