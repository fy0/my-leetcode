// 时隔三年，最后偷懒的方式如出一辙

char * longestCommonPrefix(char ** strs, int strsSize){
    int index = 0;
    if (strsSize == 0) return "";
    if (strsSize == 1) return strs[0];
    while (true) {
        char ch = strs[0][index];
        for (int i = 1; i < strsSize; i++) {
            if (strs[i][index] != ch) goto _end;
        }
        if (ch == '\0') break;
        index ++;
    }
_end:
    strs[0][index] = '\0';
    return strs[0];
}
