#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
    string s0 {"first first"};
#if 0
    size_t p = 0;
    while ((p = s0.find("first", p)) != string::npos) {
	cout << p << endl;
	p += string{"first"}.size();
    }

    p = 0;
    while ((p = s0.find_first_of("irs", p)) != string::npos) {
	cout << s0[p] << endl;
	++p;
    }
#endif
    string s1 = s0.substr(0, 5);
    cout << s1 << endl;
	
}
