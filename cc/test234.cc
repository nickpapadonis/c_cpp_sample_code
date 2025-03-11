#include <functional>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct X {
    void draw() {cout << "x" << endl;}
};

void draw_all(vector<X*>& v)
{
    for_each(v.begin(), v.end(), mem_fn(&X::draw));
}

void draw_all2(vector<X>& v)
{
    for_each(v.begin(), v.end(), mem_fn(&X::draw));
}

void draw_all3(vector<X*>& v)
{
    for_each(v.begin(), v.end(), [](X* x){x->draw();});
}

void draw_all4(vector<X>& v)
{
    for_each(v.begin(), v.end(), [](X& x){x.draw();});
}

int main()
{
    vector<X*> v {new X{}};
    draw_all(v);
    draw_all3(v);
    
    vector<X> v2 {X{}};
    draw_all2(v2);
    draw_all4(v2);
    
    return 0;
}
