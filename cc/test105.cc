#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int *a = new int[2];
    int *p = a;
    
    for (int i=0; i<2; ++i)
	*p++ = i;

    p = a;
    
    for (int i=0; i<2; i++)
	cout << *p++ << " ";
    
    cout << endl;

    delete[] a;
    return 0;
}
