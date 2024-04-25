#include "Lista.h"
#include <iostream>
#include <sstream>

template <class T> Lista<T>::Lista() { czo = new Nodo<T>(); }

template <class T> Lista<T>::Lista(Nodo<T> *n) { czo = n; }

template <class T> void Lista<T>::add(T d) {
  Nodo<T> *nuevo = new Nodo<T>(d);
  nuevo->set_next(czo);
  czo = nuevo;
}

template <class T> bool Lista<T>::esvacia() { return czo->es_vacio(); }

template <class T> T Lista<T>::() {
  if (this->esvacia()) {
    std::cout << "Error, Cabeza de lista vacia" << std::endl;
    return T();
  }
  return czo->get_dato();
}

template <class T> Lista<T> *Lista<T>::resto() {
  Lista *l = new Lista(czo->get_next());
  return l;
}

template <class T> std::string Lista<T>::toPrint(std::string p) {
  if (this->esvacia()) {
    return p;
  } else {
    std::ostringstream stm;
    stm << this->cabeza() << "-" << this->resto()->toPrint(p) << std::endl;
    return stm.str();
  }
}

template <class T> void Lista<T>::impre() {
  Nodo<T> *aux = czo;
  while (aux->get_next() != nullptr) {
    std::cout << aux->get_dato() << std::endl;
    aux = aux->get_next();
  }
}

template <class T> T Lista<T>::suma(T i) {
  if (this->esvacia()) {
    return i;
  } else {
    return this->resto()->suma(i + this->cabeza());
  }
}

template <class T> int Lista<T>::size() {
  if (this->esvacia())
    return 0;
  return 1 + this->resto()->size();
}

template <class T> bool Lista<T>::esta(T d) {
  if (this->esvacia())
    return false;
  if (this->cabeza() == d)
    return true;
  return this->resto()->esta(d);
}

template <class T> void Lista<T>::borrar(void) {
  if (!this->esvacia()) {
    Nodo<T> *tmp = czo;
    czo = czo->get_next();
    delete tmp;
  }
}

template <class T> void Lista<T>::borrar_last() {
  if (!this->esvacia()) {
    if ((czo->get_next())->get_next() == nullptr) {
      delete czo->get_next();
      czo->set_next(nullptr);
    } else
      this->resto()->borrar_last();
  }
}

template <class T> void Lista<T>::concat(Lista<T> *l1) {
  if (!(l1->esvacia())) {
    this->concat(l1->resto());
    this->add(l1->cabeza());
  }
}

template <class T> Lista<T> *Lista<T>::copy(void) {
  Lista<T> *aux = new Lista();
  aux->concat(this);
  return aux;
}

template <class T> void Lista<T>::tomar(int n) {
  if (this->size() > n) {
    this->borrar_last();
    this->tomar(n);
  }
}

template <class T> void Lista<T>::addO(T d, Nodo<T> *ant) {
  if (this->esvacia()) {
    this->add(d);
  } else {
    if (d < czo->get_dato()) {
      if (ant == nullptr) {
        this->add(d);
      } else {
        Nodo<T> *nuevo = new Nodo<T>(d);
        nuevo->set_next(ant->get_next());
        ant->set_next(nuevo);
      }
    } else {
      if ((czo->get_next())->get_next() == nullptr) {
        Nodo<T> *nuevo = new Nodo<T>(d);
        nuevo->set_next(czo->get_next());
        czo->set_next(nuevo);
      } else
        this->resto()->addO(d, czo);
    }
  }
}

template <class T> void Lista<T>::borrarD(T d, Nodo<T> *ant) {
  if (!this->esvacia()) {
    if (d == this->cabeza()) {
      if (ant == nullptr) {
        this->borrar();
      } else {
        ant->set_next(czo->get_next());
        delete czo;
      }
    } else
      this->resto()->borrarD(d, czo);
  }
}