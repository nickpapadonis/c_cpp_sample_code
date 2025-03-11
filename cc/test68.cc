#include <iostream>
#include <vector>
#include <list>
using std::vector;
using std::list;
using std::cout;

int main(int argc, char *argv[])
{
  vector<list<int>> v0 = {{0, 1},
			  {2, 3}};

  for (auto& p : v0)
    for (auto& y : p)
      cout << y << ", ";
  cout << '\n';
  
  return 0;
}
