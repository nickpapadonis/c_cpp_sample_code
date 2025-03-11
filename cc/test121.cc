#include <iostream>
using namespace std;

const char *error(int i)
{
    switch (i) {
    case 0:
	return "Error 0";
    default:
	return 0;
    }
}
	
int main(int argc, char *argv[])
{
    if (const char *p = error(1))
	cout << p << endl;
    else
	cout << "invalid error" << endl;
	
    
    return 0;
}
