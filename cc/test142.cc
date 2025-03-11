#include <iostream>
#include <memory>
using namespace std;

int main(int argc, char *argv[])
{
    allocator<int> alloc;
    int* elem = alloc.allocate(20);
    int* end = elem + 20;

    uninitialized_fill(elem, end, int(5));

    for (int *p = elem; p != end; ++p)
	cout << *p << endl;
    
    return 0;
}
