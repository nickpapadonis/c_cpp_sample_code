#include <iostream>
#include <vector>
#include <string>
using namespace std;

void f(vector<string>& s1)
{
    auto rev=[](string *b, string *e) {
		 while (1 < e - b)
		     swap(*b++, *--e);
	     };
    rev(&s1[0], &s1[0] + s1.size());
}

int main(int argc, char *argv[])
{
    vector<string> v1 = {"abcd", "efgh", "lmno"};

    f(v1);

    for (auto& p : v1)
	cout << p << ",";
    cout << endl;
    
    return 0;
}
