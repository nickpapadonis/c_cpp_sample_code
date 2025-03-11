#include <iostream>
#include <iterator>
#include <forward_list>
#include <vector>
#include <algorithm>
using namespace std;

template<typename Ran>
void sort_helper(Ran beg, Ran end, random_access_iterator_tag)
{
    sort(beg, end);
}

template<typename For>
void sort_helper(For beg, For end, forward_iterator_tag)
{
    //vector<decltype(*beg)> v {beg, end};
    vector<typename For::value_type> v {beg, end};
    sort(v.begin(), v.end());
    copy(v.begin(), v.end(), beg); 
}

template<typename C>
using Iterator_type = typename C::iterator;

template<typename Iter>
using Iterator_category = typename std::iterator_traits<Iter>::iterator_category;

template<typename C> void sort(C& c)
{
    using Iter = Iterator_type<C>; // ex. vector<int>::iterator
    sort_helper(c.begin(), c.end(), Iterator_category<Iter>{});
}

int main(int argc, char *argv[])
{
    forward_list<int> fl = {2, 1, 0};
    vector<int> v = {2, 1, 0};

    sort(fl);
    sort(v);

    for (auto p : fl)
	cout << p << endl;
    cout << endl;
    for (auto p : v)
	cout << p << endl;

    return 0;
}
