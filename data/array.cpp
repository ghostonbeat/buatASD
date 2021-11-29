#include <iostream>
#include <stdlib.h>
using namespace std;

#define MaxEl 10
#define Nil NuL

bool lanjut = true;

typedef string info;
info NuL = "";
info M[MaxEl];

#define Array(P) M[P]

void createEmpty() {
    for (int i=0; i<MaxEl; i++) {
        Array(i) = Nil;
    }
}

void inputData(info data, int index) {
    if (index < MaxEl && index >= 0) {
        if (Array(index) == Nil) {
            if (data != Nil) {
                Array(index) = data;
            }  
        }  
    }
    else {
        cout << "Out of Range!!!" << endl;
    }
}

void deleteData(info data) {
    for (int i=0; i<MaxEl; i++) {
        if (Array(i) == data) {
            Array(i) = Nil;
        }
    }
}

void deleteDataINDEX(int index) {
    if (index >= 0 && index < MaxEl) {
        Array(index) = Nil;
    }
    else {
        cout << "Out of Range!!!" << endl;
    }
}

void print() {
    cout << endl;
    for (int i=0; i<MaxEl; i++) {
        if (Array(i) != Nil) {
            cout << Array(i) << endl;
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
            info dataInput = Nil;
            int dataIndex = -1;
            cout << "Masukkan Data :";
            cin >> dataInput;
            cout << endl << "Masukkan Index :";
            cin >> dataIndex;
            inputData(dataInput, dataIndex);
            break;
        }   

        case 2: {
            info dataInput = Nil;
            int dataIndex = 0;
            delete &pilih;
            int pilih;

            cout << "Hapus berdasarkan?" << endl;
            cout << "1. Data" << endl;
            cout << "2. Index" << endl;
            cin >> pilih;
            switch (pilih) {
                case 1: {
                    cout << "Masukkan Data :";
                    cin >> dataInput;
                    deleteData(dataInput);
                    break;
                }
        
                case 2: {
                    cout << endl << "Masukkan Index :";
                    cin >> dataIndex;
                    deleteDataINDEX(dataIndex);
                    break;
                }
        
                default: {
                    break;
                }
            }
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
    createEmpty();
    while (lanjut) {
        cout << endl << "========================" << endl;
        menu();
    }
}