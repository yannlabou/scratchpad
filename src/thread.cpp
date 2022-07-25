#include <mutex>
#include <thread>
#include <chrono>
#include <iostream>

int main()
{
    std::mutex m;

    std::thread t([&] {
        for (std::size_t i = 0; i != 10; ++i) {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            { std::lock_guard<std::mutex> g(m); std::cout << "Worker thread " << std::this_thread::get_id() << '\n';}
        }
    });

    for (std::size_t i = 0; i != 10; ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        {
            std::lock_guard<std::mutex> g(m);
            std::cout << "Main thread " << std::this_thread::get_id() << '\n';
        }
    }

    t.join();
}

// g++ -pthread -std=c++17 thread.cpp -latomic -lrt -lm