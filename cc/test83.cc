#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <unistd.h>
using namespace std;

struct MSG {
    int val;
};

queue<MSG> mqueue;
condition_variable mcond;
mutex mmutex;
bool ready = false;

void consumer()
{
    while (true) {
	unique_lock<mutex> lck{mmutex};
	while (!ready)
	    mcond.wait(lck);
	ready = false;
	auto m = mqueue.front();    
	mqueue.pop();
	lck.unlock();
	cout << m.val << endl;
    }
}

void producer()
{
    MSG m = {0};

    while (true) {
	if (m.val > 100) {
	    return;
	}
	unique_lock<mutex> lck {mmutex};
	if (!ready) {
	    ready = true;
	    mqueue.push(m);
	    mcond.notify_one();
	    m.val++;
	}
    }
}

int main(int argc, char *argv[])
{
    thread tp {producer};
    thread tc {consumer};

    tp.join();
    tc.join();
  
    return 0;
}
