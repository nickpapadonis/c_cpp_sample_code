#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <sstream>
#include <queue>
using namespace std;

mutex m0;
queue<int> iq;
queue<int> oq;
condition_variable cv;

#include <random>
using namespace std::chrono;
default_random_engine gen(random_device{}());
uniform_int_distribution<int> p{0, 50};

void workert()
{
    for (;;) {
	this_thread::sleep_for(milliseconds{p(gen)});
	unique_lock<mutex> ul0{m0};
	while (iq.empty())
	    cv.wait(ul0);
	while (!iq.empty()) {
	    oq.push(iq.front());
	    iq.pop();
	}
	ul0.unlock();
	cv.notify_one();
    }
}

int main()
{
    thread w{workert};
    thread w2{workert};
    thread w3{workert};

    for (int i = 0; i < 3; ++i) {
	for (int i = 0; i < 5; ++i) {
	    {
		lock_guard<mutex> lg0{m0};
		iq.push(i);
	    }
	    cv.notify_all();
	}
	{
	    unique_lock<mutex> ul0{m0};
	    while (oq.empty())
		cv.wait(ul0);
	    while (!oq.empty()) {
		cout << oq.front() << endl;
		oq.pop();
	    }
	}
    }
    
    w.join();w2.join();w3.join();
    return 0;
}
