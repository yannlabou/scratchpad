#include <cstdio>
#include <thread>

int main()
{
  unsigned int thread_count =
    std::thread::hardware_concurrency();// https://en.cppreference.com/w/cpp/thread/thread/hardware_concurrency
  std::printf("%d\n", thread_count);
  return 0;
}
