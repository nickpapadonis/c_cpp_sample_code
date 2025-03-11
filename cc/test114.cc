#include <iostream>

template <typename T,typename V>
T create(V& a)
{
  return T(a);
}

template <typename T,typename V>
T create(const V& a)
{
  return T(a);
}

int main(int argc, char *argv[])
{
    int i = 0;

    create<int>(i);
    create<int>(0);
    
    return 0;
}
