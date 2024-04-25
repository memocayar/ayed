#ifndef CLAVESTRING_H
#define CLAVESTRING_H

#include "ClaveValor.h"
#include "Pila.h"

using namespace std;

class ClaveString : public ClaveValor {
public:
  // Nueva implementación de procesarClave específica para ClaveString
  void procesarCaracter(char c) override;
};

#endif // CLAVESTRING_H
