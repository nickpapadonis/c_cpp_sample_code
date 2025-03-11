#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct A {
    int val;
    void operator()(int& v) const {v += val;}
};

int main(int argc, char *argv[])
{
    vector<int> v {0, 1, 2, 3};

    for_each(v.begin(), v.end(), A{1});

    for_each(v.begin(), v.end(),
	     [](int& v){v += 1;});
    
    for (auto& p : v)
	cout << p;
    cout <<  endl;
    
    return 0;
}
