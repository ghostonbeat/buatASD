#include <iostream>
using namespace std;

float V, Rs, Rp, I;
int n;

void hasil1(float m) {
    cout << "Jumlah nilai hambatannya : " << m << endl;
}

void hasil2(float m) {
    cout << "Jumlah nilai tegangannya  : " << m << endl;
}

float tunggal(int n) {
    float nilai, jumlah = 0;

    for (int i=0; i<n; i++) {
        cout << "Masukkan nilai ke-" << i+1 << " : ";
        cin >> nilai;
        jumlah += nilai;
    }

    return jumlah;
}

float ganda(int n) {
    float nilai, jumlah = 0;

    for (int i=0; i<n; i++) {
        cout << "Masukkan nilai ke-" << i+1 << " : ";
        cin >> nilai;
        jumlah += 1.0/nilai;
    }

    return 1.0/jumlah;
}

float finalis() {
    return V/(Rs+Rp);
}

void urutan() {
    cout << "Berapa jumlah hambatan tersusun paralel : ";
    cin >> n;

    Rp = ganda(n);
    hasil1(Rp);
    
    cout << "Berapa jumlah hambatan yang tersusun seri : ";
    cin >> n;

    Rs = tunggal(n);
    hasil1(Rs); 

    cout << "Berapa jumlah baterai yang tersusun seri : ";
    cin >> n;

    V = tunggal(n);
    hasil2(V);

    I = finalis();

    cout << "Nilai kuat arus pada Amperemeter adalah : " << I << endl;
}

int main() {
    urutan();
    return 0;
}