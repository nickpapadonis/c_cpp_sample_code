#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <sstream>
using namespace std;

mutex m0;
condition_variable cv;
bool ready = false;
bool processed = false;
string data;

#include <random>
using namespace std::chrono;
default_random_engine gen(random_device{}());
uniform_int_distribution<int> p{0, 50};

void workert()
{
    for (;;) {
	this_thread::sleep_for(milliseconds{p(gen)});
	unique_lock<mutex> ul0{m0};
	while (!ready)
	    cv.wait(ul0);
	ready = false;
	ostringstream s;
	s << "<data:" << this_thread::get_id() << ">";
	data += s.str();
	processed = true;
	ul0.unlock();
	cv.notify_one();
    }
}

int main()
{
    data = "<datas>";
    thread w{workert};
    thread w2{workert};
    thread w3{workert};

    for (int i = 0; i < 3; ++i) {
	{
	    lock_guard<mutex> lg0{m0};
	    ready = true;
	}
	cv.notify_all();
	{
	    unique_lock<mutex> ul0{m0};
	    while (!processed)
		cv.wait(ul0);
	    processed = false;
	}
	cout << data << '\n';
    }
    
    w.join();w2.join();w3.join();
    return 0;
}
