
// 此思路无解，彻底失败

#define max(a,b) ((a)>(b)) ? (a):(b)

int work(char* s, int i, int len, int odd_flag) {
    int longest;
    int count = 1;
    int flag = 1; // 当 flag 为1时，持续读入文本；当为 0 时，进入匹配状态

    for (int j = i + 1; j < len; ++j) {
        if ((odd_flag == 1) ? (s[j] == s[i+count-1]) : ((j > i+1) && s[j] == s[i+count-2])) {
        //if (s[j] == s[i+count-1]) {
            flag = 0;
            if (--count == (odd_flag-1)) {
                // 完成回文
                int newlen = j - i + 1;
                if (newlen >= longest) {
                    longest = newlen;
                }
                // 重置回溯位置，防一手 aaaa 连续回文
                count = newlen;
                flag = 1;
            }
        } else {
            if (!flag) {
                // 不具备回文条件，再见
                break; 
            } else count++;
        }
    }
    
    return longest;
}

char* longestPalindrome(char* s) {
    int longest = 0;
    int longesti = 0;
    int len = strlen(s);
    if (len == 1) return s;

    for (int i = 0; i < len; ++i) {
        int a = work(s, i, len, 1);
        int b = work(s, i, len, 2);
        int newlen = max(a, b);
        // 这个不等于也可以，但看官方的例子，
        // 长度相同的情况下，他们比较喜欢用靠后的
        if (newlen > longest) {
            longest = newlen;
            longesti = i;
        }
    }

    char *p = s + longesti;
    p[longest ? longest : 1] = '\0';
    return p;
}
