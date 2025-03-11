#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::cout;
using std::string;
using std::cerr;

template<typename C, typename V>
vector<typename C::iterator> find_all(C& c, V v)
{
  vector<typename C::iterator> res;
  for (auto p = c.begin(); p != c.end(); ++p)
    if (*p == v)
      res.push_back(p);
  return res;
}

int main(int argc, char *argv[])
{
  string m {"Mary had a little lamb"};
  for (auto p : find_all(m, 'a')) {
    cout << ".";
    if (*p != 'a')
      cerr << "bug!\n";
  }
  cout << '\n';

  vector<double> ld = {1.1, 2.1, 3.1};
  for (auto p : find_all(ld, 1.1)) {
    cout << ".";
    if (*p != 1.1)
      cerr << "bug!\n";
  }
  cout << '\n';

  vector<string> vs = {"abc", "def", "ghi"};
  for (auto p : find_all(vs, "def")) {
    cout << ".";
    if (*p != "def")
      cerr << "bug!\n";
  }
  cout << '\n';

  for (auto p : find_all(vs, "def"))
    *p = "xyz";
  
  for (auto p : vs)
    cout << p << " ";
  cout << '\n';
  
  return 0;
}
