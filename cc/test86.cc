#include <iostream>
#include <memory>
#include <thread>
#include <numeric>
#include <vector>
#include <future>
using namespace std;

double accum(double *beg, double *end, double init)
{
    return accumulate(beg, end, init);
}

double comp2(vector<double>& v)
{
    using Task_type = double(double*, double*, double);

    packaged_task<Task_type> pt0 {accum};
    packaged_task<Task_type> pt1 {accum};

    future<double> f0 {pt0.get_future()};
    future<double> f1 {pt1.get_future()};

    double *first = &v[0];
    // move required bc package_task cannot be copied
    thread t1 {move(pt0), first, first + v.size()/2, 0};
    thread t2 {move(pt1), first + v.size()/2, first + v.size(), 0};

    t1.join();
    t2.join();
  
    return f0.get() + f1.get();
}

int main(int argc, char *argv[])
{
    vector<double> v = {1.0, 1.0, 1.0, 1.0};

    cout << "v: " << comp2(v) << endl;

    return 0;
}
