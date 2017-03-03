/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    // Output: 7 -> 0 -> 8
    // 465 + 342 = 807
    
    //[4,5,2,2,9,3,8,9,2]
    //[0,7,6,1,6,5,0,6,7]
    // 298392254 + 760561670 = 1058953924
    
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
}
