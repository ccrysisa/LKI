#include <stdio.h>

char *func() {
    // char *p = "hello world";
    char p[] = "hello world";
    return p;
}

int main() {
    printf("%p\n", func());
    return 0;
}
