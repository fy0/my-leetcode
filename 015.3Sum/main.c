
// 算法应该是对的，但是超时了

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int **buf = malloc(sizeof(int**) * 3000);
    int n = 0;
    __int128 tmp_lst[4000];
    int tmpn = 0;
    
    for (int i = 0; i < numsSize; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            int rest = - (nums[i] + nums[j]);
            for (int k = j + 1; k < numsSize; ++k) {
                if (rest == nums[k]) {
                    buf[n] = (int*)malloc(sizeof(int) * 3);
                    buf[n][0] = nums[i];
                    buf[n][1] = nums[j];
                    buf[n][2] = rest; 
                    if (buf[n][1] < buf[n][0]) {
                        buf[n][0] = nums[j];
                        buf[n][1] = nums[i];
                    }
                    if (buf[n][2] < buf[n][0]) {
                        buf[n][2] = buf[n][0];
                        buf[n][0] = rest;
                    }
                    if (buf[n][2] < buf[n][1]) {
                        int tmp = buf[n][2];
                        buf[n][2] = buf[n][1];
                        buf[n][1] = tmp;
                    }

                    int exist = 0;
                    __int128 key = (buf[n][0] << 8) | (buf[n][1] << 4) | buf[n][2];
                    for (int a = 0; a < tmpn; ++a) {
                        if (tmp_lst[a] == key) {
                            exist = 1;
                            break;
                        }
                    }
                    if (exist) continue;
                    tmp_lst[tmpn++] = key;
                    n++;
                }
            }
        }
    }

    *returnSize = n;
    return buf;
}
