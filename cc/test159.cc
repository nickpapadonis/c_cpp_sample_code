#include <iostream>
using namespace std;

// variadic template

// 201_b3 // means operator"" b3<’2’,’0’,’1’>(); so 9*2+0*3+1 == 19
// 241_b3 // means operator"" b3<’2’,’4’,’1’>(); so error: 4 isn’t a ternary digit

constexpr int ipow(int x, int n)
{
    return n>0?x*ipow(x,n-1):1;
}

template<char...> struct helper;
template<char c>
struct helper<c> {
    static_assert('0'<=c&&c<'3',"not a ternary digit");
    static constexpr int value() { return c-'0'; }
};

template<char c, char... tail>
struct helper<c, tail...> {
    
    static constexpr int value() { static_assert('0'<=c&&c<'3',"not a ternary digit"); return (c-'0')*ipow(3,sizeof...(tail)) + helper<tail...>::value(); }
};

template<char... chars>
constexpr int operator"" _b3()
{
    return helper<chars...>::value();
}

int main(int argc, char *argv[])
{
    cout << 201_b3 << endl;
    return 0;
}
