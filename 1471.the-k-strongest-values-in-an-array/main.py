class Solution:
    def getStrongest(self, arr: List[int], k: int) -> List[int]:
        arr = sorted(arr)
        m = arr[((len(arr) - 1) // 2) ]

        def get_val(k):
            if k >= m:
                return k-m, k
            else:
                return abs(k-m), k

        ret = sorted(arr, key=get_val)[len(arr)-k:]
        return ret

