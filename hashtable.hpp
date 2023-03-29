#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>

#include "block.hpp"
#include "funciones_dispersion.hpp"
#include "funciones_exploracion.hpp"
#include "list.hpp"
#include "sequence.hpp"

template <class Key>
class HashTable {
 public:
  // Constructor
  HashTable(int tableSize, DispersionFunction<Key>* funcion_dispersion,
            int blockSize = 0,
            ExplorationFunction<Key>* funcion_exploracion = nullptr);
  bool Search(const Key& k) const;
  bool Insert(const Key& k);

 private:
  int tableSize_;
  int blockSize_;
  std::vector<Sequence<Key>*> table_;
  DispersionFunction<Key>* fd_;
  ExplorationFunction<Key>* fe_;
};

// ==== Constructor ====

template <class Key>
HashTable<Key>::HashTable(int tableSize,
                          DispersionFunction<Key>* funcion_dispersion,
                          int blockSize,
                          ExplorationFunction<Key>* funcion_exploracion) {
  // Inicializamos el tamaño de la tabla
  tableSize_ = tableSize;
  // Asignamos el tamaño del bloque utilizado
  blockSize_ = blockSize;
  // Asignamos la función de dispersión
  fd_ = funcion_dispersion;
  // Asignamos la función de exploración
  fe_ = funcion_exploracion;
  if (fe_ == nullptr) {  // Si se cumple esto, la tabla hash funciona con
                         // dispersión abierta
    table_.resize(tableSize_);
    for (int i{0}; i < table_.size(); ++i) {
      table_[i] = new List<Key>{};
    }
  } else {  // La tabla hash funciona con dispersión cerrada
    table_.resize(tableSize_);
    for (int i{0}; i < table_.size(); ++i) {
      table_[i] = new Block<Key>{blockSize_};
    }
  }
}

// Este método accede al método de la clase correspondiente, dependiendo si
// estamos trabajando con dispersión abierta o cerrada y busca el elemento por
// su clave "k"
template <class Key>
bool HashTable<Key>::Search(const Key& k) const {
  unsigned index = (*fd_)(k);
  if ((*table_[index]).Search(k)) {
    std::cout << "El elemento se encuentra en la posición: " << index
              << std::endl;
    return true;
  } else {
    int attempt = 0;
    while (attempt < tableSize_) {
      index = (*fe_)(k, index) % tableSize_;
      if (index < tableSize_) {
        (*table_[index]).Search(k);
        std::cout << "El elemento se encuentra en la posición: " << index
                  << std::endl;
        return true;
      }
      attempt++;
    }
  }
  return false;
}

// Este método accede al método de la clase correspondiente, dependiendo si
// estamos trabajando con dispersión abierta o cerrada e inserta si puede, el
// elemento por su clave "k"
template <class Key>
bool HashTable<Key>::Insert(const Key& k) {
  unsigned index = (*fd_)(k);
  if (!(*table_[index]).Insert(k)) {
    int attempt = 0;
    while (attempt < tableSize_) {
      index = ((*fe_)(k, index)) % tableSize_;
      if (index < tableSize_) {
        (*table_[index]).Insert(k);
        return true;
      }
      attempt++;
    }
    return false; // Si salimos del while y del if, es que no se pudo meter el elemento, por lo que devolvemos false
  }
  return false;
}
#endif
