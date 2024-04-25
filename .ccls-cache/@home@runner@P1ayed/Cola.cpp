#include "Cola.h"

template <class T> Cola<T>::Cola() : Lista<T>() {}

template <class T> T Cola<T>::tope() { return this->last(); }

template <class T> bool Cola<T>::colavacia() { return this->esvacia(); }

template <class T> void Cola<T>::encolar(T a) { this->add(a); }

template <class T> void Cola<T>::desencolar() { this->borrar_last(); }

template <class T> T Cola<T>::ultimo() { return this->cabeza(); }

template <class T> std::string Cola<T>::imprimir(std::string s) {
  return this->toPrint(s);
}
