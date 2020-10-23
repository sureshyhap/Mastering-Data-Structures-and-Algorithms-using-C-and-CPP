#include <iostream>

int func(int n);
int func1(int n);

int main(int argc, char* argv[]) {
  //  std::cout << func(5) << '\n';
  std::cout << func(5) << '\n';
  std::cout << func(5) << '\n';
  return 0;
}

int func(int n) {
  static int sum {0};
  if (n <= 0) {
    return 0;
  }
  sum += n;
  func(n - 1);
  return sum;
}

int func1(int n) {
  static int x {1};
  if (n > 0) {
    return func1(n - 1) + x;
    ++x;
  }
  return 0;
}
