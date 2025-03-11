#include <iostream>
#include <vector>
using namespace std;

struct X {
    int a, b;
};

void f(const vector<int>& v)
{
}

void f2(const X& xxx)
{
}

int main(int argc, char *argv[])
{
    vector<int> v0 {0, 1, 2}; // const by init list
    vector<int> v1 = {0, 1, 2}; // assign by init list
    vector<int> v2 = vector<int>{0, 1, 2}; // asign operator from temp
    vector<int> v3(3);
    v3 = {0, 1, 2};
    vector<int> *pv = new vector<int>(3);
    f(vector<int>{0, 1, 2});
    delete pv;

    X x = {0, 1};
    X xx{0, 1};
    f2(X{2, 3});
    
    return 0;
}
      
