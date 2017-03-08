
#include <math.h>

char* convert(char* s, int numRows) {
    if (numRows == 1) return s;
    int len = strlen(s);
    if  (len == 1) return s;
    char *buf = malloc(len+1);
    buf[len] = '\0';
    
    int n = 0;
    while (true) {
        int index = 0 + n * (2 * numRows - 2);
        if (index >= len) break;
        buf[n++] = s[index];
    }

    int zignum = n + 1;
    for (int r = 1; r < numRows - 1; ++r) {
        for (int c = 0; c < zignum; ++c) {
            int index = r + c * (2 * numRows - 2);
            if (index >= len) break;
            buf[n++] = s[index];

            int index2 = r + (c+1) * (2 * numRows - 2) - (r*2);
            if (index2 >= len) break;
            buf[n++] = s[index2];
        }
    }

    int i = 0;
    while (true) {
        int index = (numRows-1) + i * (2 * numRows - 2);
        if (index >= len) break;
        buf[n++] = s[index];
        i++;
    }

    //memcpy(s, buf, len);
    return buf;
}
