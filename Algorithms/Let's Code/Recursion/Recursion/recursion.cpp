#include <iostream>

int fun(int n);
int fact(int n);
void fun1(int n);
void fun2(int n);

int main(int argc, char* argv[]) {
  //  std::cout << fun(5) << '\n';
  //  std::cout << fact(5) << '\n';
  //  fun1(5);
  fun2(5);
  std::cout << '\n';
  return 0;
}

int fun(int n) {
  if (n <= 0) {
    return 0;
  }
  return n + fun(n - 1);
}

int fact(int n) {
  if (n <= 0) {
    return 1;
  }
  return n * fact(n - 1);
}

void fun1(int n) {
  if (n <= 0) {
    return;
  }
  std::cout << n << ' ';
  fun1(n - 1);
}

void fun2(int n) {
  if (n <= 0) {
    return;
  }
  fun2(n - 1);
  std::cout << n << ' ';
}
