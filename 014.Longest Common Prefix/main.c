
#include <stdint.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int lens[500];
    int min = INT_MAX;
    int mini = 0;
    
    if (strsSize == 0) return "";
    for (int i = 0; i < strsSize; ++i) {
        int len = strlen(strs[i]);
        if (len < min) {
            min = len;
            mini = i;
        }
        lens[i] = len;
    }
    
    int i;
    for (i = 0; i < min; ) {
        int ch = strs[0][i];
        for (int j = 1; j < strsSize; ++j) {
            if (strs[j][i] != ch) goto _breakloop;
        }
        ++i;
        continue;
    _breakloop:
        break;
    }

    strs[0][i] = '\0';
    return strs[0];
}
