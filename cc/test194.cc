// clang++ -std=c++11 -fno-elide-constructors -Wall -pedantic -g test194.cc && ./a.out
    
template<typename T> class Ptr
{
    T* p;
public:
    Ptr(T* t) : p{t} {}
    Ptr(const Ptr& r) {p = r.p;}
    // explicit means only participate in direct initialization
    // and explicit conversions.
    template<typename T2>
    explicit operator Ptr<T2>();
};

template<class T>
template<class T2>
Ptr<T>::operator Ptr<T2>()
{
    return Ptr<T2>{p};
}

class X {};
class Y : public X {};
int main(int argc, char *argv[])
{
    Y y;
    Ptr<Y> py{&y};
    Ptr<X> xp{py}; 
//    Ptr<X> xp2 = py; // copy initialization, implicit conversion
    Ptr<X> xp2 = static_cast<Ptr<X>>(py); // direct initialization
    Ptr<Y> yp2{xp}; // will fail

    return 0;
}
