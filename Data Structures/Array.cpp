#include <iostream>
#include "List.h"
#include "Array.h"
#include <stdexcept>

template <typename Type2>
std::ostream& operator<<(std::ostream& os, const Array<Type2>& arr) {
  for (int i {0}; i < arr.size; ++i) {
    os << (arr.first)[i] << ' ';
  }
  return os;
}

template <typename Type>
Array<Type>::Array() {

}

template <typename Type>
Array<Type>::Array(const Array<Type>& other) {
  delete [] this->first;
  this->first = {nullptr};
  allocate(other.size);
  this->present = {this->first};
  this->size = {other.size};
  for (int i {0}; i < this->size; ++i) {
    this->first[i] = {other.first[i]};
  }
}

template <typename Type>
Array<Type>& Array<Type>::operator=(const Array<Type>& other) {
  delete [] this->first;
  this->first = {nullptr};
  allocate(other.size);
  this->present = {this->first};
  this->size = {other.size};
  for (int i {0}; i < this->size; ++i) {
    this->first[i] = {other.first[i]};
  }
  return *this;
}

template <typename Type>
Array<Type>::~Array() {
  delete [] this->first;
  this->first = {nullptr};
  this->present = {nullptr};
  this->size = {0};
}

template <typename Type>
bool Array<Type>::insert_beg(const Type& datum) {
  return insert(0, datum);
}

template <typename Type>
bool Array<Type>::insert_end(const Type& datum) {
  return insert(this->size, datum);
}

template <typename Type>
bool Array<Type>::insert(int index, const Type& datum) {
  if (index > this->size or index < 0) {
    return false;
  }
  Type* copy {this->first};
  ptrdiff_t present_index {-1};
  if (this->first != nullptr and this->present != nullptr) {
    present_index = {this->present - this->first};
  }
  this->first = {nullptr};
  this->present = {nullptr};
  ++(this->size);
  allocate(this->size);
  int i {0};
  // Copy first part of array
  for (i = {0}; i < index; ++i) {
    this->first[i] = {copy[i]};
  }
  // Copy data into index spot
  this->first[i++] = {datum};
  // Copy last part of array
  for (; i < this->size; ++i) {
    this->first[i] = {copy[i - 1]};
  }
  // Either first or present were nullptr so reset present
  if (present_index == -1) {
    this->present = {this->first};
  }
  // If element inserted was after present, present stays the same
  else if (present_index < index) {
    this->present = {this->first + present_index};
  }
  // Otherwise present shifts over to stay at the element it was pointing to
  else {
    this->present = {this->first + present_index + 1};
  }
  delete [] copy;
  return true;
}

template <typename Type>
bool Array<Type>::remove_beg() {
  return remove(0);
}

template <typename Type>
bool Array<Type>::remove_end() {
  return remove(this->size - 1);
}

template <typename Type>
bool Array<Type>::remove(int index) {
  if (index >= this->size or index < 0) {
    return false;
  }
  Type* copy {this->first};
  // Keeping track of present's position for later
  ptrdiff_t present_index {this->present - this->first};
  this->first = {new Type[--(this->size)]};
  for (int i {0}; i < index; ++i) {
    this->first[i] = copy[i];
  }
  for (int i {index}; i < this->size; ++i) {
    this->first[i] = copy[i + 1];
  }
  // Present's item was removed
  if (present_index == index) {
    this->present = this->first;
  }
  // Present is unaffected if the index of the removed element
  // is after its own
  else if (present_index < index) {
    this->present = this->first + present_index;
  }
  // Present shifts over to the left if the element
  // removed was to its left
  else {
    this->present = this->first + present_index - 1;
  }
  delete [] copy;
  return true;
}

template <typename Type>
bool Array<Type>::remove_element(const Type& datum) {
  return remove(find_element(datum));
}

template <typename Type>
Type& Array<Type>::find_kth(int index) {
  try {
    if (index >= this->size or index < 0) {
      throw std::runtime_error("Invalid index");
    }
  }
  catch (const std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    exit(1);
  }
  return this->first[index];
}

template <typename Type>
int Array<Type>::find_element(const Type& datum) {
  for (int i {0}; i < this->size; ++i) {
    if (datum == this->first[i]) {
      return i;
    }
  }
  return -1;
}

template <typename Type>
bool Array<Type>::move_next() {
  if (this->present == nullptr) {
    return false;
  }
  ptrdiff_t present_index {this->present - this->first};
  if (present_index == this->size - 1) {
    return false;
  }
  else {
    ++this->present;
    return true;
  }
}

template <typename Type>
bool Array<Type>::move_prev() {
  if (this->present == nullptr) {
    return false;
  }

  ptrdiff_t present_index {this->present - this->first};
  if (present_index == 0) {
    return false;
  }
  else {
    --this->present;
    return true;
  }
}

template <typename Type>
bool Array<Type>::set(int index, const Type& datum) {
  if (index >= this->size or index < 0) {
    return false;
  }
  this->first[index] = {datum};
  return true;
}

template <typename Type>
void Array<Type>::print() const {
  std::cout << *this << '\n';
}

template <typename Type>
void Array<Type>::allocate(int capacity) {
  try {
    this->first = {new Type[capacity]};
  }
  catch (const std::bad_alloc& e) {
    std::cout << e.what() << '\n';
    exit(1);
  }
}

template class Array<int>;
