#include <iostream>

template <class T, int N>
class BoundedArray
{
public:
  class UninitializedIndex{};
  class NegativeIndex {};
  class InvalidIndex{};

  void
  set(int index, T value)
  {
    if (index >= N)
      throw InvalidIndex();

    if (index < 0)
      throw NegativeIndex();

    buf[index] = value;
  }
  T get(int index)
  {
    if (index < 0)
      throw NegativeIndex();

    if (!buf[index])
      throw UninitializedIndex();

    return buf[index];
  }

private:
  T buf[N];
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
    catch (UninitializedIndex)
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