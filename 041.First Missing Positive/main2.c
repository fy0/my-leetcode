// 看了题解之后的优化版本

// 165 / 165 个通过测试用例
// 状态：通过
// 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
// 内存消耗：5.7 MB, 在所有 C 提交中击败了100.00%的用户

// 这题用set做是没错
// 但其实我忽略了一个线索，那就是哈希函数可以自己设计，多简单都行

int firstMissingPositive(int* nums, int numsSize){
    bool flag = false;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) flag = true;
        if (nums[i] <= 0) nums[i] = 1;
    }

    if (!flag) return 1;

    for (int i = 0; i < numsSize; i++) {
        int index = abs(nums[i]) - 1;
        if (index < numsSize) {
            nums[index] = -abs(nums[index]);
        }
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            return i + 1;
        }
    }
    return numsSize + 1;
}
