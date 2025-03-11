#include <iostream>
#include <vector>
#include <list>
using std::vector;
using std::list;
using std::cout;

template<typename T>
class Vec : public vector<T> {
public:
  using vector<T>::vector; // constructor
  
  T& operator[](int i)
  {
    return vector<T>::at(i);
  }
  const T& operator[](int i) const
  {
    return vector<T>::at(i);
  }
};

int main(int argc, char *argv[])
{
  vector<int> v0 = {0, 1, 2};
  Vec<int> v1 = {0, 1, 2};

  cout << v0[v0.size()] << '\n'; // no error

  try {
    cout << v1[v1.size()]; // out of range
  } catch (std::out_of_range& e) {
    cout << "tried out of range" << '\n';
  } catch (...) {
    cout << "unknown exception" << '\n';
  }
  
  return 0;
}
