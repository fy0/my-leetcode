#include <math.h>
#include <stdio.h>
#include <stdint.h>

double myPow(double x, int64_t n){
    if (n == 0) {
        return 1;
    }
    if (x == 1.0) {
        return 1.0;
    }
    double val = x;
    // if (n < 0) {
    //     // 强制正数，免去abs
    //     return 1.0 / myPow(x, -n);
    // }
    // int64_t an = n;
    int64_t an = labs(n); // 不除去abs都要超时，很神秘
    // int64_t an = n & 0x7fffffffffffffff;
    // int64_t an = (uint64_t)n << 1 >> 1;
    if (n < 4) {
        for (int64_t i = 1; i < an; i++) {
            val *= x;
        }
    } else {
        double ret = myPow(x, an / 2);
        val = ret * ret * (an & 1 ? x : 1);
    }
    if (n < 0) {
        val = 1.0 / val;
    }
    return val;
}

int main() {
    printf("%d", myPow(2.00000, -2147483648));
}
