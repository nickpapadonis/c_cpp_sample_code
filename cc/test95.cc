#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

int main(int argc, char *argv[])
{
    cout << static_cast<int>(numeric_limits<char>::max()) << endl;
    cout << static_cast<int>(numeric_limits<unsigned char>::max()) << endl;
    cout << endl;
    
    unsigned char c = 1256 & (((unsigned char) pow(2, 8)) - 1);
    cout << (int) c << endl;
    cout << endl;
    
    c = 1256 & 0xFF;
    cout << (int) c << endl;
	     
    return 0;
}
