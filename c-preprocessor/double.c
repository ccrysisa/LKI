#include <stdio.h>

#if 0
#define DOUBLE(a) ((a) + (a))
#endif

#if 0
#define DOUBLE(a)                         \
    ({                                    \
        __typeof__(a) _x_in_DOUBLE = (a); \
        _x_in_DOUBLE + _x_in_DOUBLE;      \
    })
#endif

#define DOUBLE(a)         \
    (^(__typeof__(a) x) { \
      return x + x;       \
    }(a))

int foo()
{
    printf(__func__);
    return 3;
}

int main()
{
    return DOUBLE(foo());
}
