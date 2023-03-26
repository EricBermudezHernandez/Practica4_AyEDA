#ifndef BLOCK_H
#define BLOCK_H
#include <iostream>

#include "sequence.hpp"

// Para implementar la técnica de dispersión cerrada, donde el número de claves
// sinónimas en cada posición de la tabla hash está acotado por el tamaño del
// bloque, blockSize, se implementa la clase genérica Block<Key> que deriva de
// Sequence<Key>.

template <class Key>
class Block : public Sequence {
 public:

};

#endif