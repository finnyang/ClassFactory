#ifndef CLASS2_H_
#define CLASS2_H_

#include <string>

#include "interface.h"


class Class2 final : public Interface
{
public:
  Class2(int, std::string);
  virtual ~Class2() override;
  virtual void interface1() override;
  virtual void interface2() override;

private:
  int m_id;
  std::string m_word;
};

#endif
