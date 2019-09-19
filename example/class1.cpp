#include "class1.h"
#include <iostream>
#include "factory.h"

Class1::Class1(int id, std::string greet_word) : m_id(id), m_word(greet_word)
{

}

Class1::~Class1()
{

}

void Class1::interface1()
{
  std::cout << m_word << " from Class1 interface1(id:" << m_id << ")" << std::endl;
}

void Class1::interface2()
{
  std::cout << m_word << " from Class1 interface2(id:" << m_id << ")" << std::endl;
}

REGISTER_TEST_CLASS(Class1)
