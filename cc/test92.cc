#include <random>
#include <iostream>
#include <functional>
#include <vector>
#include <stddef.h>
using namespace std;

int main(int argc, char *argv[])
{
    using engine = default_random_engine;
    using distribution = uniform_int_distribution<>;

    random_device rd;  // for seed
    engine re{rd()};

    distribution dist {1,6};
    auto rand = bind(dist, re);

    vector<int> hist(7);
    
    for (int i=0; i<200; i++)
        ++hist[rand()];

    for (size_t i=1; i<hist.size(); i++) {
        cout << i << '\t';
        for (int j=0; j!=hist[i]; ++j)
            cout << '*';
        cout << endl;
    }
    
    return 0;
}
