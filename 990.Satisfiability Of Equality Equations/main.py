class Solution:
    def translateNum(self, num: int) -> int:
        if num < 10:
            return 1

        table = {}
        for i in range(26):
            table[str(i)] = chr(ord('a') + i)

        num_str = str(num)
        arr = []

        def solve(eated, s, last):
            if not s:
                arr.append(eated)
                return

            i = s[0]

            if last == '1' or (last == '2' and i in ('0', '1', '2', '3', '4', '5')):
                # if ord(eated[-1]) < ord('k'):
                solve(table[last + i], s[1:], last + i)

            solve(eated + table[i], s[1:], i)

        solve('', num_str, None)
        return len(arr)
