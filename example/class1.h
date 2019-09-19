#ifndef CLASS1_H_
#define CLASS1_H_

#include <string>

#include "interface.h"


class Class1 final : public Interface
{
public:
  Class1(int, std::string);
  virtual ~Class1() override;
  virtual void interface1() override;
  virtual void interface2() override;

private:
  int m_id;
  std::string m_word;
};

#endif
