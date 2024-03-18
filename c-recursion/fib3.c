#include <stdio.h>

int fib(int n) {
    if (n == 0) return 0;
    int t0 = 1; // F(n)
    int t1 = 1; // F(n + 1)
    int t3 = 1; // F(2n)
    int t4; // F(2n+1)
    int i = 1;
    while (i < n) {
        if ((i << 1) <= n) {
            t4 = t1 * t1 + t0 * t0;
            t3 = t0 * (2 * t1 - t0);
            t0 = t3;
            t1 = t4;
            i = i << 1;
        } else {
            t0 = t3;       // F(n-2);
            t3 = t4;       // F(n-1);
            t4 = t0 + t4;  // F(n)
            i++;
        }
    }
    return t3;
}

int main() {
    for (int i = 0; i <= 20; i++) {
        printf("%d\n", fib(i));
    }
    return 0;
}
