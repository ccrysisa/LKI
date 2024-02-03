typedef struct list_entry {
    int value;
    struct list_entry *next;
} list_entry_t;

void append(int value, list_entry_t *head) {
    list_entry_t **indirect = &head;

    list_entry_t *new = malloc(1 * sizeof(list_entry_t));
    new->value = value, new->next = NULL;
        
    while (*indirect) {
        *indirect = &((*indirect)->next);
    }
    *indirect = new;
}

void remove(list_entry_t **head, int value) {
    list_entry_t *indirect = &head;

    while ((*indirect)->value != value) {
        indirect = &((*indirect)->next);
    }
    *indirect = (*indirect)->next;
}

