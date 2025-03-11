#include <iostream>
using namespace std;

enum class E {
    E_A = 1,
    E_B = 2,
    E_C = 4,
    E_D = 8
};

constexpr E operator|(E a, E b)
{
    return static_cast<E>(static_cast<int>(a)|static_cast<int>(b));
}

constexpr int operator&(E a, E b)
{
    return static_cast<int>(static_cast<int>(a)&static_cast<int>(b));
}

void f0(const E &ee)
{
    if (ee & E::E_A)
	cout << "E_A" << endl;
    if (ee & E::E_B)
	cout << "E_B" << endl;
    if (ee & E::E_C)
	cout << "E_C" << endl;
    if (ee & E::E_D)
	cout << "E_D" << endl;
}

int main(int argc, char *argv[])
{
    E ee = E::E_A | E::E_B | E::E_C;

    f0(ee);
    
    return 0;
}
