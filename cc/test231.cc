#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> h {2, 9, 1, 6, 3, 10};
    vector<int> h2{h};
    
    make_heap(h.begin(), h.end());
    copy(h.begin(), h.end(), ostream_iterator<int>(cout, ","));
    cout << endl;

    cout << "max: ";
    while (h.begin() != h.end()) {
	pop_heap(h.begin(), h.end());
	cout << h.back() << ", ";
	h.pop_back();
    }
    cout << endl;
    for (auto& r : h2) {
	h.push_back(r);
	push_heap(h.begin(), h.end());
    }
    copy(h.begin(), h.end(), ostream_iterator<int>(cout, ","));
    cout << endl;
    
    return 0;
}
