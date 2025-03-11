#include <iostream>
using namespace std;

enum class A { A_0, A_1 };

int main(int argc, char *argv[])
{
    A tag = A::A_0;

    switch (tag) {
    case A::A_0:
	cout << "A" << endl;
	break;
    case A::A_1:
	cout << "1" << endl;
	break;
    }
	
    
    return 0;
}
