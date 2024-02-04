/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    struct ListNode **indirect = &head;
    for (struct ListNode *fast = head; fast && fast->next; fast = fast->next->next) {
        indirect = &((*indirect)->next);
    }
    struct ListNode *del = *indirect;
    *indirect = (*indirect)->next;
    free(del);
    return head;
}
