#include <stdio.h>

static inline void swap(char *a, char *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int rev_core(char *head, int idx)
{
    if (head[idx] != '\0') {
        int end = rev_core(head, idx + 1);
        if (idx > end / 2)
            swap(head + idx, head + end - idx);
        return end;
    }
    return idx - 1;
}

char *reverse(char *s)
{
    rev_core(s, 0);
    return s;
}

int main()
{
    char s[] = "hello";
    int i = rev_core(s, 0);
    printf("%s\n", s);
    printf("%d\n", i);
    return 0;
}
