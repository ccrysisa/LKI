// crt_countof.cpp
#define _UNICODE
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>

int main(void)
{
    _TCHAR arr[20], *p;
    printf("sizeof(arr) = %zu bytes\n", sizeof(arr));
    printf("_countof(arr) = %zu elements\n", _countof(arr));
    // In C++, the following line would generate a compile-time error:
    // printf( "%zu\n", _countof(p) ); // error C2784 (because p is a pointer)

    _tcscpy_s(arr, _countof(arr), _T("a string"));
    // unlike sizeof, _countof works here for both narrow- and wide-character
    // strings
}
