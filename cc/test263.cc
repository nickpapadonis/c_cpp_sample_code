#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <list>
using namespace std;

template<typename T>
class SQ {
public:
    void put(const T& val);
    void put(T&& val);
    void get(T& val);  // T * const v;
private:
    mutex mtx;
    condition_variable cond;
    list<T> q;
};

template<typename T>
void SQ<T>::put(const T& val)
{
    {
//	lock_guard<mutex> lck(mtx);
	unique_lock<mutex> lck(mtx);
	while (q.size() > 1)
	    cond.wait(lck);
	q.push_back(val);
    }
    cond.notify_one();
}

#include <chrono>
using namespace std::chrono;
template<typename T>
void SQ<T>::get(T& val)
{
    unique_lock<mutex> lck(mtx);
    while (q.empty())
	cond.wait(lck);
    val = q.front();
    q.pop_front();
    lck.unlock();
    cond.notify_all();
}

struct MSG {
    int i;
};

SQ<MSG> mq;

#include <random>
using namespace std::chrono;
default_random_engine gen(random_device{}());
uniform_int_distribution<int> p{0, 50};

void producer()
{
    int i = 20;
    while (i) {
	MSG m{i--};
	mq.put(m);
	this_thread::sleep_for(milliseconds{p(gen)});
    }
}

mutex cout_lock;
void consumer()
{
    while (true) {
	MSG m;
	mq.get(m);
	{
	    lock_guard<mutex> l{cout_lock};
	    cout << this_thread::get_id() << ": " << m.i << '\n';
	}
	this_thread::sleep_for(milliseconds{p(gen)});
    }
}

int main()
{
    thread t0{consumer};
    thread t1{consumer};
    thread t2{consumer};
    thread t3{producer};

    t0.join(); t1.join(); t2.join(); t3.join();
    
    return 0;
}
