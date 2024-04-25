#include "ObjetoJSON.h"
#include "Pila.h"
#include <fstream>
#include <iostream>
using namespace std;

// Valida que el archivo de entrada sea un JSON válido
// -> empieza con { y termina con }
bool ObjetoJSON::procesarCaracter(ifstream &file) {
  int llaves_abiertas = 0;
  int llaves_cerradas = 0;
  char ch;
  while (file >> std::noskipws >> ch) {
    if (ch == '{') {
      llaves_abiertas++;
    } else if (ch == '}') {
      llaves_cerradas++;
    }
  }
  return llaves_abiertas == llaves_cerradas;
}

bool ObjetoJSON::detectarErroresEspacios(const std::string partecita) {
  Pila<char> espacioPila;

  for (char ch : partecita) {
    if (ch == ' ') {
      // Si el carácter es un espacio, lo apilamos
      espacioPila.apilar(ch);
      return true;
    } else {
      // Si el carácter no es un espacio, vaciamos la pila
      while (!espacioPila.pilavacia()) {
        espacioPila.desapilar();
      }
    }
  }

  // Si llegamos aquí, no se encontraron errores
  return false;
}