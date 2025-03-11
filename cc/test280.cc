#include <tuple>
#include <iostream>
using namespace std;

int main()
{
    int i = 3 / 2;
    cout << i << '\n';
    
    tuple<int, int, int> t{0, 1, 2};

    cout << get<0>(t) << '\n';
    cout << get<1>(t) << '\n';
    cout << get<2>(t) << '\n';
    
    return 0;
}
