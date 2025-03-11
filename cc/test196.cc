#include <iostream>
using namespace std;

template<class T>
constexpr bool TO();

template<typename N>
struct B {
    static_assert(TO<N>(), "bad");
    N* left;
    N* right;
    B() {}
    void insert(N& n);
    void f0(N* p) {}
};

template<typename N>
void B<N>::insert(N& n)
{
}

template<typename Val>
struct Y : B<Y<Val>> {
    Val v;
    Y(Val vv) : v{vv} {}
    bool operator<(const Y<Val>& b) {return v < b.val;}
};

template<>
constexpr bool TO<Y<int>>() { return true; }

int main(int argc, char *argv[])
{
    static_assert(TO<Y<int>>(), "bad");

    Y<int> yy{0};
    yy.left = new Y<int>{1};
    yy.right = new Y<int>{2};
    yy.f0(&yy);

    
    
    yy.left->left = new Y<int>{3};
    return 0;
}
