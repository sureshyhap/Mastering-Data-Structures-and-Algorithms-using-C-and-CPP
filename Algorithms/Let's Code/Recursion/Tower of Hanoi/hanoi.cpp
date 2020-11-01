#include <iostream>

void hanoi(int rings, char source, char auxiliary, char destination);

int main(int argc, char* argv[]) {
  hanoi(4, 'A', 'B', 'C');
  return 0;
}

void hanoi(int rings, char source, char auxiliary, char destination) {
  static int count = 0;
  if (rings == 1) {
    std::cout << "Move ring from "<< source << " to " << destination << '\n';
    ++count;
    return;
  }
  hanoi(rings - 1, source, destination, auxiliary);
  hanoi(1, source, auxiliary, destination);
  hanoi(rings - 1, auxiliary, source, destination);
  std::cout << std::endl << count;
}
