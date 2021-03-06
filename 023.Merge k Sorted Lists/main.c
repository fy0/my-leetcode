/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
// ��Ϊ Merge 2 Sorted Lists ����
// 239 ms
// 38.51%
 
 struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    struct ListNode *lst;
    
    if (l1->val < l2->val) {
        lst = l1;
        l1 = l1->next;
    } else {
        lst = l2;
        l2 = l2->next;
    }
    struct ListNode *head = lst;

    while (true) {
        if (!l1) {
            lst->next = l2;
            return head;
        }
        if (!l2) {
            lst->next = l1;
            return head;
        }

        if (l1->val < l2->val) {
            lst->next = l1;
            l1 = l1->next;
            lst = lst->next;
        } else {
            lst->next = l2;
            l2 = l2->next;
            lst = lst->next;
        }
    }
    
    return NULL;
}
 
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode *last = lists[0];
    for (int i = 1; i < listsSize; ++i) {
        last = mergeTwoLists(last, lists[i]);
    }
    return last;
}
