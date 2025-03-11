#include <iostream>
#include <cstdarg>
using namespace std;

// typedef unsigned char *va_list;
// #define va_start(list, param) (list = (((va_list)&param) + sizeof(param)))
// #define va_arg(list, type)    (*(type *)((list += sizeof(type)) - sizeof(type)))

void f(char *a ...)
{
    va_list ap;
    va_start(ap, a);

    for (;;) {
	char *s = va_arg(ap, char*);
	if (s == nullptr)
	    break;
	printf("%s\n", s);
    }

    va_end(ap);
}

int main(int argc, char *argv[])
{
    f((char*) "a", (char*) "b", (char*) "c", 0);
    return 0;
}
