#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class LT {
  const int val;
public:
  LT(const int& v) : val(v) { }
  bool operator()(const pair<const string, int>& x)
    const { return x.second < val; }
};

int main(int argc, char *argv[])
{
  map<string,int> m = {{"a", 1},
		       {"b", 2},
		       {"c", 3}};

  auto iter = find_if(m.begin(), m.end(), LT{3});
  while (iter != m.end()) {
    cout << iter->first << '\n';
    iter = find_if(++iter, m.end(), LT{3});
  }

  iter = find_if(m.begin(), m.end(),
		      [](const pair<const string,int>& r) {return r.second<=3;});
  while (iter != m.end()) {
    cout << iter->first << '\n';
    iter = find_if(++iter, m.end(),
		   [](const pair<const string,int>& r) {return r.second<=3;});
  }

  int c = count_if(m.begin(), m.end(),
		   [](const pair<const string, int>& r)
		   {return r.second <= 3;});
  cout << "count: " << c << '\n';

  return 0;
}
