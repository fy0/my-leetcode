class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        rules_eq = []

        def merge():
            do_next = True

            while do_next:
                do_next = False
                stop = False
                for _i, i in enumerate(rules_eq):
                    for _j, j in enumerate(rules_eq):
                        if _i == _j: continue
                        if i & j:
                            rules_eq[_i] = i | j
                            stop = True
                            do_next = True
                            del rules_eq[_j]
                            break
                    if stop:
                        break

        for i in equations:
            if i[1] == '=':
                a, b = i[0], i[3]
                added = False
                for i in rules_eq:
                    ca = a in i
                    cb = b in i

                    if (ca or cb) and (not (ca and cb)):
                        i.add(a)
                        i.add(b)
                        added = True
                        merge()

                if not added:
                    rules_eq.append({a, b})

        for i in equations:
            if i[1] == '!':
                a, b = i[0], i[3]
                if a == b:
                    return False
                for j in rules_eq:
                    if a in j and b in j:
                        return False

        return True
