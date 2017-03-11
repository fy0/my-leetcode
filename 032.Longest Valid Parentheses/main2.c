
// 206 ms 过了
// 这个解法本质上是把一个 n^2 问题，
// 分解成两个 O(n) 和一个代价小一些的 O(n^2)，或者应该是 O(n^3) ？
// 这个应该用动态规划的。
// 其实也是咸鱼解法

#include <string.h>

int longestValidParentheses(char* s) {
    int len = strlen(s);

    int *nums = (int*)malloc(sizeof(int) * len);
    int n = -1;

    struct {
        int start;
        int end;
    } data[30000];
    int ndata = -1;

    for (int i = 0; i < len; ++i) {
        if (s[i] == '(') {
            nums[++n] = i;
        } else if (s[i] == ')') {
            if (n != -1) {
                data[++ndata].start = nums[n--];
                data[ndata].end = i + 1;
            }
        }
    }
    
    for (int j = 0; j < ndata + 1; ++j) {
        if (data[j].start == -1) continue;
        
        while (true) {
            int exists = false;
            for (int i = 0; i < ndata + 1; ++i) {
                if (data[i].start == -1) continue;
                if (data[j].end == data[i].start) {
                    data[j].end = data[i].end;
                    data[i].start = -1;
                    exists = true;
                    break;
                }
            }
            if (!exists) break;
        }
    }

    int maxlen = 0;
    for (int i = 0; i < ndata + 1; ++i) {
        if (data[i].start != -1) {
            int newlen = data[i].end - data[i].start;
            if (newlen > maxlen) maxlen = newlen;
        }
    }

    return maxlen;
}
