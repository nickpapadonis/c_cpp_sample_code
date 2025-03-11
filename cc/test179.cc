#include <vector>
#include <iostream>
using namespace std;

template<typename T>
void sort(vector<T>& v);

#if 0
template<>
void sort<int>(vector<int>& v)
{
    cout << "sort<int>" << endl;
}
#else
template<>
void sort(vector<int>& v)
{
    cout << "sort<int>1" << endl;
}
#endif


int main(int argc, char *argv[])
{
    vector<int> v;
    sort(v);
    return 0;
}
