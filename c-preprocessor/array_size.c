#include <stdio.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

int main(void)
{
    int a[10];
    int *a_ptr = a;

    printf("%ld\n", ARRAY_SIZE(a));
    printf("%ld\n", ARRAY_SIZE(a_ptr));

    return 0;
}
