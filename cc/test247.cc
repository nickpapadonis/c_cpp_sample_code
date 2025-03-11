#include <regex>
#include <iostream>
using namespace std;

int main()
{
    string input = "aa as; asd ++eˆasdf asdfg";
    regex pat {R"(\s?(\w+))"};
    for (sregex_iterator p(input.begin(),input.end(),pat); p!=sregex_iterator{}; ++p)
	cout << (*p)[1] << '\n';

    return 0;
}
