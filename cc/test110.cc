#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    char a[] = "abcd";

    // prints null character too
    for (auto& p : a)
	cout << p;
    cout << endl;
    
    return 0;
}
