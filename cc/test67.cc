#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::ostream;

struct A {
  string name;
  int num;
};

ostream& operator<<(ostream &os, const struct A& e)
{
  return os << e.name << ", " << e.num << endl;
}

int main(int argc, char *argv[])
{
  vector<A> a0 = {{"a", 1},
		  {"b", 2}};

  for (auto& p : a0) {
    cout << p;
  }

  for (vector<A>::iterator p=a0.begin();
       p != a0.end();
       ++p)
    cout << *p;
  
  return 0;
}
