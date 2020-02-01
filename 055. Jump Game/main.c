#include <stdbool.h>
#include <stdio.h>

bool canJump(int* nums, int numsSize){
    // 如果只有一个元素，或者0个，那么无意义
    if (numsSize <= 1) return true;
    // 从倒数第二个元素向左遍历，当找到0坑的时候，检查更早的元素能否越过坑洞
    for (int i = numsSize - 2; i >= 0; i--) {
        if (nums[i] == 0) {
            // 出坑的充要条件是该位置数字大于等于距离加一
            for (int j = i-1; j >= 0; j--) {
                // printf("CCCC %d %d %d\n", i, j, nums[j]);
                if (nums[j] >= i - j + 1) {
                    goto _next;
                }
            }
            return false;
            _next:;
        }
    }
    return true;
}

int main() {
    int a[] = {2,0,0};
    printf("aaa %d\n", canJump(&a, 3));
}
