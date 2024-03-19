#include <stdio.h>

static void swap(char *a, char *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

char *reverse(char *s)
{
    if ((*s == '\0') || (*(s + 1) == '\0'))
        return NULL;

    reverse(s + 1);
    swap(s, (s + 1));

    if (*(s + 2) != '\0')
        reverse(s + 2);
    reverse(s + 1);
}

int main()
{
    char s[] = "hello";
    reverse(s);
    printf("%s\n", s);
    return 0;
}
