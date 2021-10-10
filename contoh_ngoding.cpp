#include <iostream>
using namespace std;

int luas(int p, int l) {
    return p*l;
}

int keliling(int p, int l) {
    return 2*(p+l);
}

int main() {
    int p, l;
    cout <<"Panjang = ";
    cin >> p;
    cout <<"Lebar = ";
    cin >> l;

    cout <<"HASIL!!!"<< endl;
    cout <<"Luas = "<<luas(p, l)<< endl;
    cout <<"Keliling = "<<keliling(p, l)<< endl;
}