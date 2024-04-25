#ifndef CLAVEVALOR_H
#define CLAVEVALOR_H

#include "Pila.h"

using namespace std;

class ClaveValor {
public:
  // virtual asi puede ser sobreescrita por las clases hijas
  virtual void procesarCaracter(char c);

  void procesarClave(char c, Pila<char> &pila);
  bool validarComillasSimples(string &partecita);
};

#endif // CLAVEVALOR_H