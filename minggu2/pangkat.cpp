#include <iostream>
using namespace std;

void pangkat(int* a, int* b, int temp) {
    if (*b < 2) {
        return;
    }
    else {
        temp *= *a;
        pangkat(a, b-1, temp);
    }
}

int main() {
    int a = 4, b = 6;
    int hasil = 1;

    for (int i=1; i<=b; i++) {
        hasil *= a;
    }

    cout << hasil << endl;
    pangkat(&a, &b, 1);

    cout << a;
}