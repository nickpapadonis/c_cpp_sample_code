#include <iostream>
#include <list>
#include <string>
using std::list;
using std::string;
using std::cout;

int main(int argc, char *argv[])
{
  list<string> la = {"a", "b"};
  list<string> lb {"a", "b"};

  for (auto& r : la)
    cout << r << '\n';

  for (auto& r : lb)
    cout << r << '\n';

  return 0;
}
