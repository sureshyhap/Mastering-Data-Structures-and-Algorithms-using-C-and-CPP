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

/////////////////////////////

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
void Array<Type>::print() const {
  std::cout << *this << '\n';
}

template <typename Type>
void Array<Type>::allocate(int capacity) {
  try {
    this->first = {new Type[capacity]};
    if (this->first == nullptr) {
      throw std::runtime_error("No more memory");
    }
  }
  catch (const std::runtime_error& e) {
    std::cout << e.what() << '\n';
    exit(1);
  }
}

template class Array<int>;
