#include <iostream>
#include <regex>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    ifstream fin {"test91.input"};
    // ZIP code pattern: XXddddd-dddd and variants
    // \w : matches word
    // \s : matches whitespace, *: 0 or more
    // \d : matches digits
//#define NOTRAW
#ifdef NOTRAW
    regex pat ("(\\w{2})\\s*(\\d{5})-(\\d{4})?");
#else
    regex pat (R"((\w{2})\s*(\d{5})-?(\d{4})?)");
#endif
        
    for (string line; getline(fin,line);) {
	smatch matches; // matched strings go here
	if (regex_search(line, matches, pat)) { // search for pat in line
	    cout << matches[0] << endl;
	    if (matches.size() > 1) {
		for (int i = 1; i < matches.size(); ++i) {
		    if (matches[i].matched)
			cout << matches[i] << ".";
		}
	    }
	}
	cout << endl;
    }
    
    return 0;
}
