#include <iostream>
#include <sstream>
using namespace std;

namespace Assert {
    enum class Mode { throw_, terminate_, ignore_ };

    constexpr Mode CURRENT_MODE = Mode::throw_;
    constexpr int CURRENT_LEVEL = 2;

    constexpr Mode current_mode = CURRENT_MODE;
    constexpr int current_level = CURRENT_LEVEL;
    constexpr int default_level = 1;
    
    constexpr bool level(int n) { return n<=current_level; }

    struct Error : runtime_error {
	Error(const string& p) :runtime_error(p) {}
    };

    string compose(const char* file, int line, const string& message) 
    {
	ostringstream os ("(");
	os << file << "," << line << "):" << message; return os.str();
    }

    template<bool condition =level(default_level), class Except = Error>
    void dynamic(bool assertion, const string& message ="Assert::dynamic failed")
    {
	if (assertion)
	    return;
	if (current_mode == Assert::Mode::throw_)
	    throw Except{message};
	if (current_mode == Assert::Mode::terminate_)
	    std::terminate();
    }

    template<>
    void dynamic<false,Error>(bool, const string&)
    {
    }

    void dynamic(bool b, const string& s)
    {
	dynamic<true,Error>(b,s);
    }

    void dynamic(bool b)
    {
	dynamic<true,Error>(b);
    }

}

void f(int n)
// n should be in [1:max)
{
    constexpr int max = 5;
    Assert::dynamic<Assert::level(2),Assert::Error>(
	(n>=1 && n<max),
	Assert::compose(__FILE__,__LINE__,"range problem"));
}
    
int main(int argc, char *argv[])
{
    try {
	f(10);
    } catch (std::runtime_error &e) {
	cout << e.what();
	throw;
    } catch (std::exception& e) {
	cout << e.what();
    }
    
    return 0;
}
