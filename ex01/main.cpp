#include <iostream>
#include "Data.hpp"

int main()
{
  void* raw = serialize();
  Data* data = deserialize(raw);

  std::cout << *(data->s1) << '\n';
  std::cout << data->n << '\n';
  std::cout << *(data->s2) << '\n';
}
