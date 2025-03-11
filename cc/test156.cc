#include <iostream>
#include <vector>
#include <utility>
using namespace std;

struct A {
    vector<pair<string, int>> v;

    int& operator[](const string& s);
    const int& operator[](const string& s) const;
};

int& A::operator[](const string& s)
{
    for (auto& p : v)
	if (p.first == s)
	    return p.second;
    v.push_back(pair<string,int>{s, 0});

    return v.back().second;
}
    
int main(int argc, char *argv[])
{
    A assoc;
    string s;

    while (cin >> s)
	++assoc[s];

    for (auto& p : assoc.v)
	cout << p.first << ", " << p.second << endl;
    
    return 0;
}
     
