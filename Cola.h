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
};

#endif // COLA_H