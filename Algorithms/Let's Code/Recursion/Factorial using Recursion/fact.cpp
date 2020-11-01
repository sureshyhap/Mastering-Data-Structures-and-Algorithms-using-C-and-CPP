#include <iostream>

int fact(int n);

int main(int argc, char* argv[]) {
  std::cout << fact(5) << '\n';
  return 0;
}

int fact(int n) {
  if (n == 1) {
    return 1;
  }
  return n * fact(n - 1);
}
