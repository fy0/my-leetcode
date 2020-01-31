#include <math.h>
#include <stdint.h>

double myPow(double x, int64_t n){
    if (n == 0) {
        return 1;
    }
    if (x == 1.0) {
        return 1.0;
    }
    double val = x;
    int64_t an = labs(n);
    if (n < 128) {
        for (int64_t i = 1; i < an; i++) {
            val *= x;
        }
    } else {
        double ret = myPow(x, an / 2);
        return ret * ret * (an % 2 ? x : 1);
    }
    if (n < 0) {
        val = 1.0 / val;
    }
    return val;
}
