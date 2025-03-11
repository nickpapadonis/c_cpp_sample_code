#include <vector>
#include <iostream>
using namespace std;

class X {
public:
    virtual void draw() = 0;
    virtual ~X() {};
};

class Y : public X {
public:
    void draw() {cout << "..." << endl;}
    ~Y() {}
};

int main()
{
    vector<X*> v {new Y(), new Y()};
    
    v.front()->draw();
    
    return 0;
}
