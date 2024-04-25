#include "ClaveString.h"
#include "ClaveValor.h"
#include "Cola.h"
#include "ObjetoJSON.h"
#include "Pila.h"
#include <fstream>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

enum opcionTipoValor { tipoString, tipoListaString, tipoJson, otro };

opcionTipoValor evaluarTipo(char c) {
  switch (c) {
  case '"':
    return opcionTipoValor::tipoString;
    break;
  case '[':
    return opcionTipoValor::tipoListaString;
    break;
  case '{':
    return opcionTipoValor::tipoJson;
    break;
  default:
    return opcionTipoValor::otro;
  }
}

void evaluarPartecita(Cola<char> &partecita, opcionTipoValor tipoValor,
                      int pos) {
  ClaveString claveString;
  ClaveValor claveValor;
  ObjetoJSON objetoJSON;

  string partecitaString = partecita.juntar();

  if (claveValor.validarComillasSimples(partecitaString)) {
    cout << "Error: se encontraron comillas simples en la posición " << pos
         << ": " << partecitaString << endl;
  }
  if (objetoJSON.detectarErroresEspacios(partecitaString)) {
    cout << "Error: se encontraron espacios en la posición: " << pos << ": "
         << partecitaString << endl;
  }

  while (!partecita.colavacia()) {
    char caracter = partecita.tope();

    switch (tipoValor) {
    case tipoString:
      claveString.procesarCaracter(caracter);
      break;

    case tipoListaString:

      break;

    case tipoJson:
      break;

    case otro:
      cout << "Error al encontrar el tipo de dato luego de la clave en la "
              "posición :"
           << pos << endl;
      break;

    default:
      cout << "Error al encontrar el tipo de dato luego de la clave en la "
              "posición :"
           << pos << endl;
    }

    partecita.desencolar();
  }
}

void procesarTexto(string &texto, int &pos) {
  Cola<char> partecita;
  bool evaluarTipoValor;
  opcionTipoValor tipoValor;

  // se recorrre caracter por caracter el json
  for (; pos < texto.length(); pos++) {
    char ch = texto[pos];

    if (ch != ' ' && ch != '\n' && ch != '\t') {

      // encontrar tipo de valor
      evaluarTipoValor =
          (ch == ':') ? true : false; // si el caracter es : -> encuentro el
                                      // tipo de valor en el proximo caracter
      tipoValor = evaluarTipoValor ? evaluarTipo(ch)
                                   : tipoValor; // si corresponde (estoy despues
                                                // de :), evaluar tipo de valor

      // TODO: CONSIDERAR SEPARACIÓN DE LAS LISTAS

      if (ch == ',' &&
          !partecita
               .colavacia()) { // si se encuentra una coma terminó una partecita
        evaluarPartecita(partecita, tipoValor, pos);

      } else if (ch == '{') { // si se encuentra un { se evalua el json anidado
        evaluarPartecita(partecita, tipoValor, pos);
        pos++;
        procesarTexto(texto,
                      pos); // llamada recursiva para manejar subexpresiones

      } else if (ch == '}') {
        evaluarPartecita(partecita, tipoValor, pos);
        return; // Retorna de la recursión;
      } else {
        partecita.encolar(ch);
      }
    }
  }

  // Verificar al final del texto
  if (!partecita.colavacia()) {
    evaluarPartecita(partecita, tipoValor, pos);
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

  ObjetoJSON json;

  if (json.procesarCaracter(inputFile) == true) {
    int pos = 0;
    procesarTexto(contenidoJson, pos);
  } else {
    cout << "Error en el JSON. Faltan o sobran llaves";
  }

  // Cerrar el archivo de entrada
  inputFile.close();
  return 0;
}
