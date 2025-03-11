#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

template<class C>
void sort(C& c)
{
  sort(c.begin(), c.end());
}

template<class C, class P>
void sort(C& c, P p)
{
  sort(c.begin(), c.end(), p);
}

int main(int argc, char *argv[])
{
  vector<int> v0 = {0, 3, 1, 2};
  sort(v0);
  for (auto p : v0)
    cout << p << endl;

  cout << endl;
  
  vector<int> v1 = {0, 3, 1, 2};
  sort(v1, [](int& a, int& b) {return a < b;});
  for (auto p : v1)
    cout << p << endl;

  return 0;
}
