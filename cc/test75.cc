#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
using std::string;
using std::ostream_iterator;
using std::istream_iterator;
using std::cout;
using std::cin;

int main(int argc, char *argv[])
{
  ostream_iterator<string> oo {cout};

  *oo = "One\n";
  ++oo;
  *oo = "Two\n";

  istream_iterator<string> is {cin};

  string s0 = *is;
  ++is;
  string s1 = *is;

  cout << s0 << '\n';
  cout << s1 << '\n';
  
  return 0;
}
