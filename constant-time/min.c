#include <stdint.h>
#include <stdio.h>
int32_t min(int32_t a, int32_t b) {
    int32_t diff = (a - b);
    return b + (diff & (diff >> 31));
}

int32_t max(int32_t a, int32_t b) {
    int32_t diff = (b - a);
    return b - (diff & (diff >> 31));
}

int main() {
    int32_t a = INT32_MAX, b = INT32_MIN;
    printf("min(%d, %d) = %d\n", a, b, min(a, b));
    printf("max(%d, %d) = %d\n", a, b, max(a, b));
    return 0;
}