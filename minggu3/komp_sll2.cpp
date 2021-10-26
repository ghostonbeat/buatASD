#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node *add;
struct node {
    string nama_mhs;
    add next;
};

add newNode(string nama) {
    add baru;
    baru = new node();

    baru->nama_mhs = nama;
    baru->next = NULL;
}

void insertFIRST(struct node** ref, string nama) {
    add baru;
    baru = newNode(nama);

    baru->next = (*ref);
    (*ref) = baru;
}

void insertAFTER(struct node** ref, string i, string nama) {
    add baru;
    baru = newNode(nama);

    if ((*ref) != NULL) {
        struct node* prev = *ref;

        while (prev->nama_mhs != i) {
            prev = prev->next;
        }

        baru->next = prev->next;
        prev->next = baru;
    }
    else {
        insertFIRST(ref, nama);
    }
}

void insertLAST(struct node** ref, string nama) {
    add baru;
    baru = newNode(nama);

    if (*ref != NULL) {
        node* last = *ref;

        while (last->next != NULL) {
            last = last->next;
        }

        baru->next = last->next;
        last->next = baru;
    }
    else {
        insertFIRST(ref, nama);
    }
}

void cetak(node* n) {
    while (n != NULL) {
        cout<<" "<<n->nama_mhs<<" ";
        n = n->next;
    }
}

int main() {
    node* list = NULL;

    insertFIRST(&list, "Yanto");
    insertLAST(&list, "Yuli");
    insertFIRST(&list, "Katno");
    insertAFTER(&list, "Katno", "Suwarno");

    cetak(list);
}