#include "Circunferencia.hpp"

Circunferencia::Circunferencia(double xc, double yc, double raio)
{
    _xc = xc;
    _yc = yc;
    _raio = raio;
}

double Circunferencia::calcularArea()
{
    return 3.14 * pow(_raio, 2);
}

bool Circunferencia::possuiIntersecao(Circunferencia *c)
{
    double temp = sqrt(pow(this->_xc - c->_xc, 2) + pow(this->_yc - c->_yc, 2));
    double sum = this->_raio + c->_raio;
    if (temp > sum)
        return 0;
    else
        return 1;
}