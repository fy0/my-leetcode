

int maxSubArray(int* nums, int numsSize){
    if (numsSize == 0) return 0;
    // 这个策略很简单：从前往后一直读数，只要小于0就重置，只要不小于0，那就是净赚

    int maxVal = 0;
    int val = 0;

    for (int i = 0; i < numsSize; i++) {
        val += nums[i];

        if (val > maxVal) maxVal = val;
        if (val < 0) val = 0;
    }

    // 全为负数，选一个最大的负数
    if (maxVal == 0) {
        maxVal = nums[0];
        for (int i = 1; i < numsSize; i++) {
            if (nums[i] > maxVal) {
                maxVal = nums[i];
            }
        }
    }

    return maxVal;
}
