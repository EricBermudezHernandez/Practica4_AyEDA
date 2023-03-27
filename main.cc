#include <iostream>
#include "hashtable.hpp"

int main() {
  unsigned int tableSize, eleccion_funcion_dispersion;
  std::cout << "Introduce el tamaño de la tabla: ";
  std::cin >> tableSize;
  std::cout << "Introduce la función de dispersión\n 1) Módulo\n 2) Basada en la suma\n 3) Pseudoaleatoria\n";
  std::cin >> eleccion_funcion_dispersion;
  switch (eleccion_funcion_dispersion) {
  case 1: { // Se ha elegido la función de dispersión del módulo
    fdModule<long> fd{tableSize};
    break;
  }

  case 2: { // Se ha elegido la función de dispersión de la suma
    fdSum<long> fd{tableSize};
    break;
  }
    
  case 3: {
    fdPseudoRandom<long> fd{tableSize};
    break;
  }
  default:
    break;
  }
  return 0;
}