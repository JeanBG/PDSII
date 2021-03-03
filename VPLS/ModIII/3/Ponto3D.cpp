#include "Ponto3D.hpp"

std::string Ponto3D::to_string() const
{
    return "(" + std::to_string(this->_x) + "," + std::to_string(this->_y) + "," + std::to_string(this->_z) + ")";
}

double Ponto3D::distancia(Ponto *p) const
{
    Ponto3D *p3 = dynamic_cast<Ponto3D *>(p);
    return sqrt(pow(this->_x - p3->getX(), 2) + pow(this->_y - p3->getY(), 2) + pow(this->_z - p3->getZ(), 2));
}