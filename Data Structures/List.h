#ifndef LIST_H
#define LIST_H
#include <iostream>

template <typename Type>
class List {
 public:
  virtual ~List() = 0;
  virtual bool insert_beg(const Type& datum) = 0;
  virtual bool insert_end(const Type& datum) = 0;
  virtual bool insert(int index, const Type& datum) = 0;
  /*
  virtual bool remove_beg() = 0;
  virtual bool remove_end() = 0;
  virtual bool remove(int index) = 0;
  virtual bool remove_element(const Type& datum) = 0;
  virtual bool find_kth(int index) = 0;
  virtual int find_element(const Type& datum) = 0;
  virtual bool move_next() = 0;
  virtual bool move_prev() = 0;
  virtual void set(int index, const Type& datum) = 0;
  */
  virtual void print() = 0;
// Also add sort function
protected:
  virtual void allocate(int capacity) = 0;
  Type* first {nullptr}, * present {nullptr};
  int size {0};
};

template <typename Type>
List<Type>::~List() {
  
}

// LIST_H
#endif
