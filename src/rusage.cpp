#include <sys/resource.h>
#include <iostream>

static constexpr std::size_t length = 10 * 1024 * 1024; // 10 MB

int main() {
    rusage ru1{};
    getrusage(RUSAGE_SELF, &ru1);
    [[maybe_unused]] char *buffer{new char[length]};
    for (std::size_t i = 0; i != length; ++i) {
        buffer[i] = 0;
    }
    rusage ru2{};
    getrusage(RUSAGE_SELF, &ru2);

    // ru_maxrss: max resident set size i.e. current physical memory (in bytes on BSD, kilobytes on Linux)
#ifdef __APPLE__
    long mem_usage = (ru2.ru_maxrss - ru1.ru_maxrss) >> 20; //NOLINT
#else
    long mem_usage = (ru2.ru_maxrss - ru1.ru_maxrss) >> 10; //NOLINT
#endif
    std::cout << "Physical memory usage: " << mem_usage << " MB";
    return 0;
}