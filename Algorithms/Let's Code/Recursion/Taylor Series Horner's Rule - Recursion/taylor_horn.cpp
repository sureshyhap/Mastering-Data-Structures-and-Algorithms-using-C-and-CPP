#include <iostream>
#include <ctime>

long double exp(long double x, int n);

int main(int argc, char* argv[]) {
  clock_t t1 = clock();
  std::cout << exp(10, 15) << '\n';
  clock_t t2 = clock();
  double time_diff = static_cast<double>(t2 - t1) / CLOCKS_PER_SEC;
  std::cout << time_diff << '\n';
  return 0;
}

long double exp(long double x, int n) {
  static int i = {1};
  if (n == 0) {
    return 1;
  }
  // Horner's rule for less multiplications
  return 1 + x / i++ * exp(x, n - 1);
}
