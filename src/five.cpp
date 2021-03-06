#include <cstdio>
#include <utility>// std::move

struct S
{
  S() noexcept { puts("Construct S"); }
  S(const S &) noexcept { puts("Copy construct S"); }// https://en.cppreference.com/w/cpp/language/copy_constructor
  S(S &&) noexcept { puts("Move construct S"); }// https://en.cppreference.com/w/cpp/language/move_constructor
  S &operator=(const S &)// https://en.cppreference.com/w/cpp/language/copy_assignment
  {
    puts("Copy assign S");
    return *this;// https://en.cppreference.com/w/cpp/language/this
  }
  S &operator=(S &&)// https://en.cppreference.com/w/cpp/language/move_assignment
  {
    puts("Move assign S");
    return *this;// https://en.cppreference.com/w/cpp/language/this
  }
  virtual ~S() { puts("Destroy S"); }

  virtual void do_work() { puts("do_work for S"); }
};

int main()
{
  S s1;
  S s2 = std::move(s1);// s1 becomes a moved-from object
}