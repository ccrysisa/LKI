#include <stdio.h>

int fib_rec(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

int fib_itr(int n)
{
    int pre = -1;
    int result = 1;
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum = result + pre;
        pre = result;
        result = sum;
    }
    return result;
}

int fib_tail_rec(int n, int a, int b)
{
    if (n == 0)
        return a;
    return fib_tail_rec(n - 1, b, a + b);
}

int fib(int n)
{
    return fib_tail_rec(n, 0, 1);
}

int main()
{
    printf("%d\n", fib_rec(15));
    printf("%d\n", fib_itr(15));
    printf("%d\n", fib(15));
    return 0;
}
