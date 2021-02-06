#include <cstdio>

struct S
{
  explicit S(int value) : m_value(value) {}
  operator bool() const { return m_value; }// https://en.cppreference.com/w/cpp/language/cast_operator
private:
  int m_value{};
};

int main()
{
  S s(42);

  if (s) {
    std::printf("It's true :)\n");
  } else {
    std::printf("It's false :(\n");
  }
}
