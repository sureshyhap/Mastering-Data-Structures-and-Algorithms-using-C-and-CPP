#ifndef ARRAY_H
#define ARRAY_H
#include "List.h"

template <typename Type>
class Array : public List<Type> {
  template <typename Type2>
  friend std::ostream& operator<<(std::ostream& os, const Array<Type2>& arr);
 public:
  Array();
  Array(const Array<Type>& other);
  Array<Type>& operator=(const Array<Type>& other);
  virtual ~Array();
  virtual bool insert_beg(const Type& datum);
  virtual bool insert_end(const Type& datum);
  virtual bool insert(int index, const Type& datum);
  /*
  virtual bool remove_beg();
  virtual bool remove_end();
  virtual bool remove(int index);
  virtual bool remove_element(const Type& datum);
  virtual bool find_kth(int index);
  virtual int find_element(const Type& datum);
  virtual bool move_next();
  virtual bool move_prev();
  virtual void set(int index, const Type& datum);
  */
  virtual void print();
 protected:
  virtual void allocate(int capacity);
};

// ARRAY_H
#endif
