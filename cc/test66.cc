#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
  string s {"Nicholas Papadonis"};
  string s2 = s.substr(string("Nicholas").length() - 1 + 2,
		       string("Papadonis").length());
  cout << s2 << endl;
  
  string s3 = s.replace(0, string("Nicholas").length(), "Nick");
  cout << s3 << endl;

  s3[0] = tolower(s3[0]);
  cout << s3 << endl;

  if (s3 == "nick Papadonis")
    cout << "is Nick!" << endl;
  else
    cout << "is not Nick" << endl;
  
  return 0;
}
