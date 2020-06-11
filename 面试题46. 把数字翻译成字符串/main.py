class Solution:
    def translateNum(self, num: int) -> int:
        if num < 10:
            return 1

        table = {}
        for i in range(26):
            table[str(i)] = chr(ord('a') + i)

        num_str = str(num)
        n = 0

        def solve(s, last):
            nonlocal n
            if not s:
                n += 1
                return

            i = s[0]

            if last == '1' or (last == '2' and i in ('0', '1', '2', '3', '4', '5')):
                solve(s[1:], last + i)

            solve(s[1:], i)

        solve(num_str, None)
        return n
