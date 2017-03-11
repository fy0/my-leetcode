
int searchInsert(int* nums, int numsSize, int target) {
    int a = 0;
    int b = numsSize;

    int mid;
    int val;
    int ret = -1;
    while (a < b) {
        mid = (a + b) / 2;
        val = nums[mid];
        if (target < val) {
            b = mid;
        } else if (target > val) {
            a = mid + 1;
        } else {
            ret = mid;
            break;
        }
    }

    if (ret != -1) return ret;
    if (target > val) return mid+1;
    return mid;
}
