#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#ifdef MACRO
#define func(a, b) a *b
#else
int func(int a, int b)
{
    return a * b;
}
#endif

long long getLong(char *s)
{
    long long ret = 0;
    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        ret *= 10;
        ret += s[i] - '0';
    }
    return ret;
}

int main(int argc, char **argv)
{
    int ret;
    if (argc <= 1)
        exit(0);
    long long cnt = getLong(argv[1]);
    FILE *f = fopen(NAME, "w");

    for (long long i = 0; i < cnt; ++i) {
        printf("recording %lld\n", i);
        long long tmp = i;
        struct timeval start, end, diff;

        gettimeofday(&start, NULL);
        while (tmp--) {
            ret = func(1, 1);
        }
        gettimeofday(&end, NULL);

        diff.tv_sec = end.tv_sec - start.tv_sec;
        diff.tv_usec = end.tv_usec + (1000000 - start.tv_usec);

        if (diff.tv_usec < 1000000)
            --diff.tv_sec;
        else
            diff.tv_usec -= 1000000;

        fprintf(f, "%lld %lf\n", i, diff.tv_sec + 1e-6 * diff.tv_usec);
    }

    return 0;
}
