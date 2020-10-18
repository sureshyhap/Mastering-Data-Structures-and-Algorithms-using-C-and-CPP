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
  */
  virtual Type& find_kth(int index) = 0;
  virtual int find_element(const Type& datum) = 0;
  virtual bool move_next() = 0;
  virtual bool move_prev() = 0;
  virtual bool set(int index, const Type& datum) = 0;
  virtual void print() const = 0;
  Type* get_first() const;
  Type* get_present() const;
  ptrdiff_t get_present_index() const;
  int get_size() const;
// Also add sort function
protected:
  virtual void allocate(int capacity) = 0;
  Type* first {nullptr}, * present {nullptr};
  int size {0};
};

template <typename Type>
List<Type>::~List() {
  
}

template <typename Type>
Type* List<Type>::get_first() const {
  return first;
}

template <typename Type>
Type* List<Type>::get_present() const {
  return present;
}

template <typename Type>
ptrdiff_t List<Type>::get_present_index() const {
  if (first == nullptr or present == nullptr) {
    return -1;
  }
  else {
    return present - first;
  }
}

template <typename Type>
int List<Type>::get_size() const {
  return size;
}

// LIST_H
#endif
