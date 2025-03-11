// clang++ -pthread -pedantic -Wall -std=c++11 test84.cc && ./a.out
#include <iostream>
#include <thread>
#include <unistd.h>
#include <stdlib.h>
#include <future>
#include <functional>
#include <vector>
using namespace std;
using namespace std::chrono;

struct MSG {
    int val;
};

void consumer(vector<future<MSG>> *futv)
{
    for (auto& p : *futv) {
	this_thread::sleep_for(milliseconds{rand() % 25});
	MSG m = p.get();
	cout << m.val << endl;
    }
}

void producer(vector<promise<MSG>> *promv)
c{
    MSG m = {0};

    for (auto& p : *promv) {
	this_thread::sleep_for(milliseconds{rand() % 25});
	p.set_value(m);
	m.val++;
    }
}


int main(int argc, char *argv[])
{
    vector<promise<MSG>> promv;
    vector<future<MSG>> futv;

    for (int i=0; i<10; i++) {
	promv.push_back(promise<MSG>());
	futv.push_back(promv[i].get_future());
    }

    thread tp {producer, &promv};
    this_thread::sleep_for(seconds{1});
    thread tc {consumer, &futv};

    tp.join();
    tc.join();
  
    return 0;
}
