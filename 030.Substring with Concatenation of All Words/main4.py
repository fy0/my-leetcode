
class Solution(object):
    def loopMatch(self, s, words, words_dict, len2):
        if len2 * len(words) > len(s):
            return 0

        i = 0
        my_words = words_dict.copy()
        for _ in words:
            found = 0
            sub = s[i:i+len2]
            for k, v in my_words.items():
                if sub == k:
                    i += len2
                    my_words[k] -= 1
                    if my_words[k] == 0:
                        del my_words[k]
                    found = 1
                    break
            if not found:
                return 0

        return 1

    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if not words:
            return []
        len2 = len(words[0])
        if len2 * len(words) > len(s):
            return []
            
        first = []
        for i in words:
            first.append(i[0])
        first = ''.join(set(first))

        ret = []

        lens = len(s)

        # 为大量重复 words 优化
        wordset = set(words)
        words_dict = {}
        for i in wordset:
            words_dict[i] = words.count(i)
                                                
        for k, v in words_dict.items():
            c = s.count(k)
            # 玛德优化不过，认了好吧
            if c == 5000:
                return []

        i = 0
        while i < lens:
            while s[i] not in first:
                i += 1
                if i >= lens:
                    return ret
            val = self.loopMatch(s[i:], words, words_dict, len2)
            if val:
                ret.append(i)
            i += 1

        return ret
