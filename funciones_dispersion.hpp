#ifndef FUNCIONES_DE_DISPERSION_H
#define FUNCIONES_DE_DISPERSION_H

#include <iostream>
#include <cstdlib>

template <class Key>
class DispersionFunction {
 public:
  virtual unsigned operator()(const Key& k) const = 0;
};

template <class Key>
class fdModule : public DispersionFunction<Key> {
 public:
  fdModule(const unsigned n) : tableSize_(n) {}
  unsigned operator()(const Key& k) const { return k % tableSize_; }

 private:
  unsigned tableSize_;
};

template <class Key>
class fdSum : public DispersionFunction<Key> {
 public:
  fdSum(const unsigned n) : tableSize_(n) {}
  unsigned operator()(const Key& k) const;
 private:
  unsigned tableSize_;
};

template <class Key>
class fdPseudoRandom : public DispersionFunction<Key> {
 public:
  fdPseudoRandom(const unsigned n) : tableSize_(n) {}
  unsigned operator()(const Key& k) const;
 private:
  unsigned tableSize_;
};

// Función de dispersión de tipo suma
template <class Key>
unsigned fdSum<Key>::operator()(const Key& k) const {
  unsigned suma{0};
  long aux{k};
  while (k > 0) {
    suma += aux % 10;
    aux /= 10;
  }
  // Después de sumar todos los dígitos del número le hacemos el módulo con el tamaño de la tabla hash
  return (suma % tableSize_);
}

// Función de dispersión de números Pseudo-aleatorios
template <class Key>
unsigned fdPseudoRandom<Key>::operator()(const Key& k) const {
  srand(k);
  return rand() % tableSize_;
}

#endif
