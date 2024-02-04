/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeTwoLists(struct ListNode *L1, struct ListNode *L2) {
    struct ListNode *head, **ptr, **node;
    ptr = &head;

    for (; list1 && list2; ptr = &((*ptr)->next)) {
        node = (list1->val < list2->val) ? &list1 : &list2;
        *ptr = *node;
        *node = (*node)->next;
    }
    *ptr = (struct ListNode *)((uintptr_t) list1 | (uintptr_t) list2);

    return head;
}
