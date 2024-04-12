#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int mkdir_r(const char *path, int level)
{
    int ret = -1;

    if (!strlen(path))
        goto leave;

    const char *c = path;
    int cur_level = 0;

    while (cur_level <= level) {
        for (; *c && *c != '\\' && *c != '/'; c++) /* seek for separator */
            ;
        if (*c)
            c++;
        cur_level++;
    }

    const size_t sz = c - path + 1;
    char *dir = malloc(sz);
    if (!dir)
        goto leave;

    memcpy(dir, path, sz - 1);
    dir[sz - 1] = '\0';

    DIR *d = opendir(dir);
    if (!d && mkdir(dir, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH)) {
        perror("mkdir");
        goto leave;
    }

    if (*c)
        mkdir_r(path, cur_level);

    /* No more levels left */
    ret = 0;

leave:
    free(dir);
    if (d)
        closedir(d);
    return ret;
}

int main(int argc, char *argv[])
{
    mkdir_r(argv[1], 0);
    return 0;
}
