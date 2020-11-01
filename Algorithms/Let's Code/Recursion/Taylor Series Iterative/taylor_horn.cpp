#include <iostream>
#include <ctime>

long double exp_iter(long double x, int n);

int main(int argc, char* argv[]) {
  clock_t t1 = clock();
  std::cout << exp_iter(2, 15) << '\n';
  clock_t t2 = clock();
  double time_diff = static_cast<double>(t2 - t1) / CLOCKS_PER_SEC;
  std::cout << time_diff << '\n';
  return 0;
}

long double exp_iter(long double x, int n) {
  long double result = {1};
  for (int i = {n}; i > 0; --i) {
    result = result * (x / i) + 1;
  }
  return result;
}
