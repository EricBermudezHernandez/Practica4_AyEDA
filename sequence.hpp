#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>

template<class Key>
class Sequence {
 public:  
  virtual bool Search(const Key& k) const = 0;
  virtual bool Insert(const Key& k) = 0;
  virtual bool IsFull() const = 0;
};

#endif
