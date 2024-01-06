#include <stdint.h>
#include <stdio.h>
int32_t abs(int32_t x) {
    int32_t mask = (x >> 31);
    return (x + mask) ^ mask;
}

int32_t abs2(int32_t x) {
    int32_t mask = (x >> 31);
    return (x ^ mask) - mask;
}

int main() {
    int32_t test = INT32_MIN;
    printf("abs(%d) = %d\n", test, abs(test));
    printf("abs(%d) = %d\n", test, abs2(test));
    return 0;
}