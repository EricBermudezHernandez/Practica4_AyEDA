#ifndef BLOCK_H
#define BLOCK_H
#include <iostream>
#include <vector>

#include "sequence.hpp"

// Para implementar la técnica de dispersión cerrada, donde el número de claves
// sinónimas en cada posición de la tabla hash está acotado por el tamaño del
// bloque, blockSize, se implementa la clase genérica Block<Key> que deriva de
// Sequence<Key>.

template <class Key>
class Block : public Sequence<Key> {
 public:
  //Constructores
  Block();
  Block(int size);
  bool Search(const Key& k) const;
  bool Insert(const Key& k);
  bool IsFull() const;
 private:
  int blockSize_;
  int numero_elementos_;
  std::vector<Key> block_;
};

// ==== Constructores ====
template <class Key>
Block<Key>::Block() {
  // Si no nos especifican el tamaño, por defecto será uno
  numero_elementos_ = 0;
  blockSize_ = 1;
}

template <class Key>
Block<Key>::Block(int size) {
  numero_elementos_ = 0; // El número de elementos empieza en 0
  blockSize_ = size;
  block_.reserve(size); // Reservamos los espacios de memoria que nos indican en el vector
}

// ==== Métodos heredados ====

template <class Key>
bool Block<Key>::Search(const Key& k) const {
  for (auto& elementos : block_) {
    if (elementos == k) {
      return true; // Hemos encontrado el elemento, retornamos "true"
    }
  }
  return false; // No hemos encontrado el elemento, retornamos "false"
}

template <class Key>
bool Block<Key>::Insert(const Key& k) {
  // Comprobamos si se puede introducir el elemento
  if (!IsFull() && !Search(k)) { // Si no está lleno y no se encuentra en el bloque, se introduce
    numero_elementos_++; // Se añade un elemento más 
    block_.push_back(k); // Metemos el elemento en el vector
    return true; // Se pudo introducir el elemento, retornamos "true"
  }
  return false; // No se pudo introducir el elemento, retornamos "false"
}

template <class Key>
bool Block<Key>::IsFull() const {
  // Si el número de elementos actual es igual al tamaño total, es que está lleno el bloque
  if (numero_elementos_ == blockSize_) { 
    return true;
  }
  return false; // El bloque todavía no está lleno, retornamos "false"
}
#endif
