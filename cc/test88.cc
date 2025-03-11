#include <iostream>
#include <memory>
#include <thread>
#include <numeric>
#include <vector>
#include <future>
#include <chrono>
using namespace std;
using namespace std::chrono;

// use of async
double comp2(vector<double>& v, int parts) {
    vector<future<double>> fv;

    int ilast = 0;
    for (int i = 1; i <= parts; i++) {
	fv.push_back(async(accumulate<vector<double>::iterator, double>,
			   v.begin() + v.size() * ((double) (i - 1) / parts),
			   v.begin() + v.size() * ((double) i / parts), 0));
    }

    double accum = 0;
    for (auto &p : fv)
	accum += p.get();

    return accum;
}

int main(int argc, char *argv[])
{
    vector<double> v;

    for (int i=0; i<20000000; i++)
	v.push_back(1.0);

    system_clock::time_point t0 = high_resolution_clock::now();
    cout << "v: " << comp2(v, 1) << endl;
    system_clock::time_point t1 = high_resolution_clock::now();
    cout << duration_cast<milliseconds>(t1-t0).count() << "msec\n";
    
    auto t2 = high_resolution_clock::now();
    cout << "v: " << comp2(v, 10) << endl;
    auto t3 = high_resolution_clock::now();
    cout << duration_cast<milliseconds>(t3-t2).count() << "msec\n";
    
    return 0;
}
