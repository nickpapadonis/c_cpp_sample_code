#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// template<class InputIterator, class OutputIterator>
//   OutputIterator move (InputIterator first, InputIterator last, OutputIterator result)
// {
//   while (first!=last) {
//     *result = std::move(*first);
//     ++result; ++first;
//   }
//   return result;
// }

// template<typename T> void swap(T& t1, T& t2) {
//     T temp = std::move(t1); // or T temp(std::move(t1));
//     t1 = std::move(t2);
//     t2 = std::move(temp);
// }

struct X {
    int i;
    X() {}
    X(int ii) : i{ii} {}
    
    X(const X& x) : i{x.i} {} 
    X(X&& x) : i{x.i} {x.i = 0;}
    X& operator=(const X& x)
	{X tmp{x}; swap(*this, tmp); return *this;}
    X& operator=(X&& x) {swap(i, x.i); return *this;}
};

ostream& operator<<(ostream& os, const X& x)
{
    return os << x.i;
}

int main()
{
    vector<X> v0 {X{0}, X{1}, X{2}};
    vector<X> v1 {X{6}, X{6}, X{6}};

    move(v0.begin(), v0.end(), v1.begin());

    for (auto& r : v0)
	cout << r;
    cout << endl;
    
    return 0;
}
