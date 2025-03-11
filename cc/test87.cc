#include <iostream>
#include <memory>
#include <thread>
#include <numeric>
#include <vector>
#include <future>
using namespace std;

double comp2(vector<double>& v) {
    using Task_type = double(vector<double>::iterator,
			     vector<double>::iterator, double);

    packaged_task<Task_type> pt0
	{accumulate<vector<double>::iterator, double>};
    packaged_task<Task_type> pt1
	{accumulate<vector<double>::iterator, double>};

    future<double> f0 {pt0.get_future()};
    future<double> f1 {pt1.get_future()};

    auto first = v.begin();
    // move required bc package_task cannot be copied
    thread t1 {move(pt0), first, first + v.size()/2, 0};
    thread t2 {move(pt1), first + v.size()/2, first + v.size(), 0};
  
    t1.join();
    t2.join();

    return f0.get() + f1.get();
}

int main(int argc, char *argv[])
{
    vector<double> v;

    for (int i=0; i<2000; i++)
	v.push_back(1.0);

    cout << "v: " << comp2(v) << endl;

    return 0;
}
