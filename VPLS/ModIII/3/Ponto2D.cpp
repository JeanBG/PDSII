#include "Ponto2D.hpp"

std::string Ponto2D::to_string() const
{
    return "(" + std::to_string(this->_x) + "," + std::to_string(this->_y) + ")";
}

double Ponto2D::distancia(Ponto *p) const
{
    Ponto2D *p2 = dynamic_cast<Ponto2D *>(p);
    return sqrt(pow(this->_x - p2->getX(), 2) + pow(this->_y - p2->getY(), 2));
}

void Ponto2D::converteParaPolar()
{
    double r = sqrt(pow(this->_x, 2) + pow(this->_y, 2));
    double theta = atan(this->_y / this->_x);

    this->_x = r;
    this->_y = theta;
}