#include<iostream>
#include<sstream>
using namespace std;

int fib(int x)
{
    if (x == 0)
	return 0;
    if (x == 1)
	return 1;
    return fib(x - 2) + fib(x -1);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
	return 1;
    istringstream ss{argv[1]};
    int fn;
    ss >> fn;

    for (int i = 0; i < fn; ++i)
	cout << fib(i) << ',';
    
    return 0;
}
