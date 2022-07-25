#include <stdio.h>
#include <unistd.h>

constexpr size_t PATH_MAX = 1024;

int main()
{
    char path_name[PATH_MAX];
    auto len = readlink("/proc/self/exe", path_name, PATH_MAX - 1);
    if (len != -1) {
        path_name[len] = '\0';
        printf("%s\n", path_name);
    }
    return 0;
}