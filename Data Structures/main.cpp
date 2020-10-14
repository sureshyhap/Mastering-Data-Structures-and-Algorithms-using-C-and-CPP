#include <iostream>
#include "List.h"
#include "Array.h"

int main(int argc, char* argv[]) {
  ////////////////////// Test present in function
  ///////////// Do something with exceptions actually (not just printing a message)
  Array<int> a;
  a.insert_beg(5);
  a.insert_beg(4);
  a.insert_beg(3);
  a.print();
  Array<int> b(a), c;
  b.print();
  c.insert_beg(6);
  c.insert_beg(10);
  b = {c};
  b.print();
  c.insert_end(11);
  c.print();
  return 0;
}
