#include <stdint.h>

int32_t ReLU_int32(int32_t x)
{
    return ~(x >> 31) & x;
}

float ReLU_float(float x)
{
    union {
        float f;
        int32_t i;
    } u = {.f = x};

    u.i &= ~(u.i >> 31);
    return u.f;
}

double ReLU_double(float x)
{
    union {
        double f;
        int64_t i;
    } u = {.f = x};

    u.i &= ~(u.i >> 63);
    return u.f;
}

int main()
{
    double x, y;
    x = 5.13;
    y = ReLU_double(x);
    x = -17.9;
    y = ReLU(x);
    return 0;
}
