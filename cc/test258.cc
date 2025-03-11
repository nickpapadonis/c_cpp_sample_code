#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include <random>
using namespace std;
using namespace std::chrono;

struct WT {
    static mutex m0;
    default_random_engine& gen;
    uniform_int_distribution<int>& p;

    WT(default_random_engine& gen,
       uniform_int_distribution<int>& p) : gen{gen}, p{p} {}
    void operator()(int i); 
};

mutex WT::m0;

void WT::operator()(int i)
{
    this_thread::sleep_for(milliseconds{p(gen)});
    {
	lock_guard<mutex> lg {m0};
	thread::id id0 = this_thread::get_id();
	cout << "id: " << id0 << '\n';
	while (i--) {
	    cout << i << '\n';
	}
    }
}

int main()
{
    vector<thread> v0;
    default_random_engine gen{random_device{}()};
    uniform_int_distribution<int> p{0, 75};

    WT wt{gen, p};
    for (int i = 0; i < 5; ++i)
	v0.push_back(thread{wt, 5});

    for (auto& r : v0)
	r.join();

    return 0;
}
