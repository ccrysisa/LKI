/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
static inline struct ListNode *move(struct ListNode *cur) { return cur ? cur->next : NULL; }

bool hasCycle(struct ListNode *head) {
	struct ListNode *tortoise = move(head);
	struct ListNode *hare = move(move(head));

    while (tortoise && hare && (tortoise != hare)) {
        tortoise = move(tortoise);
        hare = move(move(hare));
    }

    if (!hare) {
        return false;
    }

    return true;
}
