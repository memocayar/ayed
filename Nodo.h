#ifndef NODO_H
#define NODO_H

template <class T> class Nodo {
private:
  T dato;
  Nodo *next;

public:
  Nodo() { next = nullptr; }
  Nodo(T a) {
    dato = a;
    next = nullptr;
  }
  void set_dato(T a) { dato = a; }
  void set_next(Nodo *n) { next = n; }
  T get_dato() { return dato; }
  Nodo *get_next() { return next; }
  bool es_vacio() { return next == nullptr; }
};

#endif // NODO_H