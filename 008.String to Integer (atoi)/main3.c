
#include <math.h>
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
        int len = end - start;
        if (len > 10) {
            // 长度超过 INT_MAX 绝对溢出
            return (positive) ? INT_MAX : INT_MIN;
        }
        int count = (len-1);
        //ret += *(end-1) - '0';
        p = start;
        int count1[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

        /*int rest = len & 0x3;
        int n = (len - rest) >> 2;

        while (n--) {
            ret += (p[0] - '0') * count1[count];
            ret += (p[1] - '0') * count1[count-1];
            ret += (p[2] - '0') * count1[count-2];
            ret += (p[3] - '0') * count1[count-3];
            p += 4;
            count -= 4;
            if (ret < 0) {
                return (positive) ? INT_MAX : INT_MIN;
            }
        }

        while (rest--) {
            ret += ((*p++) - '0') * count1[count--];
            if (ret < 0) {
                return (positive) ? INT_MAX : INT_MIN;
            }
        }*/
        
        while (p != end) {
            ret += ((*p++) - '0') * count1[count];
            if (ret < 0) {
                return (positive) ? INT_MAX : INT_MIN;
            }
            count--;
        }
        
        return (positive) ? ret : -ret;
    }
_invalid:
    return 0;
}
