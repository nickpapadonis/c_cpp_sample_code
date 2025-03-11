#include <iostream>
#include <thread>
#include <unistd.h>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

void f0(int x)
{
    cout << x << flush << '\n';
}

struct X {
    int i;
    X(int i) : i{i} {}
    void operator()() {cout << i << endl;}
};

void wait0()
{
    for (;;)
	this_thread::sleep_for(seconds{1});
}

int main()
{
    vector<thread> worker(10);
    for (int i=0; i!=worker.size(); ++i) {
	// thread tmp{f0, i};
	X x{i}; thread tmp{x};
	worker[i] = move(tmp);
    }

#if 0    
    for (int i=0; i!=worker.size(); ++i) {
	worker[i].join();
    }
#endif    
//    wait0();

    return 0;
}
