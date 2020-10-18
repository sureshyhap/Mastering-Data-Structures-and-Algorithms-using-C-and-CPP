#include <iostream>
#include "List.h"
#include "Array.h"

int main(int argc, char* argv[]) {
  Array<int> a;
  std::cout << a.get_present_index() << std::endl;
  a.insert_beg(5);
  a.insert_end(4);
  a.insert_beg(1);
  a.print();
  Array<int> b(a);
  b.print();
  Array<int> c;
  c = {b};
  c.print();
  a.insert(1, 10);
  a.print();
  a.set(1, 11);
  a.print();
  std::cout << a.find_kth(1) << std::endl;
  std::cout << a.find_element(11) << std::endl;
  std::cout << a.get_present_index() << std::endl;
  a.insert_end(14);
  std::cout << a.get_present_index() << std::endl;
  a.move_prev();
  std::cout << a.get_present_index() << std::endl;
  return 0;
}
