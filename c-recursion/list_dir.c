#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

void list_dir(const char *dir_name)
{
    DIR *d = opendir(dir_name);
    if (!d) return; /* fail to open directory */

    while (1) {
        struct dirent *entry = readdir(d);
        if (!entry) break;

        const char *d_name = entry->d_name;
        if (strcmp(d_name, "..") && strcmp(d_name, ".")) {
            printf("%s/%s\n", dir_name, d_name);
        }

        if ((entry->d_type & DT_DIR) && strcmp(d_name, "..") &&
            strcmp(d_name, ".")) {
            char path[PATH_MAX];
            int path_length =
                snprintf(path, PATH_MAX, "%s/%s", dir_name, d_name);
            // printf("%s\n", path);
            if (path_length >= PATH_MAX)
                return;
            /* Recursively call "list_dir" with new path. */
            list_dir(path);
        }
    }

    if (closedir (d)) return;
}

int main(int argc, char *argv[])
{
    list_dir(argv[1]);
    return 0;
}
