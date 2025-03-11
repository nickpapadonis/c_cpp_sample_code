#include <string>
using namespace std;

template<typename T>
T f(T a)
{
    return int{};
}


int main(int argc, char *argv[])
{
    const string a = "";
    string z = f<string>(a);
    return 0;
}
