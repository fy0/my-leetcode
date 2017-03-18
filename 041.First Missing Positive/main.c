
// 156 / 156 test cases passed.
// Status: Accepted
// Runtime: 6 ms
// 5.26%
// 办法不是特别好 不过能用

#define max(a,b) (((a)>(b)) ? (a):(b))
#define min(a,b) (((a)<(b)) ? (a):(b))

int firstMissingPositive(int* nums, int numsSize) {
    if (numsSize == 0) return 1;
    if (numsSize == 1) return (nums[0] == 1) ? 2 : 1;

    int buf[10000] = {0};

    for (int i = 0; i < numsSize; ++i) {
        int val = nums[i];
        if (val <= 0) continue;
        buf[val] = 1;
    }

    for (int i = 1; i < 1000; ++i) {
        if (!buf[i]) return i;
    }

    return 1;
}
