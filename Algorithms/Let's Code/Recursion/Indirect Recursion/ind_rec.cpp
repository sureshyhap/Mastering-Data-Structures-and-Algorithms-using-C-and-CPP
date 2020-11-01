#include <iostream>

constexpr double ANGLE_CUTOFF = 1e-5;
constexpr double PI = 3.14159;

double sin(double angle);
double cos(double angle);

int main(int argc, char* argv[]) {
  std::cout << sin(PI / 4) << '\n';
  return 0;
}

double sin(double angle) {
  if (angle < ANGLE_CUTOFF) {
    // sin(x) ~ x for small x
    return angle;
  }
  return 2 * sin(angle / 2) * cos(angle / 2);
}

double cos(double angle) {
  if (angle < ANGLE_CUTOFF) {
    // cos(x) ~ 1 for small x
    return 1;
  }
  return 1 - 2 * sin(angle / 2) * sin(angle / 2);
}
