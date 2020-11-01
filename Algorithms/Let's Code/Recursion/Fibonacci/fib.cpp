#include <iostream>
#include <vector>

int fib(int n);
int fib2(int n);

int main(int argc, char* argv[]) {
  std::cout << fib2(7) << '\n';
  return 0;
}

// Starts at the 0th Fibonacci number
int fib(int n) {
  if (n <= 1) {
    return n;
  }
  int prev2 = {0}, prev1 = {1}, current = {};
  for (int i = {2}; i <= n; ++i) {
    current = {prev2 + prev1};
    prev2 = {prev1};
    prev1 = {current};
  }
  return current;
}

int fib2(int n) {
  if (n <= 1) {
    return n;
  }
  static std::vector<int> table(n, -1);
  if (table.at(0) == -1 or table.at(1) == -1) {
    table.at(0) = 0;
    table.at(1) = 1;
  }
  if (table.at(n - 2) != -1 and
      table.at(n - 1) != -1) {
    table.at(n) = {table.at(n - 2) + table.at(n - 1)};
  }
  return fib2(n - 2) + fib2(n - 1);
}
