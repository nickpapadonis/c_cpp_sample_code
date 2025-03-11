#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class GT2 {
private:
    vector<int> * const vo;
    int max;
public:
    GT2(vector<int> * const vo_, int max_) : vo{vo_}, max{max_} {}
    void operator()(int x) {if (x > max) vo->push_back(x);}
};

void f3(const vector<int> * const v, vector<int> * const v2)
{
    for_each(v->begin(), v->end(),
	     GT2(v2, 5));
}

void f(const vector<int> * const v, vector<int> * const v2)
{
    const int max = 5;
    
    for_each(v->begin(), v->end(),
	     [max, v2](int x) {if (x > max) v2->push_back(x); }); 
}

int main(int argc, char *argv[])
{
    const vector<int> v {0, 1, 6, 8};
    vector<int> v2;
    
    f(&v, &v2);
    for (auto& p : v2)
	cout << p;
    cout << endl;

    v2.clear();
    
    f3(&v, &v2);
    for (auto& p : v2)
	cout << p;
    cout << endl;

    return 0;
}
