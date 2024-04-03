#include <stdio.h>

void funci(int x)
{
    printf("func value = %d\n", x);
}
void funcc(char c)
{
    printf("func char = %c\n", c);
}
void funcdef(double v)
{
    printf("Def func's value = %lf\n", v);
}

#define func(X) _Generic((X), int : funci, char : funcc, default : funcdef)(X)

int main()
{
    func(1);
    func('a');
    func(1.3);
    return 0;
}
