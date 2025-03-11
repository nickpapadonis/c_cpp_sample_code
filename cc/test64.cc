#include <iostream>
#include <vector>
using std::vector;
using std::cout;

template<typename T>
class LT {
  const T val;
public:
  // T * const v
  LT(const T& v) : val(v) { }
  bool operator()(const T& x) const { return x < val; }
};

template<typename C, typename P>
int count(const C& c, P pred)
{
  int cnt = 0;
  for (const auto& x : c)
    if (pred(x)) ++cnt;
  return cnt;
}
  
int main(int argc, char *argv[])
{
  LT<int> lti {10};
  // LT<int> lti2 = LT<int>{10}; // ?

  cout << lti(1) << '\n';
  cout << lti(11) << '\n';

  vector<int> v = {0, 1, 11, 12, 2};
  cout << count(v, LT<int>{10}) << '\n';
  cout << count(v, lti) << '\n';

  // lambda expr
  cout << count(v, [&](int a){ return a<12; }) << '\n';
  
  return 0;
}
