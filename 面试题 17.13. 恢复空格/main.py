
class Solution:
    def respace(self, dictionary: List[str], sentence: str) -> int:
        link = {}
        for i in dictionary:
            p = link
            for j in i:
                p.setdefault(j, {})
                p = p[j]
            p['is_end'] = True

        cache = {}

        def solve(index):
            if index in cache:
                return cache[index]

            rindex = index
            start = index
            count = 0
            best = len(sentence)
            p = link

            while index < len(sentence):
                i = sentence[index]

                if i in p:
                    p = p[i]
                    index += 1

                    if p != link:
                        if i in link:
                            # ["jsf","s"] "js"
                            ret = count + index - start + solve(index)
                            if ret < best:
                                best = ret

                    if 'is_end' in p:
                        if len(p) > 1:
                            # 这里会分出非贪婪分支
                            ret = count + solve(index)
                            if ret < best:
                                best = ret

                else:
                    if p == link:
                        # 如果没有走，那么字符强制推进
                        count += 1
                        index += 1
                        start = index
                    else:
                        if 'is_end' in p:
                            # 如果走不了但是是个句尾，那么重置start和p
                            start = index
                        else:
                            # 如果走不了又不是句尾，那么字符不变，重置p
                            count += index - start
                            start = index
                        p = link

            if 'is_end' not in p:
                count += index - start

            ret = min(count, best)
            cache[rindex] = ret
            return ret

        return solve(0)

