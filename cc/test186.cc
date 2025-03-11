template<typename T> T f(T a) {
    // Can find ::ns::g(Q) only via ADL on T for
    // an instantiation of f with T == ::ns::Q.
    return g(a);
}

namespace ns {

class Q {};

Q g(Q e) { return e; }

}  // namespace ns

int main() {
    (void) f(::ns::Q{});
    return 0;
}
