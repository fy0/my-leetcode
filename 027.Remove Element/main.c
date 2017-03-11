
int comp(void *a, void *b) {
    return *(int*)a - *(int*)b;
}

int removeElement(int* nums, int numsSize, int val) {
    qsort(nums, numsSize, sizeof(int), &comp);

    if (numsSize == 0) return 0;
    int last = val;
    for (int i = 0; i < numsSize; ++i) {
        if (last == nums[i]) {
            int j = i + 0; // ¹ÊÒâÈç´Ë
            while (j < numsSize && nums[j] == last) j++;
            memmove(nums + i, nums + j, (numsSize - j)*sizeof(int));
            numsSize -= j - i;
            break;
        }
    }
    return numsSize;
}
