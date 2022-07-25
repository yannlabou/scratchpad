#include <algorithm>
#include <chrono>
#include <cstdio>
#include <filesystem>
#include <iostream>


static constexpr const char *USAGE = R"(
error: The following required argument <PATH> was not provided.
USAGE: diter <PATH>
)";

int main(const int argc, const char **argv)
{
    if (argc < 2) {
        puts(USAGE);
        return EXIT_FAILURE;
    }

    namespace fs = std::filesystem;
    using ms = std::chrono::milliseconds;
    fs::path path{ argv[1] };
    fs::recursive_directory_iterator iter1{ path };
    auto start = std::chrono::system_clock::now();
    auto counter = std::distance(fs::begin(iter1), fs::end(iter1));
    std::cout << "Found " << counter << " files.\n";
    auto stop = std::chrono::system_clock::now();
    std::cout << "Recursive directory iterator w/ iterator dereferencing: "
              << std::chrono::round<ms>(stop - start).count() << " ms\n";


    start = std::chrono::system_clock::now();
    counter = 0;
    fs::recursive_directory_iterator iter2{ path }, iter_end;
    for (; iter2 != iter_end; ++iter2) { ++counter; }
    std::cout << "Found " << counter << " files.\n";
    stop = std::chrono::system_clock::now();
    std::cout << "Recursive directory iterator w iterator dereferencing: "
              << std::chrono::round<ms>(stop - start).count() << " ms\n";

    return EXIT_SUCCESS;
}