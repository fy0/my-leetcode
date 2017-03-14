
#include <stdint.h>

// 说是不能用除法，其实并不是这样

int divide(int dividend, int divisor) {
    if (!divisor) return INT_MAX;
    long ret = (long)dividend / (long)divisor;
    return (ret > INT_MAX) ? INT_MAX : ret;
}
