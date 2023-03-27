#include <iostream>
#include "hashtable.hpp"

int main() {
  int tableSize, eleccion, eleccion_funcion_exploracion, blockSize;
  std::cout << "Introduce el tamaño de la tabla: ";
  std::cin >> tableSize;
  std::cout << "Introduce la función de dispersión\n 1) Módulo\n 2) Basada en la suma\n 3) Pseudoaleatoria\n";
  std::cin >> eleccion;
  DispersionFunction<long>* funcion_dispersion;
  // Se escoge la función de dispersión:
  switch (eleccion) {
  case 1:  // Se ha elegido la función de dispersión del módulo
    funcion_dispersion = new fdModule<long> {tableSize};
    break;
  

  case 2:  // Se ha elegido la función de dispersión de la suma
    funcion_dispersion = new fdSum<long> {tableSize};
    break;
  
    
  case 3: 
    funcion_dispersion = new fdPseudoRandom<long> {tableSize};
    break;
  
  default:
    std::cout << "Opción: " << eleccion << " incorrecta" << std::endl;
    exit(1);
    break;
  }
  std::cout << "Introduce la técnica de dispersión\n 1) Abierta\n 2) Cerrada\n";
  std::cin >> eleccion;
  HashTable<long>* hash_table;
  // Se escoge la técnica de dispersión
  switch (eleccion) {
    case 1: { // Se ha elegido la técnica de dispersión abierta
      // Se crea una tabla hash usando la técnica de dispersión abierta usando los parámetros por defecto
      hash_table = new HashTable<long>{tableSize, funcion_dispersion};
      break;
    }
    case 2: { // Se ha elegido la técnica de dispersión cerrada
      std::cout << "Introduce el tamaño del bloque: ";
      std::cin >> blockSize;
      std::cout << "Introduce la función de exloración\n 1) Exploración lineal\n 2) Exploración cuadrática\n 3) Doble dispersión\n 4) Redispersión\n";
      std::cin >> eleccion_funcion_exploracion;
      ExplorationFunction<long>* funcion_exploracion; // Función de exploración
      // Escogemos la función de exploración
      switch (eleccion_funcion_exploracion) {
      case 1: // Se ha escogido la función de exploración lineal
        funcion_exploracion = new feLineal<long>{};
        break;
      case 2: // Se ha escogido la función de exploración cuadrática
        funcion_exploracion = new feCuadratica<long>{};
        break;
      case 3: // Se ha escogido la función de exploración de doble dispersión
        funcion_exploracion = new feDobleDispersion<long>{funcion_dispersion};
        break;
      case 4: // Se ha escogido la función de exploración de Redispersión
        funcion_exploracion = new feRedispersion<long>{};
        break;
      default:
        std::cout << "Opción: " << eleccion_funcion_exploracion << " incorrecta" << std::endl;
        exit(1);
        break;
      }
      hash_table = new HashTable<long>{tableSize, funcion_dispersion, blockSize, funcion_exploracion};
      break; // Fin case 2
  }
  default:
    std::cout << "Opción: " << eleccion << " incorrecta" << std::endl;
    exit(1);
    break;
  }
  
  // Menú:
  std::cout << "Selecciona una opción:\n 1) Insertar\n 2) Buscar\n 3) Salir\n";
  std::cin >> eleccion;
  long elemento;
  do {
  switch (eleccion) {
  case 1: // Se ha escogido la función de insertar
    std::cout << "Introduce el valor del elemento a insertar: ";
    std::cin >> elemento;
    hash_table->Insert(elemento);
    break;
  case 2: // Se ha escogido la función de buscar
    std::cout << "Introduce el valor que quieres buscar: ";
    std::cin >> elemento;
    hash_table->Search(elemento);
    break;
  default:
    std::cout << "Opción: " << eleccion << " incorrecta" << std::endl;
    exit(1);
    break;
  }
  std::cout << "Selecciona una opción:\n 1) Insertar\n 2) Buscar\n 3) Salir\n";
  std::cin >> eleccion;
  } while (eleccion != 3);
  std::cout << "Fin del programa" << std::endl;
  return 0;
}
