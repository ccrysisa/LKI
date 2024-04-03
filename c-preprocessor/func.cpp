#include <stdio.h>
#include <iostream>
using namespace std;

template <typename T>
void func(T v)
{
    cout << "Def func's value = " << v << endl;
}

template <>
void func<int>(int x)
{
    printf("func value = %d\n", x);
}

template <>
void func<char>(char c)
{
    printf("func char = %c\n", c);
}

int main()
{
    func(1);
    func('a');
    func(1.3);
    return 0;
}
