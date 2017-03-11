/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *buf = (int*)malloc(sizeof(int) * 2);
    
    int a = 0;
    int b = numsSize;

    int ret = -1;
    while (a < b) {
        int mid = (a + b) / 2;
        int val = nums[mid];
        if (target < val) {
            b = mid;
        } else if (target > val) {
            a = mid + 1;
        } else {
            ret = mid;
            break;
        }
    }

    *returnSize = 2;
    if (ret == -1) {
        buf[0] = -1;
        buf[1] = -1;
        return buf;
    }
    
    int i;
    for (i = ret - 1; ret > 0; --i) {
        if (nums[ret] != nums[i]) break;
    }
    ret = i + 1;
    if (ret == -1) ret = 0;

    i = ret;
    for (i = ret + 1; i < numsSize; ++i) {
        if (nums[ret] != nums[i]) break;
    }

    buf[0] = ret;
    buf[1] = i - 1;
    return buf;
}