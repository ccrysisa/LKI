#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define STRING_SWITCH_L(s) switch (*((int32_t *) (s)) | 0x20202020)
#define MULTICHAR_CONSTANT(a, b, c, d) \
    ((int32_t) ((a) | (b) << 8 | (c) << 16 | (d) << 24))

enum {
    EXT_JPG = MULTICHAR_CONSTANT('.', 'j', 'p', 'g'),
    EXT_PNG = MULTICHAR_CONSTANT('.', 'p', 'n', 'g'),
    EXT_HTM = MULTICHAR_CONSTANT('.', 'h', 't', 'm'),
    EXT_CSS = MULTICHAR_CONSTANT('.', 'c', 's', 's'),
    EXT_TXT = MULTICHAR_CONSTANT('.', 't', 'x', 't'),
    EXT_JS = MULTICHAR_CONSTANT('.', 'j', 's', 0),
} lwan_mime_ext_t;

const char *lwan_determine_mime_type_for_file_name(char *file_name)
{
    char *last_dot = strrchr(file_name, '.');
    if ((!last_dot))
        goto fallback;

    STRING_SWITCH_L(last_dot)
    {
    case EXT_CSS:
        return "text/css";
    case EXT_HTM:
        return "text/html";
    case EXT_JPG:
        return "image/jpeg";
    case EXT_JS:
        return "application/javascript";
    case EXT_PNG:
        return "image/png";
    case EXT_TXT:
        return "text/plain";
    }

fallback:
    return "application/octet-stream";
}

int main(int argc, char *argv[])
{
    assert(argc == 2);
    printf("%s -> %s\n", argv[1],
           lwan_determine_mime_type_for_file_name(argv[1]));
    return 0;
}
