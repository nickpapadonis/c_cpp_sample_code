#include<iostream>
#include<string>
#include<map>
#include<cctype>
using namespace std;

// program:
//    end
//    expr_list end
// expr_list:
//    expression print
//    expression print expr_list
// expression:
//    expression + term
//    expression − term
//    term
// term:
//    term / primary
//    term ∗ primary
//    primary
// primary:
//    number
//    name
//    name = expression
//    − primary
//    ( expression )
    
int no_of_errors;

double error(const string& s) {
    no_of_errors++;
    cerr << "error: " << s << '\n';
    return 1;
}

enum class Kind : char { name, number, end, printnl,
			 plus='+', minus='-', mul='*',
			 div='/', print=';', assign='=',
			 lp='(', rp=')' };

struct Token {
    Kind kind;
    string string_value;
    double number_value;
};    

struct Enode {
    Token oper;
    Enode *left;
    Enode *right;
};

map<string,double> table;

class Token_stream {
public:
    Token_stream(istream& s) : ip{&s}, owns{false} { }
    Token_stream(istream* p) : ip{p}, owns{true} { }
    ~Token_stream() { close(); }
    Token get();
    Token& current() { return ct; }
    void set_input(istream& s) { close(); ip = &s; owns=false; }
    void set_input(istream* p) { close(); ip = p; owns = true; }
private:
    void close() { if (owns) delete ip; }

    istream* ip;
    bool owns;
    Token ct {Kind::end};
};

Token_stream ts {cin};

Token Token_stream::get()
{
    char ch;

    do {
	if (!ip->get(ch)) return ct={Kind::end};
    } while (ch!='\n' && isspace(ch));

    switch (ch) {
    case ';':
	return ct={Kind::print};
    case '\n':
	return ct={Kind::printnl};
    case '*':
    case '/':
    case '+':
    case '-':
    case '(':
    case ')':
    case '=':
	return ct={static_cast<Kind>(ch)};
    case '0': case '1': case '2': case '3': case '4': case '5':
    case '6': case '7': case '8': case '9': case '.':
	ip->putback(ch); 
	*ip >> ct.number_value; 
	ct.kind = Kind::number;
	return ct;
    default: 
	if (isalpha(ch)) {
	    ct.string_value = ch;
	    while (ip->get(ch))
		if (isalnum(ch))
		    ct.string_value += ch;
		else {
		    ip->putback(ch);
		    break;
		}
	    ct.kind = Kind::name;
	    return ct;
	}

	error("bad token");
	return ct={Kind::print};
    }
}

Enode *expr(bool get);

Enode *prim(bool get)
{
    Token t;
    if (get) ts.get();

    Enode *pe = 0;
    switch (ts.current().kind) {
    case Kind::number:
	pe = new Enode{ts.current(), 0, 0};
	ts.get();
	return pe;
    case Kind::end:
	pe = new Enode{ts.current(), 0, 0};
	return pe;
    case Kind::name:
	t = ts.current();
	pe = new Enode{t, 0, 0};
	if (ts.get().kind == Kind::assign) {
	    t = ts.current();
	    pe = new Enode{t, pe, expr(true)};
	}
	return pe;
    case Kind::minus:
	t = ts.current();
	pe = new Enode{t, pe, prim(true)};
	return pe;
    case Kind::lp:
	t = ts.current();
	pe = new Enode{t, 0, expr(true)};
	t = ts.current();
	pe = new Enode{t, pe, 0};
	ts.get();
	return pe;
    default:
	pe = new Enode{ts.current(), 0, 0};
	return pe;
    }
}

Enode *term(bool get)
{
    Enode *left = prim(get);
    Token t;
    for (;;) {
	switch (ts.current().kind) {
	case Kind::mul:
	case Kind::div:
	    t = ts.current();
	    left = new Enode{t, left, prim(true)};
	    break;
	default:
	    return left;
	}
    }
}
		
Enode *expr(bool get)
{
    Enode *left = term(get);
    Token t;
    for (;;) {
	switch (ts.current().kind) {
	case Kind::plus:
	case Kind::minus:
	    t = ts.current();
	    left = new Enode{t, left, term(true)};
	    break;
	default:
	    return left;
	}
    }
}

Enode *expr_list(bool get)
{
    Enode *left = expr(get);
    Token t;
    for (;;) {
	switch (ts.current().kind) {
	case Kind::print:
	    t = ts.current();
	    left = new Enode{t, left, expr(true)};
	    break;
	case Kind::printnl:
	    ts.get();
	    while (ts.current().kind == Kind::printnl)
		ts.get();
	    break;
	default:
	    return left;
	}
    }
}

Enode *program()
{
    Enode *left = 0;
    
    ts.get();
    for (;;) {
	switch (ts.current().kind) {
	case Kind::end:
	    left = new Enode{ts.current(), left, 0};
	    return left;
	default:
	    return expr_list(false);
	}
    }
}

void poper(Token op)
{
    switch (op.kind) {
    case Kind::name:
	cout << " name[" << op.string_value << "] ";
	break;
    case Kind::number:
	cout << " num[" << op.number_value << "] ";
	break;
    case Kind::end:
	cout << " end ";
	break;
    case Kind::print:
    case Kind::printnl:
	cout << " print ";
	break;
    case Kind::plus:
	cout << " + ";
	break;
    case Kind::minus:
	cout << " - ";
	break;
    case Kind::mul:
	cout << " * ";
	break;
    case Kind::div:
	cout << " / ";
	break;
    case Kind::assign:
	cout << " = ";
	break;
    case Kind::lp:
	cout << " lp ";
	break;
    case Kind::rp:
	cout << " rp ";
	break;
    }
}

void troot(Enode *node)
{
    if (node == 0)
	return;
    
    troot(node->left);
    poper(node->oper);
    troot(node->right);
}

void troot_del(Enode *node)
{
    if (node == 0)
	return;
    
    troot_del(node->left);
    troot_del(node->right);

    delete node;
}

int main(int argc, char *argv[])
{
    table["pi"] = 3.1415926535897932385;
    table["e"] = 2.7182818284590452354;

    Enode *root = program();
    troot(root);
    troot_del(root);
    
    return no_of_errors;
}
