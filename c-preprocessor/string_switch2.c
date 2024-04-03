#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

static inline uint32_t string_to_uint32(const char *s)
{
    uint32_t v;

    memcpy(&v, s, sizeof(v));

    return v;
}

#define STRING_SWITCH(s) switch (string_to_uint32(s))
#define MCC(a, b, c, d) ((a) | (b) << 8 | (c) << 16 | (d) << 24)
enum {
    METHOD_GET = MCC('G', 'E', 'T', ' '),
    METHOD_POST = MCC('P', 'O', 'S', 'T'),
    METHOD_DELETE = MCC('D', 'E', 'L', 'E'),
    METHOD_HEAD = MCC('H', 'E', 'A', 'D'),
    /* ... */
};

const char *lwan_determine_handler_for_request(char *request)
{
    STRING_SWITCH(request)
    {
    case METHOD_GET:
        return "HTTP_METHOD_GET";
    case METHOD_POST:
        return "HTTP_METHOD_POST";
    case METHOD_DELETE:
        return "HTTP_METHOD_DELETE";
    case METHOD_HEAD:
        return "HTTP_METHOD_HEAD";
    /* ... */
    default:
        return "HTTP_METHOD_UNKNOWN";
    }
}

int main(int argc, char *argv[])
{
    assert(argc == 2);
    printf("%s -> %s\n", argv[1], lwan_determine_handler_for_request(argv[1]));
    return 0;
}
