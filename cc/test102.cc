#include <iostream>
#include <vector>
using namespace std;

template<typename T> void f1(const vector<T>& arg)
{
    for (typename vector<T>::const_iterator p = arg.begin();
	 p != arg.end();
	 ++p)
	cout << *p << endl;

    for (const auto p : arg)
	cout << p << endl;

    for (const auto& p : arg)
	cout << p << endl;

}

int main(int argc, char *argv[])
{
    const vector<int> v = {0, 1};

    f1<int>(v);
    
    return 0;
}
