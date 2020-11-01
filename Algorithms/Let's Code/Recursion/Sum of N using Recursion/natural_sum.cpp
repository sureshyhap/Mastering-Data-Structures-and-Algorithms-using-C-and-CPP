#include <iostream>

int sum_natural(int n);

int main(int argc, char* argv[]) {
  std::cout << sum_natural(5) << '\n';
  return 0;
}

int sum_natural(int n) {
  if (n == 1) {
    return 1;
  }
  return n + sum_natural(n - 1);
}
