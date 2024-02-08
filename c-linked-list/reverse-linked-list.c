/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reverseList2(struct ListNode **head) {
    if (!(*head) || !(*head)->next) {
        return;
    }

    struct ListNode *tail = (*head);
    *head = tail->next;
    reverseList2(head);

    struct ListNode *next = tail->next;
    next->next = tail;
    tail->next = NULL;
}

struct ListNode* reverseList(struct ListNode* head) {
    reverseList2(&head);
    return head;
}
