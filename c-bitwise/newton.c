#include <stdio.h>
#include <stdlib.h>

int mySqrt(int n)
{
    if (n == 0)
        return 0;
    if (n < 4)
        return 1;

    unsigned int ans = n / 2;
    if (ans > 65535)  // 65535 = 2^16 - 1
        ans = 65535;

    while (ans * ans > n || (ans + 1) * (ans + 1) <= n)
        ans = (ans + n / ans) / 2;
    return ans;
}

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    printf("sqrt(%d) = %d\n", n, mySqrt(n));
    return 0;
}
