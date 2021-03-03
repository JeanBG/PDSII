#include "Ponto4D.hpp"

std::string Ponto4D::to_string() const
{
    return "(" + std::to_string(this->_x) + "," + std::to_string(this->_y) +
           "," + std::to_string(this->_z) + "," + std::to_string(this->_w) + ")";
}

double Ponto4D::distancia(Ponto *p) const
{
    Ponto4D *p4 = dynamic_cast<Ponto4D *>(p);
    return sqrt(pow(this->_x - p4->getX(), 2) + pow(this->_y - p4->getY(), 2) +
                pow(this->_z - p4->getZ(), 2) + pow(this->_w - p4->getW(), 2));
}