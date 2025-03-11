#include <iostream>

#include "test169a.h"
#include "test169b.h"

template struct MyTemplate<int>;

int main() {
    std::cout << notmain() + MyTemplate<int>().f(1)
	      << std::endl;
}
