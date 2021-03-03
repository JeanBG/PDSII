#include "Indice.hpp"
#include <string>

float Palavra::calcularPercentual(int contagem)
{
    return (float)ocorrencias / (float)contagem;
}

bool compara_palavra::operator()(const std::string &p1, const std::string &p2) const
{
    return p1 < p2;
}