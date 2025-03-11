#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <unistd.h>
#include <stdlib.h>
using namespace std;
using namespace std::chrono;

struct MSG {
    int val;
};

queue<MSG> mqueue;
condition_variable mcond;
mutex mmutex;
bool ready = false;

void consumer()
{
    queue<MSG> fillq;
    while (true) {
	this_thread::sleep_for(milliseconds{rand() % 25});
	unique_lock<mutex> lck{mmutex};
	while (!ready)
	    mcond.wait(lck); // rel lock and wait, reacq on wakeup
	// drain queue
	while (!mqueue.empty()) {
	    auto m = mqueue.front();    
	    mqueue.pop();
	    fillq.push(m);
	}
	ready = false;
	lck.unlock();

	// stdout
	while(!fillq.empty()) {
	    auto m = fillq.front();
	    fillq.pop();
	    cout << m.val << endl;
	}
    }
}

void producer()
{
    MSG m = {0};

    while (true) {
	if (m.val > 100) {
	    return;
	}
	this_thread::sleep_for(milliseconds{rand() % 25});
	unique_lock<mutex> lck {mmutex};
	mqueue.push(m);
	ready = true;
	mcond.notify_one(); // notify
	lck.unlock();
	m.val++;	
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
