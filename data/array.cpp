#include <iostream>
#include <stdlib.h>
using namespace std;

#define Maks 10

bool lanjut = true;

typedef int info;
info M[Maks];

#define arr(P) M[P]

void createEmpty() {
    for (int i=0; i<Maks; i++) {
        arr(i) = 0;
    }
}

void inputData(info data, int index) {
    if (arr(index) == 0) {
        if (data != 0) {
            arr(index) = data;
        }  
    }   
}

void deleteData(info data, int index) {
    if (index == -1) {
        for (int i=0; i<Maks; i++) {
            if (arr(i) == data) {
                arr(i) = 0;
            }
        }
    }
    else {
        arr(index) = 0;
    }
}

void print() {
    for (int i=0; i<Maks; i++) {
        if (arr(i) != 0) {
            cout << arr(i) << endl;
        }
    }
}

void menu() {
    int pilih;
    cout << "Pilih Menu" << endl;
    cout << "1. Masuk Data" << endl;
    cout << "2. Hapus Data" << endl;
    cout << "3. Keluar" << endl;
    cin >> pilih;

    switch (pilih) {
        case 1:
            info dataInput = 0;
            int dataIndex = -1;
            cout << "Masukkan Data :";
            cin >> dataInput;
            cout << endl << "Masukkan Index :";
            cin >> dataIndex;
            inputData(dataInput, dataIndex);
            break;
    
        case 2:
            info dataInput = 0;
            int dataIndex = -1;
            int pilih;

            cout << "Hapus berdasarkan?" << endl;
            cout << "1. Data" << endl;
            cout << "2. Index" << endl;
            cin >> pilih;
            switch (pilih) {
                case 1:
                    cout << "Masukkan Data :";
                    cin >> dataInput;
                    break;
        
                case 2:
                    cout << endl << "Masukkan Index :";
                    cin >> dataIndex;
                    break;
        
                default:
                    break;
            }
            break;

        case 3:
            lanjut = false;
            break;
    
        default:
            break;
    }
}

int main() {
    while (lanjut) {
        menu();
    }
}