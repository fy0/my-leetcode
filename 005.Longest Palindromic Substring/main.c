
char* longestPalindrome(char* s) {
    int longest = 0;
    int longesti = 0;
    int len = strlen(s);

    for (int i = 0; i < len; ++i) {
        int start = i;
        int flag = 1; // 当 flag 为1时，持续读入文本；当为 0 时，进入匹配状态
        int count = 1;
        int odd_flag = 1;

        for (int j = i + 1; j < len; ++j) {
            if (flag) {
                if (s[j] == s[i+count-1]) {
                    flag = 0;
                } else {
                    if ((j > i+1) && s[j] == s[i+count-2]) {
                        flag = 0;
                        odd_flag = 2;
                    }
                }
            }

            if (s[j] == s[i+count-odd_flag]) {
                if (--count == (odd_flag-1)) {
                    // 完成回文
                    int newlen = j - start + 1;
                    if (newlen > longest) {
                        longest = newlen;
                        longesti = i;
                    }
                    // 重置回溯位置，防一手 aaaa 连续回文
                    count = 1;
                    flag = 1;
                }
            } else {
                if (!flag) {
                    // 不具备回文条件，再见
                    break; 
                } else count++;
            }
        }
    }

    char *p = s + longesti;
    p[longest] = '\0';
    return p;
}
