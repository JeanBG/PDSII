#include <iostream>

#include "RingArray.h"

void fer_assert(const bool expr, const char *msg)
{
  if (!expr)
  {
    std::cout << msg << std::endl;
    exit(1);
  }
}

template <class T, unsigned N>
void RingArray<T, N>::add(T value)
{
  // TODO: implement this method.
  fer_assert(!this->isFull(), "Erro: anel cheio.");
  if (this->_first != 0)
  {
    this->_first = 0;
    this->_last = 1;
    this->buf[_first] = value;
  }
  else
  {
    this->buf[_last] = value;
    this->_last++;
  }
}

template <class T, unsigned N>
T RingArray<T, N>::get()
{
  // TODO: implement this method.
  fer_assert(!this->isEmpty(), "Erro: anel vazio.");
  T value = this->buf[this->_first];
  for (unsigned i = 0; i < this->_last; ++i)
  {
    this->buf[i] = this->buf[i + 1];
  }
  this->_last--;
  return value;
}

template <class T, unsigned N>
bool RingArray<T, N>::isFull() const
{
  // TODO: implement this method.
  return (this->_last - this->_first) == (N - 1);
}

template <class T, unsigned N>
bool RingArray<T, N>::isEmpty() const
{
  // TODO: implement this method.
  return (this->_last - this->_first) == 0;
}

template <class T>
void test_add_then_get()
{
  RingArray<T, 8> r;
  T value;
  while (std::cin >> value)
  {
    r.add(value);
  }
  while (!r.isEmpty())
  {
    std::cout << r.get() << std::endl;
  }
}

template <class T>
void test_add_or_get()
{
  RingArray<T, 8> r;
  T value;
  char c;
  while (std::cin >> c)
  {
    if (c == '+')
    {
      std::cin >> value;
      r.add(value);
    }
    else if (c == '-')
    {
      std::cout << r.get() << std::endl;
    }
    else
    {
      std::cout << "Invalid operation\n";
    }
  }
}

int main()
{
  char data;
  while (std::cin >> data)
  {
    switch (data)
    {
    case 'd':
      test_add_then_get<double>();
      break;
    case 's':
      test_add_then_get<std::string>();
      break;
    case 'D':
      test_add_or_get<double>();
      break;
    case 'S':
      test_add_or_get<std::string>();
      break;
    default:
      std::cout << "Invalid type\n";
    }
  }
  return 0;
}