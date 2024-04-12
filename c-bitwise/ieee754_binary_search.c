#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef union {
    float value;
    uint32_t v_int;
} ieee_float_shape_type;

/* Get a 32 bit int from a float. */
#define EXTRACT_WORDS(ix0, d)       \
    do {                            \
        ieee_float_shape_type ew_u; \
        ew_u.value = (d);           \
        (ix0) = ew_u.v_int;         \
    } while (0)

int mySqrt(int n)
{
    int32_t sign = 0x80000000;
    int32_t ix0, m, i;

    float x = n;
    EXTRACT_WORDS(ix0, x);

    /* take care of zero */
    if (ix0 <= 0) {
        if ((ix0 & (~sign)) == 0)
            return x; /* sqrt(+-0) = +-0 */
        if (ix0 < 0)
            return (x - x) / (x - x); /* sqrt(-ve) = sNaN */
    }

    /* normalize x */
    m = (ix0 >> 23);
    if (m == 0) { /* subnormal x */
        for (i = 0; (ix0 & 0x00800000) == 0; i++)
            ix0 <<= 1;
        m -= i - 1;
    }
    m -= 127; /* unbias exponent */
    ix0 = (ix0 & 0x007fffff) | 0x00800000;
    if (m & 1) /* odd m, double x to make it even */
        ix0 += ix0;
    m >>= 1; /* m = [m/2] */

    /* binary search 'm' */
    unsigned int head = 1 << m;             // 2^m
    unsigned int tail = 1 << (m + 1);       // 2^(m+1)
    unsigned int mid = (head + tail) >> 1;  // same as (2^m + 2^(m+1)) / 2
    while (1) {
        if (n > (mid + 1) * (mid + 1)) {
            head = mid;
            mid = (head + tail) >> 1;
        } else if (n < mid * mid) {
            tail = mid;
            mid = (head + tail) >> 1;
        } else
            break;
    }

    return mid;
}

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    printf("sqrt(%d) = %d\n", n, mySqrt(n));
    return 0;
}
