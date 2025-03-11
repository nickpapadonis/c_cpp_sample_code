#include <regex>
#include <iostream>
using namespace std;

int main()
{
    string input {"aa::bb cc::dd ee::ff"};
    regex pat {R"((\w+)([[:punct:]]+)(\w+)\s*)"};
    sregex_token_iterator end {};
    for (sregex_token_iterator p {input.begin(),input.end(),pat,{1,3}};
	 p!=end; ++p)
	cout << *p << '\n';

    return 0;
}
