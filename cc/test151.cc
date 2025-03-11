#include <iostream>
#include <initializer_list>
using namespace std;

void f(initializer_list<int> il)
{
    for (size_t i=0; i < il.size(); ++i)
	cout << il.begin()[i];
    cout << endl;

    for (auto p=il.begin(); p != il.end(); ++p)
	cout << *p;
    cout << endl;
}

int main(int argc, char *argv[])
{
    initializer_list<int> il = {0, 2, 4};

    f(il);
    
    return 0;
}
