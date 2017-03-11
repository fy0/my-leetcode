
// 这题出的不好
// 就算是遍历，也是 O(n) 了，没有比较合适的用例使得超时
// 等下试试不同的解法

int search(int* nums, int numsSize, int target) {
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == target) return i;
    }
    return -1;
}
