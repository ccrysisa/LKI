unsigned gcd_rec(unsigned a, unsigned b)
{
    if (!b)
        return a;
    return gcd_rec(b, a % b);
}

unsigned gcd_itr(unsigned a, unsigned b)
{
    while (b) {
        unsigned t = b;
        b = a % b;
        a = t;
    }
    return a;
}
