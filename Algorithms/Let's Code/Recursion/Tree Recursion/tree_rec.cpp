#include <iostream>

void func(int n);

int main(int argc, char* argv[]) {
  func(3);
  return 0;
}

void func(int n) {
  if (n == 0) {
    return;
  }
  else {
    std::cout << n << ' ';
    func(n - 1);
    func(n - 1);
  }
}
