#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

#include <string>

[[maybe_unused]] static constexpr off_t page_size = (1 << 12);// 4 KiB page size on OS X
[[maybe_unused]] static constexpr off_t huge_page_size = (1 << 21);// 2 MiB
static const std::string filename = "/tmp/file." + std::to_string(getpid());

int main()
{
    int fd = open(filename.c_str(), O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
    if (fd < 0) {
        perror("open failed\n");
        return 1;
    }

    if (ftruncate(fd, huge_page_size) < 0) {
        perror("ftruncate failed\n");
        return 1;
    }

    auto *ptr =
      static_cast<char *>(mmap(nullptr, huge_page_size, PROT_READ | PROT_WRITE, MAP_FILE | MAP_SHARED, fd, 0));
    if (!ptr) {
        perror("mmap failed\n");
        return 1;
    }

    ptr[huge_page_size - 1] = '\n';
    return 0;
}