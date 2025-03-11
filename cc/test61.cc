#include <iostream>
#include <list>
using std::list;
using std::cout;


int main(int argc, char *argv[])
{
  list<int> x = {0, 1, 2};
  list<int> y, z;
  
  z = (y = x);

  z.push_front(9);
  for (auto it : x) {
    cout << it;
  }
  cout << '\n';

  for (auto it : y) {
    cout << it;
  }
  cout << '\n';

  for (auto it : z) {
    cout << it;
  }
  cout << '\n';

  return 0;
}
