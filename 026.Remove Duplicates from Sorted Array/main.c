
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 1) return numsSize;
    int last = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        if (last == nums[i]) {
            int j = i + 0; // ¹ÊÒâÈç´Ë
            while (j < numsSize && nums[j] == last) j++;
            memmove(nums + i, nums + j, (numsSize - j)*sizeof(int));
            numsSize -= j - i;
            i --;
        } else last = nums[i];
    }
    return numsSize;
}
