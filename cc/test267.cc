#include<sstream>
#include<iostream>
using namespace std;

int main()
{
    istringstream is{"300"};
    int i;
    is >> i;
    cout << i;
    return 0;
}
