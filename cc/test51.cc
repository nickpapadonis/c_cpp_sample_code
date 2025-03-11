#include <iostream>
#include <string>
#include <list>
#include <iterator>

struct X {
  enum c_t { A, B };
  c_t type;
  std::string name;
  
  X() : type(A) {};
  //X() { type = A; };
};

struct Y : public X {
  Y() { type = B; };
  std::string oname;
};

void ple(const X *p)
{
  switch (p->type) {
  case X::A:
    std::cout << p->name << '\n';
    break;
  case X::B:
    const Y *py = static_cast<const Y*>(p);
    std::cout << py->oname << '\n';
    break;
  }
}

int main(int argc, char *argv[])
{
  std::list<X*> l;

  X *p;
  p = new X();
  p->name = "a";
  l.push_back(p);

  Y *y;
  y = new Y();
  y->name = "z0";
  y->oname = "z1";
  l.push_back(y);

  p = new X();
  p->name = "b";
  l.push_back(p);

  for (std::list<X*>::const_iterator i = l.begin(); i != l.end(); ++i) {
    ple(*i);
  }
      
  return 0;
}
