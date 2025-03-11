#include <random>
#include <iostream>
#include <functional>
#include <vector>
#include <stddef.h>
using namespace std;

class Rand_int {
public:
    Rand_int(int low, int high) :engn{dev()}, dist{low,high} { }
    int operator()() { return dist(engn); } // draw an int
private:
    random_device dev; // seed
    default_random_engine engn;
    uniform_int_distribution<> dist;
};

int main(int argc, char *argv[])
{
    Rand_int rnd{1, 6};
    
    vector<int> hist(7);
    
    for (int i=0; i<200; i++)
        ++hist[rnd()];

    for (size_t i=1; i<hist.size(); i++) {
        cout << i << '\t';
        for (int j=0; j!=hist[i]; ++j)
            cout << '*';
        cout << endl;
    }
    
    return 0;
}
