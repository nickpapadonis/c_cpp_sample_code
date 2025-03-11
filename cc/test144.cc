#include <iostream>
using namespace std;

struct Y {
    Y() {cout << "Y()" << endl;}
    ~Y() {cout << "~Y()" << endl;}
};

struct X {
    Y y;
    X() : y{} {cout << "X()" << endl; if (0) throw X::X_err{"cons error"};}
    ~X() {cout << "~X()" << endl;}
    struct X_err {
	string err;
	X_err(const string& s) : err{s} {}
	const string& what(void) {return err;}
    };
    void dothat(void) {Y yy; throw X::X_err{"fun error"};}
    void dothis(void) {throw std::runtime_error{"bad error"};}
};

void f()
{
    try {
	X x;
	x.dothat();
	cout << "a" << endl;
	//x.~X();
    } catch (std::runtime_error &e) {
	cout << "error: " << e.what() << endl;
    } catch (X::X_err &e) {
	cout << "error: " << e.what() << endl;
    } catch (...) {
	cout << "here" << endl;
    }
}

int main(int argc, char *argv[])
{
    f();
    
    return 0;
}
