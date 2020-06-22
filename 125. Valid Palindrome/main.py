import re

class Solution:
    def isPalindrome(self, s: str) -> bool:
        ret = re.findall(r'[\da-zA-Z]+', s)
        final = ''.join(ret).lower()
        return final == final[::-1]
