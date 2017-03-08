
#include <stdint.h>
#define lex_isnumber(c) (c >= '0' && c <= '9')

int myAtoi(char* str) {
    char *p = str;
    char *start, *end;
    int positive = 1;
    
    while (*p == ' ') p++;
    if (*p == '-') {
        positive = 0;
        p++;
    } else if (*p == '+') p++;

    start = p;
    int flag = 0;
    for (;;) {
        char c = *p++;
        if (!lex_isnumber(c)) {
            if (!flag) goto _invalid;
            end = p-1;
            goto _end;
        } else {
            flag = 1;
        }

        /*switch (*p++) {
            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                if (!flag) flag = 1;
                break;
            default:
                if (!flag) goto _invalid;
                end = p-1;
                goto _end;
        }*/
    }

_end: {
        int ret = 0;
        int count = 10;
        int len = end - start;
        if (len > 10) {
            // 长度超过 INT_MAX 绝对溢出
            return (positive) ? INT_MAX : INT_MIN;
        }
        ret += *(end-1) - '0';
        p = end-2;
        while (p != start-1) {
            ret += ((*p--) - '0') * count;
            if (ret < 0) {
                return (positive) ? INT_MAX : INT_MIN;
            }
            count *= 10;
        }
        return (positive) ? ret : -ret;
    }
_invalid:
    return 0;
}
