
// 6 ms
// 19.31%
// 感觉这种写不出差距

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *tmp[100];
    int i = 0;
    int count = 0;

    //if ((!head->next) && n == 1) return NULL;
    
    struct ListNode *p = head;
    while (p) {
        if (count % 5 == 0) tmp[i++] = p;
        count ++;
        p = p->next;
    }
    
    if (n == count) {
        return head->next;
    }

    int pos = count - n;
    int key = pos / 5;
    int rest = pos % 5;
    if (rest == 0) {
        p = tmp[key - 1];
        rest = 5;
    } else {
        p = tmp[key];        
    }
    
    for (int i=0;i<rest-1;++i) {
        p = p->next;
    }

    struct ListNode *ret = p->next;
    p->next = ret->next;
    return head;
}
