#include <stddef.h>
#include <stdint.h>

uint8_t unaligned_get8(void *src)
{
    uintptr_t csrc = (uintptr_t) src;
    uint32_t v = *(uint32_t *) (csrc & 0xfffffffc);
    v = (v >> (((uint32_t) csrc & 0x3) * 8)) & 0x000000ff;
    return v;
}

uint32_t unaligned_get32(void *src)
{
    uint32_t d = 0;
    uintptr_t csrc = (uintptr_t) src;
    for (int n = 0; n < 4; n++) {
        uint32_t v = unaligned_get8((void *) csrc);
        v = v << (n * 8);
        d = d | v;
        csrc++;
    }
    return d;
}

void unaligned_set8(void *dest, uint8_t value)
{
    uintptr_t cdest = (uintptr_t) dest;
    uintptr_t ptr = cdest & 0xfffffffc;
    uint32_t d = 0;
    for (int n = 0; n < 4; n++) {
        uint32_t v;
        if (n == (ptr & 0x3))
            v = value;
        else
            v = unaligned_get8((void *) ptr);
        v = v << (n * 8);
        d = d | v;
        ptr++;
    }
    *(uint32_t *) (cdest & 0xfffffffc) = v;
}

void unaligned_set32(void *dest, uint32_t value)
{
    uintptr_t cdest = (uintptr_t) dest;
    for (int n = 0; n < 4; n++) {
        unaligned_set8((void *) cdest, value & 0x000000ff);
        value = value >> 8;
        cdest++;
    }
}

int main()
{
    uint8_t a[4];
}
