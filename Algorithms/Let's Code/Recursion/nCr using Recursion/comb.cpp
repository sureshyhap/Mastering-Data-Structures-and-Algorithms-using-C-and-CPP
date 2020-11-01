#include <iostream>

int combination(int n, int r);
int factorial(int n);
int comb_rec(int n, int r);

int main(int argc, char* argv[]) {
  std::cout << comb_rec(5, 3) << '\n';

  return 0;
}

int combination(int n, int r) {
  return factorial(n) / (factorial(n - r) * factorial(r));
}

int factorial(int n) {
  if (n < 2) {
    return 1;
  }
  int product = {1};
  for (int i = {2}; i <= n; ++i) {
    product *= i;
  }
  return product;
}

int comb_rec(int n, int r) {
  if (r == 0 or r == n) {
    return 1;
  }
  return comb_rec(n - 1, r - 1) + comb_rec(n - 1, r);
}
