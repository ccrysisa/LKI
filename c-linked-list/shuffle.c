#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _node_t {
    int val;
    struct _node_t *next;
} node_t;

void shuffle(node_t **head)
{
    srand(time(NULL));

    // First, we have to know how long is the linked list
    int len = 0;
    node_t **indirect = head;
    while (*indirect) {
        len++;
        indirect = &(*indirect)->next;
    }

    // Append shuffling result to another linked list
    node_t *new = NULL;
    node_t **new_tail = &new;

    while (len) {
        int random = rand() % len;
        indirect = head;

        while (random--)
            indirect = &(*indirect)->next;

        node_t *tmp = *indirect;
        *indirect = (*indirect)->next;
        tmp->next = NULL;

        *new_tail = tmp;
        new_tail = &(*new_tail)->next;

        len--;
    }

    *head = new;
}

void list_print(node_t *head)
{
    for (node_t *p = head; p; p = p->next) {
        printf(" | %d", p->val);
    }
    printf(" |\n");
}

int main()
{
    node_t *prev = NULL, *head;
    for (int i = 0; i < 10; i++) {
        node_t *curr = (node_t *) malloc(sizeof(node_t));
        curr->val = i + 1;
        curr->next = prev;
        prev = curr;
    }

    head = prev;
    shuffle(&head);
    list_print(head);

    for (node_t *curr = head; curr != NULL;) {
        node_t *next = curr->next;
        free(curr);
        curr = next;
    }

    return 0;
}
