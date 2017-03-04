// 2080 / 2080
// 39ms 59.03%

#include <stdint.h>
#define max(a,b) (((a)>(b)) ? (a):(b))
#define min(a,b) (((a)<(b)) ? (a):(b))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int all = nums1Size + nums2Size;
    int two = (all % 2 == 0);
    int index = (int)(two ? all / 2 : (all+1) / 2) - 1;
    int cur = 0;
    int last = 0;
    
    int *p1 = nums1;
    int *p2 = nums2;
    int *p1_end = p1 + nums1Size;
    int *p2_end = p2 + nums2Size;
    
    int n1 = *p1++;
    int n2 = *p2++;

    while (cur <= index) {
        cur++;
        if (n1 <= n2) {
            last = n1;
            if (p1 == p1_end) {
                n1 = INT_MAX; // n1 已经没有内容，不再参与
                continue;
                //if (cur == index) break;  // 优化：如果当前值是要的那个值，那么直接停止
                //last = p1[]; // 否则，要的那个值必然在另一个数组中，算出位置并结束
                //n2 = p2[index - cur - 0];
                //break;
                // 优化没搞定，弄出好多BUG，丢人
            }
            n1 = *p1++;
        } else {
            last = n2;
            if (p2 == p2_end) {
                n2 = INT_MAX;
                continue;
            }
            n2 = *p2++;
        }
    }
    
    return two ? (last + min(n1, n2)) / 2.0 : last;
}
