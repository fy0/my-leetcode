
#include <stdlib.h>
#include <stdint.h>

int comp(const void *a,const void *b) {
    return (*(int*)a - *(int*)b);
}

// 一个现象：C/CPP 等速的时候，CPP排名更靠前，大概说明用C的dalao更多


int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), &comp);

    if (numsSize < 3) return 0;
    int minsum = INT_MAX;
    int minkey = INT_MAX;
    // 当target>0，且 sum < target 向右移动a有利于靠近目标
    // 若 target < 0，那么 sum < target 向右移动有利于靠近目标，sum > target 向左移动有利于靠近目标

    for (int i = 0; i < numsSize - 2; ++i) {
        int a = i + 1;
        int b = numsSize - 1;
        while (a < b) {
            int sum = nums[i] + nums[a] + nums[b];
            int key = abs(sum - target);
            if (key < minkey) {
                minkey = key;
                minsum = sum;
                if (sum < target) a++;
                else b--;
            } else if (sum < target) a++;
            else b--;
        }
    }

    return minsum;
}
