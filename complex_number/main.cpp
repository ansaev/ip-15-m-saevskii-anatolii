#include <iostream>
#include "ComplexNumberTests.cpp"
#include <string>

using namespace std;
int main() {

    ComplexNumberTests *tests = new  ComplexNumberTests();
    tests->run();
    delete(tests);

    ComplexNumber* a = new ComplexNumber(2.1,3.0);
    ComplexNumber* b = new ComplexNumber(1.7,1.5);
    ComplexNumber* c = new ComplexNumber(2.1,3.0);
    cout<<" a == b : "<< to_string(a==b) << endl;
    cout<<" a == c : "<< to_string(a==c) << endl;
    cout<<" a != b : "<< to_string(a!=b) << endl;
    cout<<" c : "<< c->toString() << endl;
    *c -=*b;
    cout<<" c : "<< c->toString() << endl;

    cout<<"try to += c : "<< c->toString() << endl;
    *c += *b;
    cout<<" c : "<< c->toString() << endl;

    cout<<"try to *=  c : "<< c->toString() << endl;
    *c *= *b;
    cout<<" c : "<< c->toString() << endl;

    cout<<"try to /=  c : "<< c->toString() << endl;
    *c /= *b;
    cout<<" c : "<< c->toString() << endl;

    cout<<"try to cout complex "<<*c<<endl;
    cin >> *c;
    cout<<"c after >> "<<*c<<endl;
    delete(a,b,c);

    return 0;
}