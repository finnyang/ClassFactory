#ifndef FACTORY_H_
#define FACTORY_H_

#include "../ClassFactory.h"
#include "interface.h"
#include <string>

using FactoryTest = ClassFactory<Interface, int, std::string>;

#define REGISTER_TEST_CLASS(ClassName) REGISTER_CLASS(ClassName, Test, int, std::string)

#endif
