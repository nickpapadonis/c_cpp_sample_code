#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
  map<string,int> m = {{"a", 1},
		       {"b", 2},
		       {"c", 3}};

  auto p = find(m.begin(), m.end(), pair<const string,int>{"b", 2});
  cout << p->first << '\n';

  p = m.find("c");
  cout << p->first << '\n';

  int z = m["c"];
  cout << z << '\n';
  
  return 0;
}
