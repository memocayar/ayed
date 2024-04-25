#ifndef PILA_H
#define PILA_H

#include "Lista.h"

template <class T> class Pila : public Lista<T> {
public:
  Pila() : Lista<T>() {}

  void apilar(T d) { this->add(d); }

  T tope() { return this->cabeza(); }

  void desapilar() { this->borrar(); }

  bool pilavacia() { return this->esvacia(); }
};

#endif // PILA_H