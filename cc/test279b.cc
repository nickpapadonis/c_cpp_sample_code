#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
#include <limits>
using namespace std;

tuple<int, int, int> fmaxcross(vector<int> &v, int low, int mid, int high)
{
    int leftsum = numeric_limits<int>::min();
    int maxleft;
    int sum = 0;
    for (int i = mid; i >= low; --i) {
	sum = sum + v[i];
	if (sum > leftsum) {
	    leftsum = sum;
	    maxleft = i;
	}
    }
    int rightsum = numeric_limits<int>::min();
    int maxright;
    sum = 0;
    for (int i = mid + 1; i <= high; ++i) {
	sum = sum + v[i];
	if (sum > rightsum) {
	    rightsum = sum;
	    maxright = i;
	}
    }
    
    return {maxleft, maxright, leftsum + rightsum};
}

tuple<int, int, int> fmaxsub(vector<int> &v, int low, int high)
{
    if (low == high)
	return {low, high, v[high]};

    int mid = (high + low) / 2;
    tuple<int, int, int> tl = fmaxsub(v, low, mid);
    tuple<int, int, int> tr = fmaxsub(v, mid + 1, high);
    tuple<int, int, int> tc = fmaxcross(v, low, mid, high);

    if (get<2>(tl) > get<2>(tr) && get<2>(tl) > get<2>(tc))
	return tl;
    if (get<2>(tr) > get<2>(tl) && get<2>(tr) > get<2>(tc))
	return tr;
    return tc;
}

#include <chrono>
using namespace std::chrono;
int main()
{
    vector<int> v = {13, -3, -25, 20, -3, -16, -23, 18,
		     20, -7, 12, -5, -22, 15, -4, 7};

    auto start = high_resolution_clock::now();
    tuple<int, int, int> tpl = fmaxsub(v, 0, v.size() - 1);
    auto end = high_resolution_clock::now();

    microseconds td = duration_cast<microseconds>(end - start);
    cout << "usec: " << td.count() << '\n';
    
    cout << "start: " << get<0>(tpl) << ", end: " << get<1>(tpl) <<
	" sum: " << get<2>(tpl) << '\n';
    
    return 0;
}
