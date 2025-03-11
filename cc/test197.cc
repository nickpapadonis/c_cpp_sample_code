#include <type_traits>
using namespace std;

template<bool B, typename T>
using Enable_if = typename std::enable_if<B,T>::type;

struct X {
    template <class T>
    Enable_if<false, T> f0(int x) {};
    template <class T>
    Enable_if<true, T> f0(int x) {};
};

int main(void)
{
    X xx;
    xx.f0<void>(0);
    return 0;
}
