// https://www.youtube.com/watch?v=2FAi2mNYjFA
// Warning: std::find() is Broken! - Sean Parent - CppCon 2021
// Remove the first odd number
#include <algorithm>
#include <iostream>
#include <vector>


int main()
{
  std::vector<int> v{ 0, 1, 2, 3, 4, 5 };
  int odd_count{ 0 };

  auto p = std::remove_if(std::begin(v),
    std::end(v),
    // Passing odd_count by value will display 0 2 4 5 - where is 3?
    // Passing odd_count by reference is fine
    [odd_count](int x) mutable { return (x & 1) && (++odd_count == 1); });
  v.erase(p, std::end(v));

  for (auto &&e : v) { std::cout << e << ' '; }
}