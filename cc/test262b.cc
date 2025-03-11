#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <list>
#include <future>
#include <utility>
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
void SQ<T>::put(T&& val)
{
    {
        unique_lock<mutex> lck(mtx);
        while (q.size() > 3) // no q bigger than
            cond.wait(lck);
        q.push_back(forward<T&&>(val));
    }
    cond.notify_one();
}

template<typename T>
void SQ<T>::put(const T& val)
{
    {
        unique_lock<mutex> lck(mtx);
        while (q.size() > 3) // no q bigger than
            cond.wait(lck);
        q.push_back(val);
    }
    cond.notify_one();
}

template<typename T>
void SQ<T>::get(T& val)
{
    unique_lock<mutex> lck(mtx);
    while (q.empty())
        cond.wait(lck);
    val = move(q.front());
    q.pop_front();
    lck.unlock();
    cond.notify_all();
}

SQ<packaged_task<int(int)>> mq;

#include <random>
#include <chrono>
using namespace std::chrono;
default_random_engine gen(random_device{}());
uniform_int_distribution<int> p{0, 50};

int f(int i) { return i; }

void producer()
{
    vector<future<int>> fv;
    int i = 5;
    while (i--) {
        packaged_task<int(int)> pt {f};
        fv.push_back(pt.get_future());
        mq.put(move(pt));
        this_thread::sleep_for(milliseconds{p(gen)});
    }

    // get the results
    for (auto& p : fv)
        cout << "res : " << p.get() << '\n';
}

mutex cout_lock;
void consumer()
{
    while (true) {
        packaged_task<int(int)> pt;
        mq.get(pt);
        {
            //lock_guard<mutex> l{cout_lock};
            //cout << this_thread::get_id() << ": " << '\n';
        }
        this_thread::sleep_for(milliseconds{p(gen)});
        pt(0);
    }
}

int main()
{
    thread t0{consumer};
    thread t1{producer};

    t0.join(); t1.join();
    
    return 0;
}
