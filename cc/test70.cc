#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using std::list;
using std::cout;
using std::string;
using std::ostream;
using std::sort;

struct A {
  string name;
  int num;
};

bool operator<(const struct A& a, const struct A& b)
{
  return a.name < b.name;
}

int get_num(const list<struct A>& l, const string name)
{
  for (const auto& p : l) {
    if (p.name == name)
      return p.num;
  }
  return -1;
}

int get_num_it(const list<struct A>& l, const string name)
{
  for (auto it=l.begin();
       it != l.end();
       ++it) {
    if (it->name == name)
      return it->num;
  }
  return -1;
}

void erase(list<struct A>& l, const string name)
{
  for (auto it=l.begin();
       it != l.end();
       ++it) {
    if (it->name == name) {
      l.erase(it);
      break;
    }
  } 
}

void insert(list<struct A>& l, const string name, const struct A& s)
{
  for (auto it=l.begin();
       it != l.end();
       ++it) {
    if (it->name == name) {
      l.insert(it, s);
      return;
    }
  }
  // insert at end
  l.insert(l.end(), s);
}

ostream& operator<<(ostream& os, const struct A& s)
{
  return cout << "name:" << s.name << " " << "num:" << s.num << '\n';
}

ostream& operator<<(ostream& os, const list<struct A>& l)
{
  for (const auto& p : l)
    cout << p;
  return cout << '\n';
}

int main(int argc, char *argv[])
{
  list<struct A> l0 = {{"abc", 0},
		       {"def", 1},
		       {"hij", 2}};

  cout << l0;

  cout << get_num(l0, "def") << '\n';
  cout << get_num_it(l0, "def") << '\n';

  erase(l0, "def");
  cout << l0;

  struct A s = {"xyz", 0};
  insert(l0, "abc", s);
  cout << l0;

  s = {"lmn", 0};
  insert(l0, "", s);
  cout << l0;

  l0.sort();
  cout << l0;
  
  return 0;
}
