#include <iostream>
#include <list>
#include <vector>
using std::list;
using std::vector;
using std::cout;
using std::initializer_list;

template<typename C, typename V>
V sum(const C& c, V v)
{
  for (auto x : c)
    v+=x;
  return v;
}

int main(int argc, char *argv[])
{
  list<int> li = {0, 1, 2};
  vector<double> vd = {0.1, 0.1, 0.1};
  
  cout << sum(li, 0) << '\n';
  cout << sum(vd, 0.0) << '\n';
  
  return 0;
}
