#ifndef CIRCUNFERENCIA_H
#define CIRCIUNFERENCIA_H

#include <cmath>

struct Circunferencia
{
    double _xc, _yc;
    double _raio;

    Circunferencia(double, double, double);
    double calcularArea();
    bool possuiIntersecao(Circunferencia *);
};

#endif