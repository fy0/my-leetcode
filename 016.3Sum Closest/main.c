
#include <stdlib.h>
#include <stdint.h>

int comp(const void *a,const void *b) {
    return (*(int*)a - *(int*)b);
}

// һ������C/CPP ���ٵ�ʱ��CPP��������ǰ�����˵����C��dalao����


int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), &comp);

    if (numsSize < 3) return 0;
    int minsum = INT_MAX;
    int minkey = INT_MAX;
    // ��target>0���� sum < target �����ƶ�a�����ڿ���Ŀ��
    // �� target < 0����ô sum < target �����ƶ������ڿ���Ŀ�꣬sum > target �����ƶ������ڿ���Ŀ��

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
