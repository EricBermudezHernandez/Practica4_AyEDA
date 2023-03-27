#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include "sequence.hpp"
#include "funciones_dispersion.hpp"
#include "funciones_exploracion.hpp"
#include "list.hpp"
#include "block.hpp"

template <class Key>
class HashTable {
 public:
  // Constructor
  HashTable(int tableSize, DispersionFunction<Key>* funcion_dispersion, int blockSize = 0 ,ExplorationFunction<Key>* funcion_exploracion = nullptr);
  bool Search(const Key& k) const;
  bool Insert(const Key& k);
 private:
  int tableSize_;
  int blockSize_;
  Sequence<Key>* table_;
  DispersionFunction<Key>* fd_;
  ExplorationFunction<Key>* fe_;
};

// ==== Constructor ====

template <class Key>
HashTable<Key>::HashTable(int tableSize, DispersionFunction<Key>* funcion_dispersion, int blockSize,ExplorationFunction<Key>* funcion_exploracion) {
  // Inicializamos el tamaño de la tabla
  tableSize_ = tableSize;
  // Asignamos el tamaño del bloque utilizado
  blockSize_ = blockSize;
  // Asignamos la función de dispersión
  fd_ = funcion_dispersion; 
  // Asignamos la función de exploración
  fe_ = funcion_exploracion; 
  if (fe_ == nullptr) { // Si se cumple esto, la tabla hash funciona con dispersión abierta
    table_ = new List<Key>[tableSize_];
  } else { // La tabla hash funciona con dispersión cerrada
    table_ = new Block<Key>[tableSize_];
    // Vamos iterando por cada celda de la tabla, asignandole a cada una un objeto de tipo block de tamaño blocksize
    for (int i{0}; i < tableSize_; ++i) {
      table_[i] = Block<Key>{blockSize_};
    }
  }
}

// Este método accede al método de la clase correspondiente, dependiendo si estamos trabajando con dispersión abierta o cerrada y busca el elemento por su clave "k"
template <class Key>
bool HashTable<Key>::Search(const Key& k) const {
  return (table_->Search(k));
}

// Este método accede al método de la clase correspondiente, dependiendo si estamos trabajando con dispersión abierta o cerrada e inserta si puede, el elemento por su clave "k"
template <class Key>
bool HashTable<Key>::Insert(const Key& k) {
  return (table_->Insert(k));
}
#endif
