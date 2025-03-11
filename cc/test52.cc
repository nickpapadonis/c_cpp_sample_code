#include <iostream>
#include <string>

using std::cout;
using std::string;

class X {
  string s;
public:
  X(string x) : s(x) {};
  virtual void print() const;
};

void X::print() const
{
  cout << "X " << s << '\n';
}

class Y : public X {
  string s;
public:
  Y(string y) : X(y), s(y) {};
  void print() const;
};

void Y::print() const
{
  X::print();
  cout << "Y " << s << '\n';
}

int main(int argc, char *argv[])
{
  X x("testx");
  x.print();
  Y y("testy");
  y.print();

  cout << '\n';
  
  X &rx = y;
  rx.print();
  X *px = &y;
  px->print();
  
  return 0;
}
