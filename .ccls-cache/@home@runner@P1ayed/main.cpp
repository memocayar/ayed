#include "ClaveValor.h"
#include "Cola.h"
#include "ObjetoJSON.h"
#include "Pila.h"
#include <fstream>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// ClaveValor clavevalor;
// Pila<char> miPila;

bool validarComillasSimples(const string &partecita) {
  for (char ch : partecita) {
    if (ch == '\'') { // Detecta comillas simples
      return true;    // Retorna true si encuentra comillas simples
    }
  }
  return false; // Retorna false si no hay comillas simples
}

bool detectarErroresEspacios(const std::string partecita) {
  std::stack<char> espacioPila;

  for (char ch : partecita) {
    if (ch == ' ') {
      // Si el carácter es un espacio, lo apilamos
      espacioPila.push(ch);
      return true;
    } else {
      // Si el carácter no es un espacio, vaciamos la pila
      while (!espacioPila.empty()) {
        espacioPila.pop();
      }
    }
  }

  // Si llegamos aquí, no se encontraron errores
  return false;
}

void procesarTexto(string &texto, size_t &pos) {
  string partecita;
  for (; pos < texto.length(); pos++) {
    char ch = texto[pos];
    if (ch == ',' && !partecita.empty()) {
      if (validarComillasSimples(partecita)) {
        cout << "Error: se encontraron comillas simples en la posición " << pos
             << ": " << partecita << endl;
      }
      if (detectarErroresEspacios(partecita)) {
        cout << "Error: se encontraron espacios en la posición: " << pos << ": "
             << partecita << endl;
      }
      partecita.clear();
    } else if (ch == '{') {
      if (validarComillasSimples(partecita)) {
        cout << "Error: se encontraron comillas simples en la posición " << pos
             << ": " << partecita << endl;
      }
      if (detectarErroresEspacios(partecita)) {
        cout << "Error: se encontraron espacios en la posición: " << pos << ": "
             << partecita << endl;
      }
      partecita.clear();
      pos++;
      procesarTexto(texto,
                    pos); // Llamada recursiva para manejar subexpresiones
    } else if (ch == '}') {
      if (validarComillasSimples(partecita)) {
        cout << "Error: se encontraron comillas simples en la posición " << pos
             << ": " << partecita << endl;
      }
      if (detectarErroresEspacios(partecita)) {
        cout << "Error: se encontraron espacios en la posición: " << pos << ": "
             << partecita << endl;
      }
      return; // Retorna de la recursión
    } else {
      partecita.push_back(ch);
    }
  }
  // Verificar al final del texto
  if (!partecita.empty() && validarComillasSimples(partecita)) {
    cout << "Error: se encontraron comillas simples en la posición " << pos
         << ": " << partecita << endl;
  }
}

int main() {
  string ruta = "entrada.json";
  ifstream inputFile(ruta);
  string contenidoJson;

  if (inputFile.is_open()) {
    cout << "Se abrio el archivo correctamente" << endl;

    contenidoJson.assign((istreambuf_iterator<char>(inputFile)),
                         (istreambuf_iterator<char>()));
  } else {
    cout << "No se pudo abrir el archivo de entrada." << endl;
    return 1;
  }

  // ObjetoJSON json;

  // if (json.procesarCaracter(inputFile) == true){

  // }
  // else {
  //     cout<<"Error en el JSON. Faltan o sobran llaves";
  // }

  size_t pos = 0;
  stack<char> pila;
  procesarTexto(contenidoJson, pos);

  // Cerrar el archivo de entrada
  inputFile.close();
  return 0;
}
