#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
    char name;
    struct Node *next;
} Node;

static inline Node *move(Node *cur) { return cur ? cur->next : NULL; }

bool cycle_finding(Node *HEAD, Node **TAIL, int *length, int *mu, int *lambda) {
    // lambda is length
    // mu is the most node's index
    // TAIL is the tail node of cycle
    Node *tortoise = move(HEAD);
    Node *hare = move(move(HEAD));

    // get meet point
    while (hare && tortoise && (hare != tortoise)) {
        tortoise = move(tortoise);
        hare = move(move(hare));
    }

    // not loop
    if (!hare) {
        *TAIL = NULL;
        *length = 0;
        tortoise = HEAD;
        while (tortoise && (tortoise = move(tortoise)))
            (*length)++;
        return false;
    }

    // get mu
    *mu = 0;
    tortoise = HEAD;
    while (tortoise != hare) {
        (*mu)++;
        tortoise = tortoise->next;
        hare = hare->next;
    }

    // get lambda
    *lambda = 1;
    tortoise = move(tortoise);
    *TAIL = tortoise;
    while (tortoise != hare) {
        (*lambda)++;
        *TAIL = tortoise;
        tortoise = move(tortoise);
    }
    *length = *mu + *lambda;
    return true;

}

int main() {
    Node n0, n1, n2, n3, n4, n5;
    Node *head, *tail;
    int length, mu, lambda;

    head = &n0;
    n0.next = &n1; n0.name = 'a';
    n1.next = &n2; n1.name = 'b';
    n2.next = &n3; n2.name = 'c';
    n3.next = &n4; n3.name = 'd';
    n4.next = &n5; n4.name = 'e';
    n5.name = 'f';

    n5.next = &n2; 
    cycle_finding(head, &tail, &length, &mu, &lambda);
    printf("tail: %c, length: %d, mu: %d, lambda %d\n", tail->name, length, mu, lambda);

    n5.next = &n0; 
    cycle_finding(head, &tail, &length, &mu, &lambda);
    printf("tail: %c, length: %d, mu: %d, lambda %d\n", tail->name, length, mu, lambda);

    n5.next = &n5; 
    cycle_finding(head, &tail, &length, &mu, &lambda);
    printf("tail: %c, length: %d, mu: %d, lambda %d\n", tail->name, length, mu, lambda);

    return 0;
}
