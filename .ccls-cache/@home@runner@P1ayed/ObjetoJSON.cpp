#include "ObjetoJSON.h"
#include <fstream>
#include <iostream>
using namespace std;

bool ObjetoJSON::procesarCaracter(ifstream &file) {
  int llaves_abiertas = 0;
  int llaves_cerradas = 0;
  char ch;
  while (file >> std::noskipws >> ch) {
    if (ch == '{') {
      llaves_abiertas++;
    } else if (ch == '}') {
      llaves_cerradas++;
    }
  }
  return llaves_abiertas == llaves_cerradas;
}