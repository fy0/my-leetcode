/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 int checklen(struct ListNode* l) {
     int i = 0;
     while (l) {
         i++;
         l = l->next;
     }
     return i;
 }
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    // Output: 7 -> 0 -> 8
    // 465 + 342 = 807
    
    //[4,5,2,2,9,3,8,9,2]
    //[0,7,6,1,6,5,0,6,7]
    // 298392254 + 760561670 = 1058953924
    
    // 优化了短整数，结果发现提升了 2%
    // 依旧咸鱼
    
    int len1 = checklen(l1);
    int len2 = checklen(l2);
    
    if (len1 >= 37 || len2 >= 37) {
        int carry = 0;
        struct ListNode *ret = malloc(sizeof(struct ListNode));
        struct ListNode *l3 = ret;
        int next = l1 || l2;
        
        while (next) {
            int r = ((l1) ? l1->val : 0) + ((l2) ? l2->val : 0);
            l3->val = r % 10 + carry;
            carry = r >= 10;
            if (l3->val == 10) {
                l3->val = 0;
                carry ++;
            }

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            next = l1 || l2;
            if (next) {
                l3->next = malloc(sizeof(struct ListNode));
                l3 = l3->next;
            }
        }

        if (carry) {
            l3->next = malloc(sizeof(struct ListNode));
            l3->next->next = NULL;
            l3->next->val = 1;
        } else l3->next = NULL;
        return ret;
    } else {
        __int128 n1 = l1->val;
        __int128 n2 = l2->val;
        
        // 这里在赌位数
        int i = 1;
        __int128 basenum[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000, 10000000000000, 100000000000000, 1000000000000000, 10000000000000000, 100000000000000000, 1000000000000000000, 10000000000000000000, 100000000000000000000, 1000000000000000000000, 10000000000000000000000, 100000000000000000000000, 1000000000000000000000000, 10000000000000000000000000, 100000000000000000000000000, 1000000000000000000000000000, 10000000000000000000000000000, 100000000000000000000000000000, 1000000000000000000000000000000, 10000000000000000000000000000000, 100000000000000000000000000000000, 1000000000000000000000000000000000, 10000000000000000000000000000000000, 100000000000000000000000000000000000, 1000000000000000000000000000000000000, 10000000000000000000000000000000000000, 100000000000000000000000000000000000000};

        struct ListNode* p1 = l1->next;
        while (p1) {
            n1 += p1->val * basenum[i++];
            p1 = p1->next;
        }

        i = 1;
        struct ListNode* p2 = l2->next;
        while (p2) {
            n2 += p2->val * basenum[i++];
            p2 = p2->next;
        }

        struct ListNode *p3 = l1;
        struct ListNode *l3 = l1->next;
        if (!l3) l3 = l2;

        __int128 ret = n1 + n2;
        
        if (ret == 0) {
            p3->val = 0;
            p3->next = NULL;
            return p3;
        }

        while (ret > 0) {
            int n = ret % 10;
            ret /= 10;

            // 这里就是在赌不会出现 99 + 1 的情况……
            if (!p3->next) {
                p3->next = l2;
                // 补丁：不用赌了，这次肯定够
                if (l2) l2 = NULL;
                else p3->next = l1;
            }
            p3 = p3->next;
            p3->val = n;
        }

        p3->next = NULL;
        return l3;
    }

}
