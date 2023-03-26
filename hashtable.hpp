#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include "sequence.hpp"
#include "funciones_dispersion.hpp"
#include "funciones_exploracion.hpp"

template <class Key>
class HashTable {
 public:
  // Constructor
  HashTable(int tableSize, DispersionFunction<Key>* funcion_dispersion, int blockSize = 0 ,ExplorationFunction<Key>* funcion_exploracion = nullptr);
  bool Search(const key& k) const;
  bool Insert(const Key& k);
 private:
  int tableSize_;
  int blockSize_;
  Sequence<Key> table_[];
  DispersionFunction<Key>* fd_;
  ExplorationFunction<Key>* fe_;
};

template <class Key>
HashTable<Key>::HashTable(int tableSize, DispersionFunction<Key>* funcion_dispersion, int blockSize = 0 ,ExplorationFunction<Key>* funcion_exploracion = nullptr) {
  // Inicializamos el tamaño de la tabla
  tableSize_ = tableSize;
  table_[tableSize_];
  fd_ = funcion_dispersion;
  if (funcion_exploracion == nullptr) {
    
  }
}

#endif