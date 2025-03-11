#include <iostream>
#include <list>
using std::list;
using std::cout;

int main(int argc, char *argv[])
{
  list<int> l = {0, 1, 2};

  for (list<int>::iterator it=l.begin();
       it != l.end();
       ++it)
    cout << *it;
  cout << '\n';

  for (auto &it : l) {
    it += 1;
    cout << it;
  }
  cout << '\n';

  for (auto it : l) {
    cout << it;
    it += 1;
  }
  cout << '\n';

  for (auto it : l) {
    cout << it;
  }
  cout << '\n';

  return 0;
}
