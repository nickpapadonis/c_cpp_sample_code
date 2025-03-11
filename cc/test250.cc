#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    fstream f {"test250.txt", ios_base::in};

    for (string s; f >> s;)
	cout << s;
    
    return 0;
}
