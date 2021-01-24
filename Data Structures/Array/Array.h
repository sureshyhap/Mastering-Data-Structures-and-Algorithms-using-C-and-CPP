#ifndef ARRAY_H
#define ARRAY_H
#include "../List/List.h"

template <typename Type>
class Array : public List<Type> {
  template <typename Type2>
  friend std::ostream& operator<<(std::ostream& os, const Array<Type2>& arr);
 public:
  Array();
  Array(const Array<Type>& other);
  Array(Type arr[], int n);
  Array<Type>& operator=(const Array<Type>& other);
  virtual ~Array();
  virtual bool insert_beg(const Type& datum);
  virtual bool insert_end(const Type& datum);
  virtual bool insert(int index, const Type& datum);
  virtual bool remove_beg();
  virtual bool remove_end();
  virtual bool remove(int index);
  virtual bool remove_element(const Type& datum);
  virtual Type& find_kth(int index);
  virtual int find_element(const Type& datum);
  virtual bool move_next();
  virtual bool move_prev();
  virtual bool set(int index, const Type& datum);
  virtual void print() const;
  virtual void set_is_sorted();
  virtual bool check_is_sorted();
  virtual Type get_max();
  virtual Type get_min();
  virtual Type get_sum();
  virtual double get_avg();
  virtual void reverse();
  virtual void left_rotate(int shift_amount);
  virtual void right_rotate(int shift_amount);
  // Also add sort function
 protected:
  virtual void allocate(int capacity);
  virtual inline void swap(Type& f, Type& s);
  virtual int linear_search(const Type& datum);
  virtual int binary_search(const Type& datum);
};

// ARRAY_H
#endif
