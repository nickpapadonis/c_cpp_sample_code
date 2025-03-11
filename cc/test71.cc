#include <map>
#include <unordered_map>
#include <string>
#include <iostream>

using std::map;
using std::unordered_map;
using std::string;
using std::cout;

int main(int argc, char *argv[])
{
  // red black tree with ordering
  map<string, int> m0 = {{"abc", 1},
			 {"def", 2}};

  // hashed lookup
  unordered_map<string, int> m1 = {{"abc", 1},
				   {"def", 2}};

  cout << m0["def"] << '\n';
  cout << m0["ghi"] << '\n';

  cout << m1["def"] << '\n';
  cout << m1["ghi"] << '\n';
  
  return 0;
}
