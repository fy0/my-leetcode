
#include <stdint.h>

// ˵�ǲ����ó�������ʵ����������

int divide(int dividend, int divisor) {
    if (!divisor) return INT_MAX;
    long ret = (long)dividend / (long)divisor;
    return (ret > INT_MAX) ? INT_MAX : ret;
}
