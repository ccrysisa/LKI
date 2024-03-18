#include <stdio.h>
#include <string.h>

void matrix_multiply(int a[2][2], int b[2][2], int t[2][2])
{
    memset(t, 0, sizeof(int) * 2 * 2);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                t[i][j] += a[i][k] * b[k][j];
}

void matrix_pow(int a[2][2], int n, int t[2][2])
{
    if (n == 1) {
        t[0][0] = a[0][0];
        t[0][1] = a[0][1];
        t[1][0] = a[1][0];
        t[1][1] = a[1][1];
        return;
    }
    if (n % 2 == 0) {
        int t1[2][2];
        matrix_pow(a, n >> 1, t1);
        matrix_multiply(t1, t1, t);
        return;
    } else {
        int t1[2][2], t2[2][2];
        matrix_pow(a, n >> 1, t1);
        matrix_pow(a, (n >> 1) + 1, t2);
        matrix_multiply(t1, t2, t);
        return;
    }
}

int fib(int n)
{
    if (n <= 0)
        return 0;
    int A1[2][2] = {{1, 1}, {1, 0}};

    int result[2][2];
    matrix_pow(A1, n, result);
    return result[0][1];
}

int main()
{
    for (int i = 0; i < 21; i++) {
        printf("%d\n", fib(i));
    }
    return 0;
}
