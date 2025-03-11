#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using std::list;
using std::vector;
using std::cout;
using std::string;
using std::ostream;
using std::unique_copy;

struct A {
  string name;
  int num;
};

bool operator==(const struct A& a, const struct A& b)
{
  return a.name == b.name && a.num == b.num;
}

void f0(vector<struct A>& vec, list<struct A>& lst)
{
  unique_copy(vec.begin(),vec.end(),lst.begin());
}

void f1(vector<struct A>& vec, list<struct A>& lst)
{
  unique_copy(vec.begin(),vec.end(),back_inserter(lst));
}

int main(int argc, char *argv[])
{
  vector<struct A> v0 = {{"a", 0},
			 {"b", 1}};
  list<struct A> l0(v0.size());
  list<struct A> l1;
  
  f0(v0, l0);

  f1(v0, l1);

  for (auto& p : l0)
    cout << p.name << " " << p.num << '\n';

  for (auto& p : l1)
    cout << p.name << " " << p.num << '\n';

  struct A s0 = {"b", 1};
  struct A s1 = {"z", 1};
  
  auto p = find(v0.begin(),v0.end(),s0);
  if (p!=v0.end())
    cout << "found\n";
  else
    cout << "notfound\n";

  p = find(v0.begin(),v0.end(),s1);
  if (p!=v0.end())
    cout << "found\n";
  else
    cout << "notfound\n";

  return 0;
}
