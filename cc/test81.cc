#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
#include <unistd.h>
using namespace std;

struct A {
  int x;
  int y;
};

struct B {
  void operator()(){ cout << "B()\n"; };
};

void f0(void)
{
  unique_ptr<A> p {new A};

  p->x = 0;
  p->y = 1;
  cout << "f0()\n";
}

unique_ptr<A> f1(void)
{
  cout << "f1()\n";
  return unique_ptr<A>{new A};
}

void f2(void)
{
  unique_ptr<A> sp = f1();
  cout << "f2()\n";
  return; // sp destroyed
}

mutex m;


int tmt(string name)
{
  static int i = 10;
#ifdef IMPLICIT
  unique_lock<mutex> lock{m};
#else
  m.lock();
#endif
  if (i == 0)
    return i;
  i--;
  cout << "i: " << i << " " << name << endl;
#ifndef IMPLICIT
  m.unlock();
#endif
  return i;
}

#include <stdlib.h>
void tmw(string name)
{
  for (;;) {
    usleep(rand() % 100000);
    if (tmt(name) < 1)
      break;
  }
}

int main(int argc, char *argv[])
{
  thread t1 {f0};
  thread t2 {f2};
  thread t3 {B()};

  t1.join();
  t2.join();
  t3.join();

  thread t4 {tmw,"a"};
  thread t5 {tmw,"b"};
  thread t6 {tmw,"c"};
  thread t7 {tmw,"d"};

  t4.join();
  t5.join();
  t6.join();
  t7.join();
  
  return 0;
}
