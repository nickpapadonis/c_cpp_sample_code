#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <set>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
  ifstream is {"input.txt"};
  ofstream os {"output.txt"};
  
  istream_iterator<string> ii {is};
  istream_iterator<string> eos {};
  
  ostream_iterator<string> oi {os, "\n"};

  // no dupes and ordering
  set<string> b {ii, eos}; // [ii, eos)

  copy(b.begin(), b.end(), oi);
  
  return !is.eof() || !os;
}
