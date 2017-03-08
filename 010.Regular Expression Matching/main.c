
// 咸鱼极了
// 最好成绩 59ms
// 3.14%

bool match(char ch, char re) {
    if (re == '.') return ch;
    return (ch == re);
}

bool isMatch(char* s, char* p) {
    int state = 0;
    char ch, re;
    struct {
        char *s;
        char *p;
    } backtrack[100];
    int bti = 0;

    // 重排一下顺序，方便使用    
    char *p1 = p;
    while (*p1) {
        if (*p1 == '*') {
            *p1 = *(p1 - 1);
            *(p1 - 1) = '*';
        }
        p1++;
    }

    // 主循环
    while (1) {
        if (!state) {
            re = *p;
            if (re == '*') {
                state = 1;
                re = *(p+1);
                p+=2;
                continue;
            }

            ch = *s;
            if (ch == 0 && re == 0) return 1;

            if (match(ch, re)) p++;
            else {
                if (bti) {
                    s = backtrack[--bti].s;
                    p = backtrack[bti].p;
                    continue;
                }
                return 0;
            }
            s++;
        } else {
            backtrack[bti].s = s;
            backtrack[bti++].p = p;
            while (*s && match(*s, re)) {
                s++;
                backtrack[bti].s = s;
                backtrack[bti++].p = p;
            }
            state = 0;
        }
    }
}
