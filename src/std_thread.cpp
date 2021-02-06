#include <cstdio>
#include <thread>

int main()
{
  unsigned int cpu_count =
    std::thread::hardware_concurrency();// https://en.cppreference.com/w/cpp/thread/thread/hardware_concurrency
  std::printf("%d\n", cpu_count);
  return 0;
}