#include <iostream>
using namespace std;

int main() {
    float V, Rs, Rp, I;
    int n;

    cout << "Berapa jumlah hambatan tersusun paralel : ";
    cin >> n;

    float nilai, jumlah = 0;

    for (int i=0; i<n; i++) {
        cout << "Masukkan nilai ke-" << i+1 << " : ";
        cin >> nilai;
        jumlah += 1.0/nilai;
    }
    jumlah = 1.0/jumlah;

    cout << "Jumlah nilai hambatannya : " << jumlah << endl;
    Rp = jumlah;

    cout << "Berapa jumlah hambatan yang tersusun seri : ";
    cin >> n;

    jumlah = 0;

    for (int i=0; i<n; i++) {
        cout << "Masukkan nilai ke-" << i+1 << " : ";
        cin >> nilai;
        jumlah += nilai;
    }
    cout << "Jumlah nilai hambatannya : " << jumlah << endl;
    Rs = jumlah;

    cout << "Berapa jumlah baterai yang tersusun seri : ";
    cin >> n;

    jumlah = 0;

    for (int i=0; i<n; i++) {
        cout << "Masukkan nilai ke-" << i+1 << " : ";
        cin >> nilai;
        jumlah += nilai;
    }
    
    cout << "Jumlah nilai tegangannya : " << jumlah << endl;
    V = jumlah;

    cout << "Nilai kuat arus pada Amperemeter adalah : ";

    I = V/(Rs+Rp);

    cout << I << endl;

    return 0;
}