#ifndef OBJETOJSON_H
#define OBJETOJSON_H
#include <fstream>

class ObjetoJSON {
public:
  bool procesarCaracter(std::ifstream &file);
};

#endif // OBJETOJSON_H