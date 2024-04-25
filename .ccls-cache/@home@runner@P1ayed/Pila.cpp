#include "Pila.h"

template <class T> Pila<T>::Pila() : Lista<T>() { Lista<T>(); }

template <class T> void Pila<T>::apilar(T d) { this->add(d); }

template <class T> T Pila<T>::tope() { return this->cabeza(); }

template <class T> void Pila<T>::desapilar() { this->borrar(); }

template <class T> bool Pila<T>::pilavacia() { return this->esvacia(); }
