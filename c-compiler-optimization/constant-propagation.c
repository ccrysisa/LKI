int main()
{
    int a = 11, b = 13, c = 5566;
    int i, result;
    for (i = 0; i < 10000; i++)
        result = (a * b + i) / (a * c);
    return result;
}
