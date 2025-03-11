#define B
#define B1
#ifdef A
class Quad { };
Quad g(Quad e) {return e;}
#endif

template<typename T> T f(T a)
{
    return g(a); // OK: a is a dependent name and therefore so is g
}

#ifdef B
class Quad { };
#ifdef B0
Quad g(Quad e) {return e;}
#endif
#ifdef B1
template<class T>
Quad g(T e) {return e;}
template<>
Quad g<Quad>(Quad e) {return e;}
#endif
#endif

int main(int argc, char *argv[])
{
    Quad z = f(Quad{}); // f’s g is bound to g(Quad)
}

