#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    char *p, *q;
    uintptr_t pv, qv;
    {
        char a = 3;
        p = &a;
        pv = (uintptr_t) p;
    }
    {
        char b = 4;
        q = &b;
        qv = (uintptr_t) q;
    }
    if (p != q) {
        printf("%p is different from %p\n", (void *) p, (void *) q);
        printf("%" PRIxPTR " is not the same as %" PRIxPTR "\n", pv, qv);
    } else {
        printf("Surprise!\n");
    }
    return 0;
}
