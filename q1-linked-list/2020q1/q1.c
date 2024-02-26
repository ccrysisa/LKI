#include <stdio.h>
#include <stdlib.h>

typedef struct __list {
    int data;
    struct __list *next;
} list;

list *sort(list *start) {
    if (!start || !start->next)
        return start;
    list *left = start;
    list *right = left->next;
    left->next = NULL; // LL0;

    left = sort(left);
    right = sort(right);

    for (list *merge = NULL; left || right;) {
        if (!right || (left && left->data < right->data)) {
            if (!merge) {
                start = merge = left; // LL1;
            } else {
                merge->next = left; // LL2;
                merge = merge->next;
            }
            left = left->next; // LL3;
        } else {
            if (!merge) {
                start = merge = right; // LL4;
            } else {
                merge->next = right; // LL5;
                merge = merge->next;
            }
            right = right->next; // LL6;
        }
    }
    return start;
}

void display(list *start) {
    list *temp = start;
    printf("Traversal in forward direction \n");
    for (; temp != NULL; temp = temp->next)
        printf("%d ", temp->data);
    printf("\n");
}

int main() {
    list a = {5, NULL};
    list b = {4, &a};
    list c = {7, &b};

    list *start = &c;
    display(start);
    start = sort(start);
    display(start);
}