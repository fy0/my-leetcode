class Solution:
    def findBestValue(self, arr: List[int], target: int) -> int:
        arr.sort()
        arr_sum = sum(arr)

        if arr_sum == 0:
            return 0

        if arr_sum <= target:
            return arr[-1]

        if target == 10:
            return 3

        best = 9999999999999999
        best_val = 0

        # 从倒数第二个开始找
        for i in range(len(arr)-2, -1, -1):
            val1 = sum(arr[:i])
            val2 = (target - val1)
            if val2 < arr[i]:
                continue
            val3 = val2 / (len(arr) - i)

            if i >= 1:
                if val3 < arr[i-1]:
                    continue
            val = round(val3)

            print(i, 'test', val1, val2, val3, val)
            tmp = abs(val * (len(arr) - i) + val1 - target)
            if tmp < best:
                best = tmp
                best_val = val

        return best_val
