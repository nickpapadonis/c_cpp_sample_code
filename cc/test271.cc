#include<iostream>
#include<sstream>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
	return 1;
    istringstream ss{argv[1]};
    int fn;
    ss >> fn;

    int a = 0, b = 1;
    for (int x = 0; x < fn; ++x)
    {
	cout << a << ",";
	int atmp = a;
	a = b;
	b = atmp + b;
    }
    
    return 0;
}
