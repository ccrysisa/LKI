#include <stdio.h>

/* bit clear: 
  a: int,
  pos: bit position to clear */
#define CLEARBIT(a, pos) (a &= ~(1 << pos))

int main() {
    /* 'z': decimal value 122 (=01111010) */
    char a = 'z';  

    /* clearing the 5th bit */
    char aOut = CLEARBIT(a, 5);

    /* aOut = 'Z': decimal value 90 (=01011010) */
    printf("aOut=%c\n", aOut);

    return 0;
}
