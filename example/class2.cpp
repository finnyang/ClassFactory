#include "class2.h"
#include <iostream>
#include "factory.h"

Class2::Class2(int id, std::string greet_word) : m_id(id), m_word(greet_word)
{

}

Class2::~Class2()
{

}

void Class2::interface1()
{
  std::cout << m_word << " from Class2 interface1(id:" << m_id << ")" << std::endl;
}

void Class2::interface2()
{
  std::cout << m_word << " from Class2 interface2(id:" << m_id << ")" << std::endl;
}

REGISTER_TEST_CLASS(Class2)
