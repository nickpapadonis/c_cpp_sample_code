#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main(int argc, char *argv[])
{
  vector<int> v0 = {0, 1, 2, 3};
  replace(v0.begin(), v0.end(), 2, 9);
  for (auto p : v0)
    cout << p << endl;

  cout << endl;

  cout << "equal_range" << endl;
  vector<int> v1 = {0, 1, 2, 2, 1, 2, 3};
  pair<vector<int>::iterator, vector<int>::iterator> bounds;
  // binary search for 2
  bounds = equal_range(v1.begin(), v1.end(), 2);
  for (auto it = bounds.first; it != bounds.second; ++it)
    cout << *it << " ";
  cout << endl;

  
  cout << endl;
  
  replace_if(v1.begin(), v1.end(), [](int &a){return a<=2;}, 9);
  for (auto p : v1)
    cout << p << endl;

  cout << endl;
  
  vector<int> v2 = {0, 3, 1, 2};
  sort(v2.begin(), v2.end(), [](int &a, int&b){return a<b;});
  for (auto p : v2)
    cout << p << endl;

  cout << endl;
  
  vector<int> va = {0, 1};
  list<int> vb = {2, 3};

  vector<int> vc(va.size() + vb.size());
  merge(va.begin(), va.end(), vb.begin(), vb.end(), vc.begin());
  for (auto p : vc)
    cout << p << endl;

  cout << endl;

  vector<int> vd;
  merge(va.begin(), va.end(), vb.begin(), vb.end(), back_inserter(vd));
  for (auto p : vd)
    cout << p << endl;

  return 0;
}
