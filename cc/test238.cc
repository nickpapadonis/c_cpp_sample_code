#include<memory>
using namespace std;

unique_ptr<int[]> make_sequence(int n)
{
    unique_ptr<int[]> p {new int[n]};
    for (int i=0; i<n; ++i)
	p[i]=i;
    return p;
}

int main()
{
    unique_ptr<int[]> up = make_sequence(1);
    return 0;
}
