#include <iostream>
using namespace std;

template<typename F>
struct FinalAct {
    FinalAct(F f): clean{f} {}
    ~FinalAct() { clean(); }
    F clean;
};

template<class F>
FinalAct<F> finally(F f)
{
    return FinalAct<F>(f);
}

void f(void)
{
    auto act = finally([&](){cout << "finally0" << endl;});
    {
	auto act = finally([&](){cout << "finally1" << endl;});
    }
}

int main(int argc, char *argv[])
{
    f();
    
    return 0;
}
