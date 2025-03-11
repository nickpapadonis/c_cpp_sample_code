#include <regex>
#include <iostream>
using namespace std;

int main()
{
    string input {"x 1 y 2 z 3"};
    regex pat {R"((\w)\s(\d+))"}; // word space number
    string format {"$2: $1\n"};
//    cout << regex_replace(input,pat,format,regex_constants::format_no_copy);
      string s = regex_replace(input,pat,format,regex_constants::format_no_copy);
      cout << s;

    return 0;
}
