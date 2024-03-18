int func(int x)
{
    static int count = 0;
    int y = x;
    return ++count && func(x++);
}

int main()
{
    return func(0);
}
