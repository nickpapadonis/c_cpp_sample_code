#include <iostream>
using std::cout;
using std::endl;

template <class T, int i> class Buffer {
  T arr[i];
  int sz;
public:
  Buffer() : sz(i) {}
  int getsz() {return sz;}
};

//C++ forbids variable length array
void f(int i)
{
  // int arr[i];
}

int main(int argc, char *argv[])
{
  int a[10];
  Buffer<int, 10> buf;

  cout << buf.getsz() << endl;
  return 0;
}
