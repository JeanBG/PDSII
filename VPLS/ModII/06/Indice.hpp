#ifndef INDICE_H
#define INDICE_H

#include <string>

struct Palavra
{
    int ocorrencias;

    float calcularPercentual(int);
};

struct compara_palavra
{
    bool operator()(const std::string &p1, const std::string &p2) const;
};

#endif