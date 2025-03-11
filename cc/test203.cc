#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct X {
    X(int p) : priority{p} {}
    int priority;
    bool operator<(const X&) const;
};

bool X::operator<(const X& b) const
{
    return priority < b.priority;
}

struct X_less {
    bool operator()(const X&, const X&) const;
};
bool X_less::operator()(const X& a, const X& b) const
{
    return a.priority < b.priority;
}

int main()
{
    vector<X> v = {X{9}, X{1}, X{2}, X{5}};
#if 0
    priority_queue<X, vector<X>,
		   bool(*)(const X&, const X&)> p{v.begin(), v.end(),
       +[](const X& a, const X& b){return a.priority < b.priority;}};
#endif
    priority_queue<X, vector<X>, X_less> p{v.begin(), v.end(), X_less{}, vector<X>{}};
						  
    p.push(X{20});
    while (!p.empty()) {
	X xx = p.top();
	p.pop();
	cout << xx.priority << endl;
    }
    
    return 0;
}
