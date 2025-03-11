prog: test169a.cc test169b.cc test169a.h test169b.h
	clang++ -c -Wall -Wextra -std=c++11 -pedantic-errors -o test169a.o test169a.cc
	clang++ -c -Wall -Wextra -std=c++11 -pedantic-errors -o test169b.o test169b.cc
	clang++ -Wall -Wextra -std=c++11 -pedantic-errors -o test169.out test169a.o test169b.o 
