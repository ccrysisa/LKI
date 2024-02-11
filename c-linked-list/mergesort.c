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

static struct ListNode *mergesort_list(struct ListNode *head) {
    if (!head || !head->next) return head;

    struct ListNode *slow = head;
    for (struct ListNode *fast = head->next; fast && fast->next; fast = fast->next->next) {
        slow = slow->next;
    }
    struct ListNode *mid = slow->next;
    slow->next = NULL;

    struct ListNode *left = mergesort_list(head), *right = mergesort_list(mid);
    return mergeTwoLists(left, right);
}

void mergesort(struct ListNode **list) {
    *list = mergesort_list(*list);
}

void mergesort_iter(struct ListNode **list) {
    struct ListNode *head = *list;
    if (!head || !head->next) return;

    int top = 0;
    int listSize = 0;
    struct ListNode *stack[1000] = { NULL };
    struct ListNode *lists[100000] = { NULL };
    stack[top] = head;

    // divide to single one
    while (top >= 0) {
        struct ListNode *left = stack[top--];

        if (left) {
            struct ListNode *slow = left;
            struct ListNode *fast;

            for (fast = left->next; fast && fast->next; fast = fast->next->next) {
                slow = slow->next;
            }

            struct ListNode *right = slow->next;
            slow->next = NULL;

            stack[++top] = left;
            stack[++top] = right;
        } else {
            lists[listSize++] = stack[top--];
        }
    }

    // merge K sorted lists
    while (listSize > 1) {
        for (int i = 0, j = listSize - 1; i < j; i++, j--) {
            lists[i] = mergeTwoLists(lists[i], lists[j]);
        }
        listSize = (listSize + 1) / 2;
    }
    *list = lists[0];
}
