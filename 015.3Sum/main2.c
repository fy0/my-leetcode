
// √„«øπ˝œﬂ

#include <stdlib.h>

int comp(const void *a,const void *b) {
    return (*(int*)a - *(int*)b);
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int **buf = malloc(sizeof(int**) * 30000);
    int n = 0;
    __int128 tmp_lst[30000];
    int tmpn = 0;

    qsort(nums, numsSize, sizeof(int), &comp);

    for (int i = 0; i < numsSize - 2; ++i) {
        int target = -nums[i];
        
        int a = i + 1;
        int b = numsSize - 1;
        while (a < b) {
            int sum = nums[a] + nums[b];
            if (target == sum) {
                int exist = 0;
                __int128 _1 = nums[a];
                __int128 _2 = nums[b];
                __int128 key = (_1 << 64) | (_2 << 32) | nums[b];
                for (int x = 0; x < tmpn; ++x) {
                    if (tmp_lst[x] == key) {
                        exist = 1;
                        break;
                    }
                }
                if (exist) {
                    a++;b--;
                    continue;
                }
                tmp_lst[tmpn++] = key;
                buf[n] = (int*)malloc(sizeof(int) * 3);
                buf[n][0] = nums[i];
                buf[n][1] = nums[a];
                buf[n++][2] = nums[b];
                a++;
                b--;
            } else if (sum < target) a++;
            else b--;
        }
    }

    *returnSize = n;
    return buf;
}
