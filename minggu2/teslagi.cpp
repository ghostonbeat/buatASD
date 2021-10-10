#include <iostream>
using namespace std;

int main() {
    int a[2][2] = {{1, 2}, {3,4}};
    int (*b)[2];

    b = a;

    cout << b << endl;
    cout << a << endl;
    for (int i=0; i<2; i++) {
        for (int j=0; j<2 ;j++) {
            cout << *(*(b+i))+j << endl;
            cout << a[i][j] << endl;
        }
    }
}