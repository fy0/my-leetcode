#include <math.h>
#include <stdint.h>

double myPow(double x, int64_t n){
    if (n == 0) {
        return 1;
    }
    if (x == 1.0) {
        return 1.0;
    }
    if (n < 0) {
        // 强制正数，免去abs
        return 1.0 / myPow(x, -n);
    }
    double val = x;
    if (n < 128) {
        for (int64_t i = 1; i < n; i++) {
            val *= x;
        }
    } else {
        double ret = myPow(x, n / 2);
        return ret * ret * (n & 1 ? x : 1);
    }
    return val;
}
