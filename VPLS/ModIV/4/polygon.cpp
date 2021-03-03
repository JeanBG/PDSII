/**
 * Todas as tarefas deste exercicio devem ser feitas sobre esse arquivo.
 * Os metodos e operacoes marcados com a tag "TODO" devem ser editados.
 */

#include <iostream>
#include "polygon.h"

std::ostream &operator<<(std::ostream &out, const Polygon &poly)
{
  for (const Point &p : poly.limits)
  {
    out << " " << p;
  }
  return out;
}

bool operator==(const Polygon &lhs, const Polygon &rhs)
{
  // TODO: implement this method.
  std::vector<Point> left(lhs);
  std::vector<Point> right(rhs);
  int size = left.size() < right.size() ? left.size() : right.size();
  int count = 0;
  for (auto i : left)
  {
    for (auto j : right)
    {
      if (i == j)
      {
        count++;
        break;
      }
    }
  }
  return count == size;
}

bool Point::contains(const Point &p) const
{
  return p.x == this->x && p.y == this->y;
}

std::ostream &operator<<(std::ostream &out, const Point &p)
{
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

bool RightRectangle::contains(const Point &p) const
{
  // TODO: implement this method.
  return false;
}

Point::Point(int xx, int yy) : x(xx), y(yy) {}

RightRectangle::RightRectangle(int x0, int y0, int x1, int y1)
{
  // TODO: implement this method.
  Point p0(x0, y0);
  Point p1(x1, y1);
  limits.push_back(p0);
  limits.push_back(p1);
}