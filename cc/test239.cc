#include <iostream>
#include <chrono>
#include <unistd.h>
using namespace std;
using namespace std::chrono;

using mil = duration<int, ratio<1,10*10*10>>;

int main()
{
    time_point<steady_clock> tp  =
	steady_clock::now() + seconds{3} + mil{1};
    cout << "start" << endl;
    while (steady_clock::now() < tp) {
	sleep(1);
    }
    cout << "done" << endl;

    time_point<steady_clock> tp2 = steady_clock::now();
    for (unsigned long i = 0; i < 1000000; ++i);
    time_point<steady_clock> tp3 = steady_clock::now();

    milliseconds ms = duration_cast<milliseconds>(tp3-tp2);
    cout << "ms : " << ms.count() << "\n";
    
    return 0;
}
