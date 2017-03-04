
#define max(a,b) ((a)>(b)) ? (a):(b)

int inBuf(char *buf, int size, char c) {
    for (int i=0; i<size; ++i) {
        if (buf[i] == c) return i+1;
    }
    return false;
}

int lengthOfLongestSubstring(char* s) {
    if (*s == 0) return 0;
    char *src = s;
    int mnum = 1;
    int num = 1;
    char buf[100];
    buf[0] = *s++;
    
    char c;

    while (c = *s++) {
        int r = inBuf(buf, num, c);
        if (r) {
            mnum = max(num, mnum);
            if (num != r) {
                memmove(buf, buf + r, num - r);
                num = num - r + 1;
            } else {
                num = 1;
            }
            buf[num-1] = c;
        } else {
            buf[num++] = c;
        }
    }
    
    return max(num, mnum);
}