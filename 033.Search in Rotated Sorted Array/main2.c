
// 不知道是不是太水，运行时间都是一样的。。。

int search(int* nums, int numsSize, int target) {
    int pivot = -1;
    
    // 先找轴
    for (int i = 0; i < numsSize - 1; ++i) {
        if (nums[i] == target) return i;
        if (nums[i] > nums[i+1]) {
            pivot = i + 1;
            break;
        }
    }

    // 找到轴对剩下的二分，感觉 MDZZ
    if (pivot == -1) {
        return nums[numsSize - 1] == target ? numsSize - 1 : -1;
    } else {
        int right = numsSize;
        while (true) {
            int num = right - pivot;
            int mid = pivot + num / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (target > nums[mid]) {
                pivot = mid + 1;
            } else {
                right = mid;
            }
            if (num <= 1) return -1;
        }
    }
}
