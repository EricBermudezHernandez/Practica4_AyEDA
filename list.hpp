#ifndef LIST_H
#define LIS_H
#include <iostream>
#include <list>

#include "sequence.hpp"
// Para implementar la técnica de dispersión abierta, donde todos los valores de
// clave sinónimos se almacenan en la misma posición de la tabla hash, se
// implementa la clase genérica List<Key> que deriva de Sequence<Key>.

template <class Key>
class List : public Sequence<Key> {
 public:
  // Constructor por defecto
  List() = default;
  bool Search(const Key& k) const;
  bool Insert(const Key& k);
  bool IsFull() const;

 private:
  std::list<Key> lista_; // Lista enlazada que sirve para meter todos los elementos en la tabla
};

// ==== Métodos heredados ====

template <class Key>
bool List<Key>::Search(const Key& k) const {
  int posicion{0};
  // Recorremos la lista entera, si encontramos el elemento devolvemos que lo hemos encontrado con un "true"
  for (auto& elemento : lista_) {
    posicion++;
    if (elemento == k) {
      std::cout << "El elemento se encuentra en la posición: " << posicion << std::endl;
      return true;
    }
  }
  std::cout << "El elemento no se encuentra en la secuencia" << std::endl;
  return false; // No hemos encontrado el elemento
}

template <class Key>
bool List<Key>::Insert(const Key& k) {
  //Si no existe el elemento en la lista de sinonimos de la posición correspondiente de la tabla hash, se añade al final
  if (!Search(k)) {
    lista_.push_back(k); // Se añade el elemento al final de la lista
    std::cout << "El elemento se pudo insertar correctamente en la secuencia" << std::endl;
    return true;
  }
  std::cout << "No se pudo insertar el elemento en la secuencia" << std::endl;
  return false; // No se ha podido añadir el elemento en la lista
}

// Este método en el caso de la dispersión abierta, siempre nos va a dar false,
// debido a que en las listas siempre se van a poder insertar elementos sin una
// limitación de espacio
template <class Key>
bool List<Key>::IsFull() const {
  return false;
}

#endif
