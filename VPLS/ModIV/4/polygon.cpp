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
  int size = left.size() > right.size() ? left.size() : right.size();

  int firstIteration = 0;
  for (Point i : left)
  {
    for (Point j : right)
    {
      if (i.contains(j))
      {
        firstIteration++;
        break;
      }
    }
  }
  int secondtIteration = 0;
  for (auto i : right)
  {
    for (auto j : left)
    {
      if (i.contains(j))
      {
        secondtIteration++;
        break;
      }
    }
  }
  if (size == 1)
  {
    std::cout << lhs << ", " << rhs;
  }
  return (firstIteration == size && firstIteration == secondtIteration);
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
  Point begin = limits[0];
  Point end = limits[2];
  return p.x >= begin.x && p.x <= end.x &&
         p.y >= begin.y && p.y <= end.y;
}

Point::Point(int xx, int yy) : x(xx), y(yy)
{
  limits.push_back(*this);
}

RightRectangle::RightRectangle(int x0, int y0, int x1, int y1)
{
  // TODO: implement this method.
  int smallerX = x0 < x1 ? x0 : x1;
  int smallerY = y0 < y1 ? y0 : y1;

  int greaterX = x0 > x1 ? x0 : x1;
  int greaterY = y0 > y1 ? y0 : y1;

  limits.push_back(Point(smallerX, smallerY));
  limits.push_back(Point(smallerX, greaterY));
  limits.push_back(Point(greaterX, greaterY));
  limits.push_back(Point(greaterX, smallerY));
}