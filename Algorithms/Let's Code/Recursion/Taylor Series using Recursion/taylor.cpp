#include <iostream>
#include <ctime>

long long fact(int n);
long double pow(long double base, int exp);
long double exp_iter(long double x, int num_terms);
long double exp_rec(long double x, int n);

int main(int argc, char* argv[]) {
  clock_t t1 = clock();
  std::cout << exp_iter(10, 15) << '\n';
  clock_t t2 = clock();
  double time_diff = static_cast<double>(t2 - t1) / CLOCKS_PER_SEC;
  std::cout << time_diff << '\n';

  return 0;
}

long long fact(int n) {
  if (n == 0) {
    return 1;
  }
  return n * fact(n - 1);
}

long double pow(long double base, int exp) {
  if (exp == 0) {
    return 1;
  }
  if (exp % 2 == 0) {
    return pow(base * base, exp / 2);
  }
  else {
    return base * pow(base * base, exp / 2);
  }
}

long double exp_iter(long double x, int num_terms) {
  double sum = {};
  for (int i = {0}; i <= num_terms; ++i) {
    sum += pow(x, i) / fact(i);
  }
  return sum;
}

long double exp_rec(long double x, int n) {
  if (n == 0) {
    return 1;
  }
  return pow(x, n) / fact(n) + exp_rec(x, n - 1);
}
