#include <iostream>
#include <string>
using namespace std;

class Entry2 { // two alternative representations represented as a union
private:
    enum class Tag { number, text };
    Tag type; // discriminant
    union { // representation
        int i;
        string s; // string has default constructor, copy operations, and destructor
    };
public:
    struct Bad_entry { }; // used for exceptions
    string name;
    Entry2(int n) : type{Tag::number}, i{n} { };
    Entry2(string ss) : type{Tag::number} { new(&s) string{ss}; };
    ~Entry2();
    Entry2& operator=(const Entry2&); Entry2(const Entry2&);
// ...
    int number() const; string text() const;
    void set_number(int n);
    void set_text(const string&); // ...
};

Entry2::~Entry2()
{
    if (type==Tag::text)
        s.~string();
}

int Entry2::number() const
{
    if (type!=Tag::number) throw Bad_entry{};
    return i;
}

string Entry2::text() const
{
    if (type!=Tag::text) throw Bad_entry{};
    return s;
}

void Entry2::set_number(int n)
{
    if (type==Tag::text) {
        s.~string(); 
        type = Tag::number;
    }
    i = n;
}

void Entry2::set_text(const string& ss)
{
    if (type==Tag::text)
        s = ss;
    else {
        new(&s) string{ss};
        type = Tag::text;
    }
}

Entry2& Entry2::operator=(const Entry2& e)
{
    if (type==Tag::text && e.type==Tag::text) {
        s = e.s; // usual string assignment
        return *this;
    }
    
    if (type==Tag::text)
        s.~string(); // explicit destroy (§11.2.4)
    
    switch (e.type) {
    case Tag::number:
        i = e.i;
        break;
    case Tag::text:
        new(&s) string{e.s};
        type = e.type;
    }
    
    return *this;
}

int main(int argc, char *argv[])
{
    Entry2 e0(0);
    
    cout << e0.number() << endl;
    try {
        e0.text();
    } catch (...) {
        cout << "caught except" << endl;
    }
            
    e0.set_text("abcd");
    cout << e0.text() << endl;
    
    return 0;
}
