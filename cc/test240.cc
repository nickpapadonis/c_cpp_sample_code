#include <type_traits>
#include <iostream>
using namespace std;

class Z {
};
class X : public Z {
};
class Y : public Z {
};

int main()
{
    common_type<X,Z>::type p;
    return 0;
}
     
