#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    cout << int((signed char)   (0b00000000)) << endl; // 0
    cout << int((signed char)   (0b01111111)) << endl; // 127
    cout << int((signed char)   (0b10000000)) << endl; // -128
    cout << int((unsigned char) (0b10000000)) << endl; // 128
    cout << int((signed char)   (0b10000001)) << endl; // -127
    cout << int((signed char)   (0b11111111)) << endl; // -1
    cout << int((unsigned char) (0b11111111)) << endl; // 255
    cout << endl;

    signed char sc = -140;
    cout << "signed int = " <<
	int((signed int) (0b11111111111111111111111101110100))
	 << endl; // -140, 4 bytes
    cout << "signed int & 0xFF = " <<
	int((signed int) -140 & 0xFF)
	 << endl; // 116, narrow 2 bytes
    cout << "signed char = " <<
	int((signed char) (0b01110100)) << endl; // 116, narow 2 bytes
    cout << int(sc) << endl;
    unsigned char uc = sc; // -140 % 256 = 116
    cout << int(uc) << endl;

    cout << endl;
    cout << "sizeof(char) = " << sizeof(char) << endl;
    cout << "sizeof(short) = " << sizeof(short) << endl;
    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(long) = " << sizeof(long) << endl;
    cout << "sizeof(long long) = " << sizeof(long long) << endl;
    cout << "sizeof(float) = " << sizeof(float) << endl;
    cout << "sizeof(double) = " << sizeof(double) << endl;
    cout << "sizeof(long double) = " << sizeof(long double) << endl;
    
    return 0;
}
