#include <chrono>
#include <cstdlib>
#include <iostream>
#include <mutex>
#include <thread>

int main()
{
    auto thread_count = std::thread::hardware_concurrency();
    std::int64_t t_start, t_join;
    std::once_flag bm_started;
    for (std::size_t i = 0; i != thread_count; ++i) {
        auto begin = std::chrono::system_clock::now();
        auto thread_begin = begin;
        std::thread t([&] {
            std::call_once(bm_started, [] { std::cout << "Benchmark started\n"; });
            thread_begin = std::chrono::system_clock::now();
        });
        t.join();
        auto end = std::chrono::system_clock::now();
        auto t1 = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
        auto t2 = std::chrono::duration_cast<std::chrono::microseconds>(thread_begin - begin).count();
        t_join += t1;
        t_start += t2;
    }
    std::cout << "Average time to start " << thread_count << " threads is " << t_start / thread_count << " us\n";
    std::cout << "Average time to join  " << thread_count << " threads is " << t_join / thread_count << " us\n";
    return EXIT_SUCCESS;
}

// g++ -pthread -std=c++17 thread_bm.cpp -latomic -lrt -lm