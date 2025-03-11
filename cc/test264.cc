#include<iostream>
#include<thread>
#include<future>
#include<vector>
#include<random>
#include<chrono>
using namespace std;
using namespace std::chrono;

default_random_engine gen(random_device{}());
uniform_int_distribution<int> p{0, 10};

int f0(const vector<int> v)
{
    unsigned int res = 0;
    for (auto& r : v) {
	this_thread::sleep_for(milliseconds{p(gen)});
	res += r;
    }
    return res;
}

int main()
{
    vector<int> v;
    for (int i = 0; i < 100; ++i)
	v.push_back(1);
    
    future<int> f = async(f0, v);
    int r = f.get();
    cout << r << '\n';
    int i = 666;
    future<int> f2 = async([i](){return i;});
    cout << f2.get() << '\n';
    return 0;
}
