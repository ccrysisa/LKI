#include <time.h>

#pragma pack(push, 1)
typedef struct _test1 {
    char c[3];
    int num[256];
} test1;
#pragma pack(pop)

typedef struct _test2 {
    char c[3];
    int num[256];
} test2;

int main()
{
    test1 p1[5];
    test2 p2[5];
    printf("struct test1 size: %ld byte\n", sizeof(test1));
    printf("struct test2 size: %ld byte\n", sizeof(test2));
    for (int i = 0; i < 10; i++) {
        printf("the struct p1[%d] address =%p\n", i, p1 + i);
    }
    for (int i = 0; i < 10; i++) {
        printf("the struct p2[%d] address =%p\n", i, p2 + i);
    }
}
