/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
	struct ListNode *l2 = NULL;    
    struct ListNode **p1 = &head, **p2 = &l2;

    for (struct ListNode *node = head; node; node = node->next) {
        // if (node->val < x) {
        //     *p1 = node;
        //     p1 = &((*p1)->next);
        // } else {
        //     *p2 = node;
        //     p2 = &((*p2)->next);
        // }
        struct ListNode ***p = (node->val < x) ? &p1 : &p2;
        **p = node;
        *p = &((**p)->next);
    }

    *p1 = l2;
    *p2 = NULL;
    return head;
}
