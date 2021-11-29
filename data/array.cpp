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

int main() {
    createEmpty();
}