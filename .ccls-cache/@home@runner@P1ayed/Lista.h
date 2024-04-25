#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
#include <iostream>
#include <sstream>
#include <string>

template <class T> class Lista {
private:
  Nodo<T> *czo;

  void addO(T d, Nodo<T> *ant) {
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

  void borrarD(T d, Nodo<T> *ant) {
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

public:
  Lista() { czo = new Nodo<T>(); }

  Lista(Nodo<T> *n) { czo = n; }

  void add(T d) {
    Nodo<T> *nuevo = new Nodo<T>(d);
    nuevo->set_next(czo);
    czo = nuevo;
  }

  bool esvacia() { return czo->es_vacio(); }

  T cabeza() {
    if (this->esvacia()) {
      std::cout << "Error, Cabeza de lista vacia" << std::endl;
      return T();
    }
    return czo->get_dato();
  }

  Lista *resto() {
    Lista *l = new Lista(czo->get_next());
    return l;
  }

  std::string toPrint(std::string p) {
    if (this->esvacia()) {
      return p;
    } else {
      std::ostringstream stm;
      stm << this->cabeza() << "-" << this->resto()->toPrint(p) << std::endl;
      return stm.str();
    }
  }

  void impre() {
    Nodo<T> *aux = czo;
    while (aux->get_next() != nullptr) {
      std::cout << aux->get_dato() << std::endl;
      aux = aux->get_next();
    }
  }

  T suma(T i) {
    if (this->esvacia()) {
      return i;
    } else {
      return this->resto()->suma(i + this->cabeza());
    }
  }

  int size() {
    if (this->esvacia())
      return 0;
    return 1 + this->resto()->size();
  }

  bool esta(T d) {
    if (this->esvacia())
      return false;
    if (this->cabeza() == d)
      return true;
    return this->resto()->esta(d);
  }

  void borrar() {
    if (!this->esvacia()) {
      Nodo<T> *tmp = czo;
      czo = czo->get_next();
      delete tmp;
    }
  }

  void borrar_last() {
    if (!this->esvacia()) {
      if ((czo->get_next())->get_next() == nullptr) {
        delete czo->get_next();
        czo->set_next(nullptr);
      } else
        this->resto()->borrar_last();
    }
  }

  void concat(Lista<T> *l1) {
    if (!(l1->esvacia())) {
      this->concat(l1->resto());
      this->add(l1->cabeza());
    }
  }

  Lista<T> *copy() {
    Lista<T> *aux = new Lista();
    aux->concat(this);
    return aux;
  }

  void tomar(int n) {
    if (this->size() > n) {
      this->borrar_last();
      this->tomar(n);
    }
  }

  void addOrdenado(T d) { this->addO(d, nullptr); }

  void borrarDato(T d) { this->borrarD(d, nullptr); }
};

#endif // LISTA_H