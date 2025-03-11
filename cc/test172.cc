#include <iostream>
#include <initializer_list>
using namespace std;
struct A {
    int x, y;
    void p(void) {}
};

template <class T>
struct B {
    T x, y, z;
    B(T, T);
    B(const initializer_list<T>&);
    void p(void);
};

template <class T>
B<T>::B(T a, T b)
{
    x = b; y = a; z = 0;
}

template <class T>
B<T>::B(const initializer_list<T>& l)
{
    int k = 0;
    cout << "in il" << endl;
    for (auto& e : l) {
	if (k == 0)
	    x = e;
	if (k == 1)
	    y = e;
	if (k == 2)
	    z = e;
	k++;
    }
	
}

template <class T>
void B<T>::p(void)
{
}

template <>
void B<int>::p(void)
{
    cout << "p(void)" << endl;
}

int main(int argc, char *argv[])
{
    A a0 {0, 1};
    A a1 = {0, 1};
    cout << a0.x << a0.y << endl;
    cout << a1.x << a1.y << endl;
    B<int> b0{0, 2};
    cout << b0.x << b0.y << b0.z << endl;
    B<int> b1(0, 3);
    cout << b1.x << b1.y << b1.z << endl;
    B<int> b5{0, 4, 5};
    cout << b5.x << b5.y << b5.z << endl;
    B<int> b2 = B<int>(0, 3);
    cout << b2.x << b2.y << b2.z << endl;

    return 0;
}
