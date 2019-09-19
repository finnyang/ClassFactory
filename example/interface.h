#ifndef INTERFACE_H_
#define INTERFACE_H_

class Interface {
public:
  virtual ~Interface();
  virtual void interface1() = 0;
  virtual void interface2() = 0;
};

#endif
