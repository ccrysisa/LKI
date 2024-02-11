/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reverseList_recur(struct ListNode **head) {
    if (!(*head) || !(*head)->next) {
        return;
    }

    struct ListNode *tail = (*head);
    *head = tail->next;
    reverseList_recur(head);

    struct ListNode *next = tail->next;
    next->next = tail;
    tail->next = NULL;
}

void reverseList_iter(struct ListNode **head) {
    if (!(*head)) {
        return;
    }

    struct ListNode *prev = NULL;
    struct ListNode *curr = *head;
    struct ListNode *next = (*head)->next;

    while (curr != NULL) {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = next ? next->next : next;

        *head = prev;
    }
}

struct ListNode* reverseList(struct ListNode* head) {
    reverseList_iter(&head);
    return head;
}
