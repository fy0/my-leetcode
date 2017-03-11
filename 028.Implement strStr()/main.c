
int strStr(char* haystack, char* needle) {
    int len1 = strlen(haystack);
    int len2 = strlen(needle);
    if (len2 == 0) return 0;
    if (len2 > len1) return -1;

    for (int i = 0; i < len1 - len2 + 1;) {
        int firstmatch = 0;
        for (int j = 0; j < len2; ++j) {
            if ((!firstmatch) && j > 0 && (haystack[i + j] == needle[0])) {
                firstmatch = i + j;
            }

            if (haystack[i + j] != needle[j]) {
                if (firstmatch) i = firstmatch;
                else i += j + 1;
                goto _next;
            }
        }
        return i;
    _next:;
    }
    return -1;
}
