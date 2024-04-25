#ifndef COLA_H
#define COLA_H

#include "Lista.h"

template <class T> class Cola : public Lista<T> {
public:
  Cola() : Lista<T>() {}

  T tope() { return this->cabeza(); }

  bool colavacia() { return this->esvacia(); }

  void encolar(T a) { this->add(a); }

  void desencolar() { this->borrar(); }

  T ultimo() { return this->last(); }

  std::string imprimir(std::string s) { return this->toPrint(s); }

  // Juntar todos los caracteres de la cola en un solo string
  std::string juntar() {
    std::string resultado;
    Cola<T> copia(*this);

    while (!copia.colavacia()) {
      resultado += copia.tope();
      copia.desencolar();
    }

    return resultado;
  }
};

#endif // COLA_H