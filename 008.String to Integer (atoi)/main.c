
#include <stdint.h>

int myAtoi(char* str) {
    char *p = str;
    int state = 0;
    char *start, *end;
    int positive = 1;

    for (;;) {
        switch (*p++) {
            case ' ':
                if (state) {
                    if (state == 1) return 0; // invalid
                    if (state == 2) {
                        end = p-1;
                        goto _end;
                    }
                }
                break;
            case '-':
                if (state) return 0; // 重复符号
                state = 1;
                positive = 0;
                break;
            case '+':
                if (state) return 0; // 重复符号
                state = 1;
                break;
            case '\0':
                if (state != 2) goto _invalid;
                else {
                    end = p-1;
                    goto _end;
                }
            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                if (state <= 1) {
                    state = 2;
                    start = p - 1;
                }
                break;
            default:
                if (state == 2) {
                    end = p-1;
                    goto _end;
                }
                goto _invalid;
        }
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
