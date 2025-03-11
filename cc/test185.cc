#include <iostream>
using namespace std;

template<typename T> T f(T a) {
    return g(a);
}

namespace z {
    class Q {};
    z::Q g(z::Q e) { return e; }
}

int main() {
    (void) f(z::Q{});
    return 0;
}
