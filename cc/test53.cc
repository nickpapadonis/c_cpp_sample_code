#include <iostream>
#include <string>
#include <list>

using std::cout;
using std::endl;
using std::string;
using std::list;

class X {
  string s;
public:
  X();
  X(string ss) {cout << "Xss" << endl; s = ss;}
  virtual void print() const;
};

X::X() {
  cout << "X cons" << endl;
}

class Z {
  string s;
public:
  Z();
  Z(string ss) {cout << "Zss" << endl; s = ss;}
  virtual void print() const;
  virtual void f1() const;
};

Z::Z() {
  cout << "Z cons" << endl;
}

void Z::f1() const {
  cout << "in f1" << endl;
}

class Y : public X, protected Z {
  string s;
public:
  Y();
  Y(string ss) : X(ss), Z(ss) {s = ss;}
  void print() const;
};

Y::Y() {
  cout << "Y cons" << endl;
}

class H : public Y {
public:
  void print() const;
};

void H::print() const
{
  cout << "in H" << endl;
  f1();
}

void X::print() const
{
  cout << "in X" << endl;
}

void Y::print() const
{
  X::print();
  Z::print();
  f1();
  cout << "in Y" << endl;
}

void Z::print() const
{
  cout << "in Z" << endl;
}

int main(int argc, char *argv[])
{
  Y y("hi");

  cout << endl;
  X *px = static_cast<X*>(&y);
  // Z *pz = static_cast<Z*>(&y); Z is protected!
  
  px->print();
  cout << endl;

  H h;
  h.print();
  
  return 0;
}
