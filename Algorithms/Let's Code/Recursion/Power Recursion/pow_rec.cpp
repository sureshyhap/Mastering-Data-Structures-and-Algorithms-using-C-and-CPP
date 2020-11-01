#include <iostream>

int pow(int num, int exp);

int main(int argc, char* argv[]) {
  std::cout << pow(2, 8) << '\n';
  return 0;
}

int pow(int num, int exp) {
  if (exp == 1) {
    return num;
  }
  return num * pow(num, exp - 1);
}
