#include <iostream>
#include <vector>
using namespace std;

namespace std2 {
    // primary
    template<class It>
    void sort(It b, It e)
    {cout << "s0" << endl;}

#if 0
    // specialization
    template<>
    void sort(typename std::vector<std::string>::iterator b,
	      typename std::vector<std::string>::iterator e)
    {cout << "s1" << endl;}
#endif

#if 0
    // overloading
    void sort(typename std::vector<string>::iterator b,
	      typename std::vector<string>::iterator e)
    {cout << "s2" << endl;}
#endif
}

template<typename T>
void print_sorted(std::vector<T>& v)
{
    sort(v.begin(),v.end());
    for (const auto& x : v)
	std::cout << x << '\n';
}

#include <algorithm> // will cause redef of sort

int main(int argc, char *argv[])
{
    std::vector<std::string> v = {"b", "a"};
    print_sorted(v);
    return 0;
}
// point of instantiation

//#include <algorithm> : point of instantiation end of TU
