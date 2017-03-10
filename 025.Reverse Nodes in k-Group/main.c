/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 // 6 ms
 // 81 / 81
 
struct ListNode* reverse(struct ListNode *head, int num, struct ListNode **plast) {
    if (!head) return NULL;

    int n = 1;
    struct ListNode *prev = head;
    struct ListNode *cur = head->next;
    struct ListNode *src_head = head;
    struct ListNode *tmp;

    while (true) {
        tmp = cur->next;
        cur->next = prev;
        prev = cur;
        if (!tmp) break;
        if (++n == num) break;
        cur = tmp;
    }

    src_head->next = tmp;
    *plast = src_head;
    return cur;
}

int listLen(struct ListNode *head) {
    int i = 0;
    while (head) {
        i++;
        head = head->next;
    }
    return i;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (!head) return NULL;
    if (!head->next) return head;
    if (k == 1) return head;

    int len = listLen(head);
    int num = len / k;
    if (!num) return head;

    struct ListNode *last = NULL;
    struct ListNode *first = head = reverse(head, k, &last);

    for (int i = 1; i < num; ++i) {
        struct ListNode *last_bak = last;
        head = reverse(last->next, k, &last);
        last_bak->next = head;
    }

    return first;
}

