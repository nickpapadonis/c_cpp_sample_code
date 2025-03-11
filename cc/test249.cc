#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main()
{
    string fname {"test249.txt"};
    fstream file {fname, ios_base::out | ios_base::trunc};

    file << "first line" << endl;
    file << "second line" << endl;

    file.close();
    file.open(fname, ios_base::in);

    for (string s; getline(file, s);)
	cout << s << endl;

    file.close();
    file.open(fname, ios_base::in);
    fstream file2 {"test249out.txt", ios_base::out | ios_base::trunc};
    for (char c; file.get(c);) {
	cout << c << endl;
	file2.put(c);
    }

    
    

    return 0;
}
