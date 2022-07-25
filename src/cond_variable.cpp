#include <condition_variable>
#include <cstdio>
#include <fstream>
#include <mutex>
#include <string>
#include <thread>

std::mutex m;
std::condition_variable cv;
bool ready{ false };

void wait_for_completion(int value)
{
    std::unique_lock<std::mutex> lock(m);
    cv.wait(lock, [=] { return ready; });
    std::printf("Value is %d\n", value);
}

void complete()
{
    {
        std::lock_guard<std::mutex> lock(m);
        std::ifstream input_file("/Users/yannlabou/Code/scratchpad/CMakeLists.txt");
        std::string line;
        while (std::getline(input_file, line)) { continue; }
        ready = true;
    }
    cv.notify_all();
    std::printf("Read file done!\n");
}

int main()
{
    std::thread t1(wait_for_completion, 42);
    std::thread t2(complete);
    t2.join();
    t1.join();
    return 0;
}
