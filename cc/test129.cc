#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> f2(const vector<int>& v)
{
    class GT {
    private:
	vector<int>& vo; // *(vector<int> * const vo)
	int max;
    public:
	GT(vector<int>& vo_, int max_) : vo{vo_}, max{max_} {}
	void operator()(int x) {if (x > max) vo.push_back(x);}
    };

    vector<int> vo;
    
    for_each(v.begin(), v.end(),
	     GT(vo, 5));

    return vo;
}

vector<int> f(const vector<int>& v)
{
    const int max = 5;
    vector<int> vg;

    auto mod_print = [max, &vg](int x) {if (x > max) vg.push_back(x);};
	
    for_each(v.begin(), v.end(), mod_print); 

    return vg;
}

int main(int argc, char *argv[])
{
    vector<int> v {0, 1, 6, 8};
    vector<int> v2;
    
    v2 = f(v);
    for (auto& p : v2)
	cout << p;
    cout << endl;

    v2 = f2(v);
    for (auto& p : v2)
	cout << p;
    cout << endl;

    return 0;
}
