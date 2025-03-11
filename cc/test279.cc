#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

struct X {
    int sum;
    pair<int,int> p;
};

bool operator<(const X& a, const X& b)
{
    return a.sum < b.sum;
}

bool operator>(const X& a, const X& b)
{
    return a.sum > b.sum;
}

#include <tuple>
tuple<int, int, int> fmaxsub(vector<int>& v, int low, int high)
{
    vector<pair<int,int>> vp;

    for (int i=0; i<v.size(); ++i) {
	for (int j=i; j<v.size(); ++j) {
	    vp.push_back({i, j});
	}
    }

    vector<X> vx;
    for (auto& r : vp) {
	X x {};
	for (int i = r.first; i <= r.second; ++i) {
	    x.sum += v[i];
	}
	x.p = r;
	vx.push_back(x);
    }

    sort(vx.begin(), vx.end(), greater<X>());

    return {vx.begin()->p.first, vx.begin()->p.second,
	    vx.begin()->sum};
}

#include<chrono>
using namespace std::chrono;
int main()
{
    vector<int> v = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};

    auto start = high_resolution_clock::now();
    tuple<int, int, int> t = fmaxsub(v, 0, v.size() - 1);
    auto end = high_resolution_clock::now();

    microseconds td = duration_cast<microseconds>(end - start);
    cout << "usec: " << td.count() << '\n';
    
    cout << "low: " << get<0>(t) << " high: " << get<1>(t)
	 << " sum: " << get<2>(t) << '\n';

    return 0;
}
