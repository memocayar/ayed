#include "ClaveValor.h"
#include "Pila.h"
#include <iostream>

using namespace std;

void ClaveValor::procesarClaveValor(char c, Pila<char> &pila) {
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
