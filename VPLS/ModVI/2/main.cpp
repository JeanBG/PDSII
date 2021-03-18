#include <iostream>
#include <set>

class UninitializedIndex
{
};
class NegativeIndex
{
};
class InvalidIndex
{
};

template <class T, int N>
class BoundedArray
{
public:
  void set(int index, T value)
  {
    if (index >= N)
      throw InvalidIndex();

    if (index < 0)
      throw NegativeIndex();

    buf[index] = value;
    if (indexes.find(index) == indexes.end())
      indexes.insert(index);
  }
  T get(int index)
  {
    if (index < 0)
      throw NegativeIndex();

    if (index >= N)
      throw InvalidIndex();

    if (indexes.find(index) == indexes.end())
      throw UninitializedIndex();

    return buf[index];
  }

private:
  T buf[N];
  std::set<int> indexes;
};

template <class T>
void testArray()
{
  BoundedArray<T, 8> a;
  char action;
  while (std::cin >> action)
  {
    int index;
    std::cin >> index;
    try
    {
      if (action == 's')
      {
        T value;
        std::cin >> value;
        a.set(index, value);
      }
      else if (action == 'g')
      {
        std::cout << a.get(index) << std::endl;
      }
    }
    catch (UninitializedIndex)
    {
      std::cerr << "Erro: indice nao inicializado." << std::endl;
    }
    catch (NegativeIndex)
    {
      std::cerr << "Erro: indice negativo." << std::endl;
    }
    catch (InvalidIndex)
    {
      std::cerr << "Erro: indice maior que arranjo." << std::endl;
    }
    catch (...)
    {
      std::cerr << "Erro desconhecido." << std::endl;
    }
  }
}

int main()
{
  char type;
  std::cin >> type;
  switch (type)
  {
  case 'd':
    testArray<double>();
    break;
  case 'i':
    testArray<int>();
    break;
  case 's':
    testArray<std::string>();
    break;
  }
  return 0;
}