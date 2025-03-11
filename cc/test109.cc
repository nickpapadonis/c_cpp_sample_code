#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    // smile emoji and aleph
    string str = u8"\U0001F600\u05d0";
    string str2 = u8"😀";
    // code point form of 0x0001F600
    // 11110xxx	10xxxxxx 10xxxxxx 10xxxxxx
    // 11110000 10011111 10011000 10000000
    // 3..6..0. 2..3..7. 2..3..0. 2..0..0.
    auto str3 = u8"\xf0\x9f\x98\x80";
    auto str4 = u8"\360\237\230\200";
    
    cout << str << endl;
    cout << str2 << endl;
    cout << str3 << endl;
    cout << str4 << endl;
    
    return 0;
}
