#include "Data.hpp"

void* serialize(void)
{
  char* raw = new char[sizeof(void*) * 2 + sizeof(int)];
  std::string* s1 = new std::string("01234");
  int n = 123;
  std::string* s2 = new std::string("01234");

  *(reinterpret_cast<std::string**>(raw)) = s1;
  *(reinterpret_cast<int*>(raw + sizeof(std::string*))) =  n;
  *(reinterpret_cast<std::string**>(raw + sizeof(std::string*) + sizeof(int))) = s2;
  return static_cast<void*>(raw);
}

Data* deserialize(void* _raw)
{
  char* raw = static_cast<char*>(_raw);
  Data* data = new Data();
  data->s1 = *reinterpret_cast<std::string**>(raw);
  data->n = *reinterpret_cast<int*>(raw + sizeof(std::string *));
  data->s2 = *reinterpret_cast<std::string**>(raw + sizeof(std::string *) + sizeof(int));
  return (data);
}
