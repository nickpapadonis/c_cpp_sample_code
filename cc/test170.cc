class Pool { 
    int t;
public:    
#if 0
    template<typename T>
    T* get() {return &t;}
#endif
    int* get() {return &t;}
};

template<typename Alloc>
void f(Alloc& all)
{
    //int* p1 = all.get<int>();
    //int* p2 = all.template get<int>();
    int* p2 = all.get();
}

void user(Pool& pool)
{ 
    f(pool);
}

int main(int argc, char *argv[])
{
    return 0;
}
