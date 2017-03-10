/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 // 3ms
 // 55 �� testcase �о�ûʲô��˵��
 
struct ListNode* swapPairs(struct ListNode* head) {
    if (!head) return NULL;
    if (!head->next) return head;
    
    ListNode *first = head;
    ListNode *second = head->next;
    ListNode *last = NULL;
    head = second;

    while (true) {
        first->next = second->next;
        second->next = first;
        if (last) last->next = second;

        last = first;
        first = first->next;
        if (!first) break;
        second = first->next;
        if (!second) break;
    }
    
    return head;
}
