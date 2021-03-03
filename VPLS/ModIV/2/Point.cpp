#include <iostream>

#include "Point.h"

std::ostream &operator<<(std::ostream &out, const Point &p)
{
  // TODO: implement this operator.
  return out << "(" << p.x << ", " << p.y << ")";
}

std::istream &operator>>(std::istream &in, Point &p)
{
  // TODO: implement this operator.
  in >> p.x >> p.y;
  return in;
}

Point Point::operator+(const Point &p)
{
  // TODO: implement this operator.
  Point hold(x + p.x, y + p.y);
  return hold;
}

Point &Point::operator+=(const Point &p)
{
  // TODO: implement this operator.
  x += p.x;
  y += p.y;
  return *this;
}