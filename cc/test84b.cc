// clang++ -pthread -pedantic -Wall -std=c++11 test84.cc && ./a.out
#include <iostream>
#include <thread>
#include <unistd.h>
#include <stdlib.h>
#include <future>
#include <functional>
#include <vector>
using namespace std;
using namespace std::chrono;

int f0(int i)
{
    return i;
}

int main(int argc, char *argv[])
{
    vector<packaged_task<int(int)>> vpt;

    for (int i = 0; i < 10; ++i) {
	vpt.emplace_back(&f0);
    }

    for (auto& r : vpt)
	r(0);

    for (auto& r : vpt) {
	future<int> f0 = r.get_future();
	cout << f0.get() << '\n';
    }

    return 0;
}
