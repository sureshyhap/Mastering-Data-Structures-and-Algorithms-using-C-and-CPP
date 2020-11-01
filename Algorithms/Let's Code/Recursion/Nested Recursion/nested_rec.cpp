#include <iostream>

int func(int n);

int main(int argc, char* argv[]) {
  std::cout << func(95) << '\n';
  return 0;
}

int func(int n) {
  if (n > 100) {
    return n - 10;
  }
  else {
    func(func(n + 11));
  }
}
