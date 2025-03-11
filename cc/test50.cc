#include <iostream>

class X {
private:
  int x;
public:
  X();
  X(int x);
  X(const X &s);
  X &operator=(const X &s);
  void print();
};

X::X()
{
  std::cout << "X()" << '\n';
}

X::X(int xv)
{
  x = xv;
  std::cout << "X(" << xv << ")\n";
}

X::X(const X &s)
{
  std::cout << "X(cc)" << '\n';
}

X& X::operator=(const X &s)
{
  std::cout << "X(ao)" << '\n';
  return *this;
}

void X::print()
{
  std::cout << "x = " << x << '\n';
}

int main(int argc, char *argv[])
{
  /* call empty () cons */
  X s1, s2;

  /* both same call ao */
  s2 = s1;
  s2.operator=(s1);

  /* call cc */
  X s3(s1);

  /* call cc */
  X s6 = s1;

  std::cout << "p0\n";
  X s7(1);
  X s4 = X(1);   
  s7.print(); s4.print();
  
  return 0;
}
