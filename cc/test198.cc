#include <iostream>
using namespace std;

void printz(const char* s)
{
    if (s==nullptr) return;
    while (*s) {
	if (*s=='%' && *++s!='%') 
	    throw runtime_error("invalid format: missing arguments");
	std::cout << *s++;
    }
}

template<typename T, typename... Args>
void printz(const char* s, T value, Args... args) 
{
    while (s && *s) {
	if (*s=='%' && *++s!='%') {
	    std::cout << value;
	    return printz(s, args...);
	}
	std::cout << *s++;
    }
    throw std::runtime_error("extra arguments provided to printf"); 
}

int main()
{
    printz("%hi%you", 1, 2);
    return 0;
}
