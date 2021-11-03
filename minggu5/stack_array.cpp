#include <iostream>
#include <stdlib.h>
using namespace std;

typedef string infotype;

int tanda = 10;

struct link {
    infotype *top;
    infotype *batas;
};

void inisial(struct link* ref, infotype* nama) {
    int i = tanda-1;
    ref->top = nama;
    ref->batas = nama+i;
}

void geser(struct link* ref) {
    if (ref->top == ref->batas) {
        return;
    }
    else {
        ref->top++;
    }
}

bool penuh(struct link* ref) {
    if (*(ref->top) == "") {
        return false;
    }
    else {
        return true;
    }
}

void push(struct link* ref, infotype wadah) {
    if (!penuh(ref)) {
        *(ref->top) = wadah;
        geser(ref);
    }
    else {
        cout << "Array Penuh" << endl;
    }
}

void cetak(infotype* nama) {
    if (*nama != "") {
        int i = tanda-1;
        while (i >= 0) {
            if (*(nama+i) != "") {
                cout << *(nama+i) << endl;
            }
            i--;
        }
    }
    else {
        
    }
}

int main() {
    infotype nama_mhs[tanda];
    link data;

    inisial(&data, nama_mhs);
    push(&data, "Yanto");
    push(&data, "Yuli");
    push(&data, "Katno");
    push(&data, "Suwarno");

    cetak(nama_mhs);

    cetak(nama_mhs);
}