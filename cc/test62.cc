#include <iostream>
#include <list>
using std::list;
using std::cout;
using std::initializer_list;

class X {
  list<int> *p;
public:
  X() : p{ new list<int>(0) } { }
  X(size_t size) : p{ new list<int>(size) } { }
  X(initializer_list<int> li) : p{ new list<int>(li) } { }

  X(const X&);
  X& operator=(const X&);

  // move
  X(X&&);
  X& operator=(X&&);

  size_t size() const { return p->size(); }
  int &operator[](int);
  int &operator[](int) const;
  
  class size_mismatch { };
};

X::X(const X& a)
{
  p = new list<int>();
  for (auto pp : *(a.p))
    p->push_back(pp);
}

X& X::operator=(const X& a)
{
  delete p;
  p = new list<int>();
  for (auto pp : *(a.p))
    p->push_back(pp);
  return *this;
}

X::X(X&& a) : p{ a.p }
{
  cout << "here0\n";
  a.p = nullptr;
}


X& X::operator=(X&& a)
{
  cout << "here1\n";
  p = a.p;
  a.p = nullptr;
  return *this;
}

int& X::operator[](int x)
{
  for (auto &i : *p) {
    if (x == 0) return i;
    --x;
  }

  throw std::out_of_range("List container");
}

int& X::operator[](int x) const
{
  for (auto &i : *p) {
    if (x == 0) return i;
    --x;
  }

  throw std::out_of_range("List container");
}

X operator+(const X& a, const X& b)
{
  if (a.size()!=b.size())
    throw X::size_mismatch{};
  
  X res(a.size());

  for (size_t i = 0; i != a.size(); ++i)
    res[i] = a[i] + b[i];

  //return std::move(res);
  // copy-elision no move called
  return res;
}

int main(int argc, char *argv[])
{
  X px = {0, 1, 2};

  for (size_t i=0; i < px.size(); i++)
    cout << px[i];
  cout << '\n';

  X py(px);
  for (size_t i=0; i < py.size(); i++)
    py[i]++;
  for (size_t i=0; i < py.size(); i++)
    cout << py[i];
  cout << '\n';

  X pz;
  pz = py;
  for (size_t i=0; i < pz.size(); i++)
    cout << pz[i];
  cout << '\n';

  X ph;
  ph = px + py + pz;
  for (size_t i=0; i < ph.size(); i++)
      cout << ph[i];
  cout << '\n';
  
  return 0;
}
