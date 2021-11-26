#include <iostream>
#include <stdlib.h>
using namespace std;

#define Maks 10
#define Nil 0

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
    if (index < Maks && index > 0) {
        if (arr(index) == 0) {
            if (data != 0) {
                arr(index) = data;
            }  
        }  
    }
    else {
        cout << "Out of Range!!!" << endl;
    }
}

void deleteData(info data, int index) {
    if (index == -1) {
        for (int i=0; i<Maks; i++) {
            if (arr(i) == data) {
                arr(i) = Nil;
            }
        }
    }
    else {
        arr(index) = Nil;
    }
}

void print() {
    cout << endl;
    for (int i=0; i<Maks; i++) {
        if (arr(i) != Nil) {
            cout << arr(i) << endl;
        }
    }
}

void menu() {
    int pilih;
    cout << "Pilih Menu" << endl;
    cout << "1. Masuk Data" << endl;
    cout << "2. Hapus Data" << endl;
    cout << "3. Cetak" << endl;
    cout << "4. Keluar" << endl;
    cin >> pilih;

    switch (pilih) {
        case 1: {
            info dataInput = 0;
            int dataIndex = -1;
            cout << "Masukkan Data :";
            cin >> dataInput;
            cout << endl << "Masukkan Index :";
            cin >> dataIndex;
            inputData(dataInput, dataIndex);
            break;
        }   

        case 2: {
            info dataInputLAGI = 0;
            int dataIndexLAGI = -1;
            int pilihLAGI;

            cout << "Hapus berdasarkan?" << endl;
            cout << "1. Data" << endl;
            cout << "2. Index" << endl;
            cin >> pilihLAGI;
            switch (pilihLAGI) {
                case 1: {
                    cout << "Masukkan Data :";
                    cin >> dataInputLAGI;
                    break;
                }
        
                case 2: {
                    cout << endl << "Masukkan Index :";
                    cin >> dataIndexLAGI;
                    break;
                }
        
                default: {
                    break;
                }
            }
            deleteData(dataInputLAGI, dataIndexLAGI);
            break;
        }

        case 3: {
            print();
            break;
        }
        
        case 4: {
            lanjut = false;
            break;
        }
    
        default: {
            break;
        }
    }
}

int main() {
    while (lanjut) {
        cout << endl << "========================" << endl;
        menu();
    }
}