#include <iostream>
using namespace std;

typedef enum E {
    E_A = 1,
    E_B = 2,
    E_C = 4,
    E_D = 8
} E_t;

void f0(const int &ee)
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

void f1(E_t ee)
{
    switch (ee) {
    case E::E_A:
	cout << "E_A" << endl;
	break;
    case E::E_B:
	cout << "E_B" << endl;
	break;
    case E::E_C:
	cout << "E_C" << endl;
	break;
    case E::E_D:
	cout << "E_D" << endl;
	break;
    }
}

enum F {
    F_A,
    F_B
};

void f2(enum F fe)
{
    if (F::F_A == fe)
	cout << "F_A" << endl;
}

void f4(enum F fe)
{
    switch(fe) {
    case F::F_A:
	cout << "F_A" << endl;
	break;
    case F::F_B:
	cout << "F_B" << endl;
	break;
    }
}
	
int main(int argc, char *argv[])
{
    int ee = E::E_A | E::E_B | E::E_C;

    f0(ee);

    cout << endl;
    E_t eee = E::E_B;
    f1(eee);

    cout << endl;
    enum F fe = F::F_A;
    f2(fe);

    cout << endl;
    f4(fe);
    
    return 0;
}
