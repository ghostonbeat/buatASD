#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node *add;
struct node {
    string nama_mhs;
    node* next;
    node* back;
};

add newNode(string nama) {
    add baru;
    baru = new node();

    baru->nama_mhs = nama;
    baru->next = NULL;
    baru->back = NULL;
}

void insertFIRST(struct node** ref, string nama) {
    add baru;
    baru = newNode(nama);

    baru->next = (*ref);
    baru->back = NULL;

    if (*ref != NULL) {
        (*ref)->back = baru;
    }
    
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
        prev->next->back = baru;
        prev->next = baru;
        baru->back = prev;
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
        baru->back = last;
    }
    else {
        insertFIRST(ref, nama);
    }
}

void cetak(node* n) {
    node* last;
    
    cout << "\nTraversal in forward direction \n";
    while (n != NULL) {
        cout << " " << n->nama_mhs << " ";
        last = n;
        n = n->next;
    }
 
    cout << "\nTraversal in reverse direction \n";
    while (last != NULL) {
        cout << " " << last->nama_mhs << " ";
        last = last->back;
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
