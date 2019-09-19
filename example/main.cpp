#include "interface.h"
#include "factory.h"
#include <memory>

int main()
{
  std::unique_ptr<Interface> temp1(FactoryTest::generate_class("Class1", 1, "hello world"));
  temp1->interface1();
  temp1->interface2();
  std::unique_ptr<Interface> temp2(FactoryTest::generate_class("Class2", 2, "hello world"));
  temp2->interface1();
  temp2->interface2();

  return 0;
}
