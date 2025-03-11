#include <iostream>
using std::cout;
using std::endl;

class X {
public:
  virtual void i0(void) = 0;
};

class Y : public X {
public:
  virtual void i1(void) = 0;
};

class BB {
public:
  void d0(void) { }
};

class BBI : public Y, protected BB {  
  void i0(void) { d0(); cout << "i0" << endl; }
  void i1(void) { d0(); cout << "i1" << endl; }
};

class Fact {
public:
  virtual Y *y(void) = 0;
};

class FactBB : public Fact {
public:
  Y *y(void) { return new BBI(); }
};

void f(Fact *fact)
{
  Y *y0 = fact->y();

  y0->i0(); y0->i1();

  delete y0;
}

int main(int argc, char *argv[])
{
  // driver
  FactBB BB_impl;
  f(&BB_impl);

  return 0;
}
