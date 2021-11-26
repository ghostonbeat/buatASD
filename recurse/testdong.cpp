#include <iostream>
using namespace std;

int main() {

    int a, *b;

    a = 10;

    b = &a;

    cout << *b << endl;

    a = 20;

    cout << *b << endl;

    cout << endl;

    cout << sizeof(a) << endl;
    cout << a << endl;
    cout << sizeof(*b) << endl;
    cout << *b << endl;
    cout << sizeof(&a) << endl;
    cout << &a << endl;
    cout << sizeof(b) << endl;
    cout << b << endl;
    cout << sizeof(&b) << endl;
    cout << &b << endl;
    
}