// best random
#include <iostream>
#include <map>
#include <random>

int main()
{
    std::mt19937 gen(std::random_device{}());  // default_random_engine
    std::uniform_int_distribution<int> p{0, 9};

    std::map<int, int> m;
    for (int i = 0; i < 100; ++i) {
	m[p(gen)]++;
    }

    for (auto it = m.begin(); it != m.end(); ++it) {
	std::cout << it->first << ", " << it->second << '\n';
    }

    return 0;
}
