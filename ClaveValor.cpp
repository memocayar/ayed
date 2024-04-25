#include "ClaveValor.h"
#include "Pila.h"
#include <iostream>

using namespace std;

// (no se está usando)
void ClaveValor::procesarClave(char c, Pila<char> &pila) {
  if (c == ',') {
    while (!pila.pilavacia()) {
      if (pila.tope() == '\'') {
        std::cout << "Error: comilla simple" << std::endl;
        // Cuando encuentra una comilla simple, hace un break y vacía la pila
        while (!pila.pilavacia())
          pila.desapilar();
        break;
      } else {
        pila.desapilar();
      }
    }
  } else {
    pila.apilar(c);
  }
}

bool ClaveValor::validarComillasSimples(string &partecita) {
  for (char ch : partecita) {
    if (ch == '\'') { // Detecta comillas simples
      return true;    // Retorna true si encuentra comillas simples
    }
  }
  return false; // Retorna false si no hay comillas simples
}