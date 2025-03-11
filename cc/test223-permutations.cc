#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<string> merge(vector<string> list, string c);

vector<string> perms(string s)
{
    vector<string> res;
    if (s.size() == 1) {
	res.push_back(s);
    } else if (s.size() > 1) {
	string last = s.substr(s.size() - 1, 1);
	string begin = s.substr(0, s.size() - 1);
	res = merge(perms(begin), last);
    }
    return res;
}

vector<string> merge(vector<string> list, string c)
{
    vector<string> res;
    for (auto& r : list) {
	for (int i = 0; i <= r.size(); ++i) {
	    string s = string{r}.insert(i, c);
	    res.push_back(s);
	}
    }
    return res;
}

int main(int argc, char *argv[])
{
    if (argc <= 1)
	return 1;

    string s0{};
    if (argc == 2)
	s0 = argv[1];
    else
	return 1;
    
    vector<string> v = perms(s0);

    for (auto& r : v)
	cout << r << ", ";
    cout << endl;
    
    return 0;
}
