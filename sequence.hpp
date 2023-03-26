#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>

template<class Key>
class Sequence {
 public:  
  bool Search(const Key& k) const = 0;
  bool Insert(const Key& k) = 0;
  bool IsFull() const = 0;
};

#endif
