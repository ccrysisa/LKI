/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
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

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;    
    if (listsSize <= 1) return *lists;

    int m = listsSize >> 1;
    struct ListNode *left  = mergeKLists(lists, m);
    struct ListNode *right = mergeKLists(lists + m, listsSize - m);

    return mergeTwoLists(left, right);
}
