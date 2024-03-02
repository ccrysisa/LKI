#include <stdlib.h>

int main()
{
    for (int i = 0; i < 10000; ++i) {
        char *z;
        z = malloc(sizeof(char));
        void *p = z;
    }
    return 0;
}
