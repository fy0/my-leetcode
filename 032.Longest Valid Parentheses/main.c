
// ³¬Ê±

int longestValidParentheses(char* s) {
    int len = strlen(s);
    int len2 = len;
    int num = 0;

    int start = 0;
    int maxlen = 0;

    for (int j = 0; j < len2; ++j) {
        for (int i = 0; i < len; ++i) {
            if (s[i] == '(') {
                num++;
            } else if (s[i] == ')') {
                if (num == 0) {
                    start = i + 1;
                } else {
                    if (--num == 0) {
                        int newlen = i - start + 1;
                        if (newlen > maxlen) maxlen = newlen;
                    }
                }
            }
        }

        s++;
        len--;
        start = 0;
        num = 0;
    }

    return maxlen;
}
