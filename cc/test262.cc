#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
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
    queue<T> q;
};

template<typename T>
void SQ<T>::put(const T& val)
{
    {
        unique_lock<mutex> lck(mtx);
        while (q.size() > 3) // no q bigger than
            cond.wait(lck);
        q.push(val);
    }
    cond.notify_one();
}

template<typename T>
void SQ<T>::put(T&& val)
{
    {
        unique_lock<mutex> lck(mtx);
        while (q.size() > 3) // no q bigger than
            cond.wait(lck);
        q.push(forward<T&&>(val));
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
    q.pop();
    lck.unlock();
    cond.notify_all();
}

struct QP {
    packaged_task<int(int)> pt;
};

SQ<QP> mq;

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
        QP m{packaged_task<int(int)>{f}};
        fv.push_back(m.pt.get_future());
        mq.put(move(m));
        this_thread::sleep_for(milliseconds{p(gen)});
    }

    // get the results
    for (auto& p : fv)
        cout << p.get() << '\n';
}

mutex cout_lock;
void consumer()
{
    int i = 0;
    while (true) {
        QP m;
        mq.get(m);
#if 0
        {
            lock_guard<mutex> l{cout_lock};
            cout << this_thread::get_id() << ": " << '\n';
        }
#endif
        this_thread::sleep_for(milliseconds{p(gen)});
        m.pt(i++);
    }
}

int main()
{
    thread t0{consumer};
    thread t1{producer};

    t0.join(); t1.join();
    
    return 0;
}
