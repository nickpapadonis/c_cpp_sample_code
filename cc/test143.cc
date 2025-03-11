// g++ -pedantic -Wall -std=c++11 -fno-elide-constructors -g test143.cc && ./a.out
#include <iostream>
#include <memory>
using namespace std;

template<typename T, typename A = allocator<T>>
struct vector_base {
    A alloc;	
    T* elem;	
    T* space;	
    T* last;	
    
    vector_base(const A& a, typename A::size_type n, typename A::size_type m = 0)
	: alloc{a}, elem{alloc.allocate(n + m)}, space{elem + n},
	  last{elem + n + m} { }
    ~vector_base() { alloc.deallocate(elem, last - elem); }

    vector_base(const vector_base&) = delete;
    vector_base& operator=(const vector_base&) = delete;

    vector_base(vector_base&&);	
    vector_base& operator=(vector_base&&);
};

template<typename T, typename A>
vector_base<T,A>::vector_base(vector_base&& a)
    : alloc{a.alloc},
      elem{a.elem},
      space{a.space},
      last{a.last}	
{
    a.elem = a.space = a.last = nullptr;
}

template<typename T, typename A>
vector_base<T,A>& vector_base<T,A>::operator=(vector_base&& a)
{
    swap(a.alloc,alloc);
    swap(a.elem,elem);
    swap(a.space,space);
    swap(a.last,last);

    return *this;
}

template<typename T, typename A = allocator<T> >
class vector {
    vector_base<T,A> vb;
    void destroy_elements();
public:
    using size_type = typename A::size_type ;

    explicit vector(size_type n, const T& val = T{}, const A& a = A{});

    vector(const vector& a);
    vector& operator=(const vector& a);	

    vector(vector&& a);	
    vector& operator=(vector&& a);

    ~vector() { destroy_elements(); }

    size_type size() const { return vb.space - vb.elem; }
    size_type capacity() const { return vb.last - vb.elem; }

    void reserve(size_type);

    void resize(size_type, const T& = {});
    void clear() { resize(0); }	
    void push_back(const T&);
    void print(void);
};

template<typename T, typename A>
void vector<T,A>::destroy_elements()
{
    for (T* p = vb.elem; p != vb.space; ++p)
	p->~T();
    vb.space = vb.elem;
}

template<typename T, typename A>
vector<T,A>::vector(size_type n, const T& val, const A& a)
    : vb{a,n}
{
    uninitialized_fill(vb.elem, vb.elem + n, val);
}

template<typename T, typename A>
vector<T,A>::vector(const vector<T,A>& a)
    : vb{a.vb.alloc, a.size()}
{
    uninitialized_copy(a.vb.elem, a.vb.space, vb.elem);
}

template<typename T, typename A>
vector<T,A>& vector<T,A>::operator=(const vector& a)
{
    vector temp {a};
    swap(*this, temp);
    return *this;
}

template<typename T, typename A>
vector<T,A>::vector(vector&& a)	
    : vb{move(a.vb)}
{
}

template<typename T, typename A>
vector<T,A>& vector<T,A>::operator=(vector&& a)
{
    //clear();
    // vb = move(a.vb);
    swap(vb, a.vb);
    return *this;
}

template<typename In, typename Out>
Out uninitialized_move(In b, In e, Out o)
{
    typedef typename std::iterator_traits<Out>::value_type T;
    for (; b != e; ++b, ++o) {
	new(static_cast<void*>(&*o)) T{move(*b)};
	b->~T();
    }
    return o;		 
}

template<typename T, typename A>
void vector<T,A>::reserve(size_type newalloc)
{
    if (newalloc <= capacity()) return;
    vector_base<T,A> b {vb.alloc, size(), newalloc - size()};
    uninitialized_move(vb.elem, vb.elem + size(), b.elem);
    swap(vb, b);	
}

template<typename In>
void destroy(In b, In e)
{
    typedef typename std::iterator_traits<In>::value_type T;
    for (; b != e; ++b)
	b->~T();
}

template<typename T, typename A>
void vector<T,A>::resize(size_type newsize, const T& val)
{
    reserve(newsize);
    if (size() < newsize)
	uninitialized_fill(vb.elem + size(), vb.elem + newsize, val);
    else
	destroy(vb.elem + newsize, vb.elem + size());
//    vb.space = vb.last = vb.elem + newsize;
    vb.space = vb.elem + newsize;
}


template<class T, typename A>
void vector<T,A>::push_back(const T& val)
{
    if (capacity() == size())
	reserve(size() ? 2*size() : 8);
    vb.alloc.construct(&vb.elem[size()], val);
    ++vb.space;	
}

template<class T, typename A>
void vector<T,A>::print(void)
{
    for (T* p = vb.elem; p != vb.space; ++p)
	cout << *p;
    cout << endl;
}

void test_vectorbase(void)
{
    // expected to call move constructor with rvalue but elided
    vector_base<int> vb1 = vector_base<int>(allocator<int>{}, 1);

    // force move constructor, no elide
    vector_base<int> vb2 = move(vector_base<int>(allocator<int>{}, 1));
    
    vector_base<int> vb0(allocator<int>{}, 1);
    // assign with rvalue, invoke move assignment
    vb0 = vector_base<int>(allocator<int>{}, 1);

    // vector_base<int> vb3{vb0}; // copy cons. deleted
    // vector_base<int> vb3 = vb0; // copy assign deleted
}

void test_vector(void)
{
    vector<int> v0{0};
    v0.push_back(9); v0.push_back(1); v0.push_back(1);
    v0.print();

    vector<int> v1{0};
    v1 = vector<int>{5, 7};
    v1.print();
    vector<int> v2{vector<int>{6,8}};
    v2.print();

    v0.resize(0);
}


int main(int argc, char *argv[])
{
    test_vector();
    
    return 0;
}
