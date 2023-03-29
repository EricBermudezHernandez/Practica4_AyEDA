#ifndef FUNCIONES_DE_EXPLORACION_H
#define FUNCIONES_DE_EXPLORACION_H

#include <iostream>
#include "funciones_dispersion.hpp"

template <class Key>
class ExplorationFunction {
 public:
  virtual unsigned operator()(const Key& k, unsigned i) const = 0;
};

template <class Key>
class feLineal : public ExplorationFunction<Key> {
 public:
  unsigned operator()(const Key& k, unsigned i) const { return ++i; }
};

template <class Key>
class feCuadratica : public ExplorationFunction<Key> {
 public:
  unsigned operator()(const Key& k, unsigned i) const {return (i*i);}
};

template <class Key>
class feDobleDispersion : public ExplorationFunction<Key> {
 public:
  // Constructor al que se le pasa la función de dispersión f(k) utilizada
  feDobleDispersion(DispersionFunction<Key>* funcion_dispersion) : funcion_dispersion_(funcion_dispersion) {};
  unsigned operator()(const Key& k, unsigned i) const {return ((*funcion_dispersion_)(k) * i);} // f(k) * i
 private:
  //Función de dispersión que inicializamos en el constructor
  DispersionFunction<Key>* funcion_dispersion_;
};

template <class Key>
class feRedispersion : public ExplorationFunction<Key> {
 public:
  unsigned operator()(const Key& k, unsigned i) const;
};

template <class Key>
unsigned feRedispersion<Key>::operator()(const Key& k, unsigned i) const {
  srand(k);
  for (unsigned j{1}; j < i; ++j) {
    rand();
  }
  return rand();
}

#endif
