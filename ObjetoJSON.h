#ifndef OBJETOJSON_H
#define OBJETOJSON_H
#include <fstream>

class ObjetoJSON {
public:
  bool procesarCaracter(std::ifstream &file);
  bool detectarErroresEspacios(const std::string partecita);
};

#endif // OBJETOJSON_H