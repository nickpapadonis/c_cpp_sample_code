#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void f1()
{
    queue<int> q{};
    q.push(0); q.push(1); q.push(2);
    while (!q.empty()) {
	cout << q.front() << endl;
	q.pop();
    }
}

void f0()
{
    stack<int> s{};
    s.push(0); s.push(1); s.push(2);
    while (!s.empty()) {
	cout << s.top() << endl;
	s.pop();
    }
}

int main()
{
    //f0();
    f1();
    return 0;
}
