#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
  ifstream is {"input.txt"};
  ofstream os {"output.txt"};
  
  istream_iterator<string> ii {is};
  istream_iterator<string> eos {};
  
  ostream_iterator<string> oi {os, "\n"};

  // dupes and no ordering
  vector<string> b_v {ii, eos}; // [ii, eos)

  sort(b_v.begin(), b_v.end());
  
  // discards duplicates
  unique_copy(b_v.begin(), b_v.end(), oi);
  
  return !is.eof() || !os;
}
