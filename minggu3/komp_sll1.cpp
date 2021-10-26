#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node *address;
class node {
public:
    string nama_mhs;
    node* next;
};

address newNode(string nama) {
    address baru;
    baru = (struct node*) malloc(sizeof(struct node));

    baru->nama_mhs = nama;
    baru->next = NULL;

    return baru;
}

void insertFIRST(struct node** ref, string nama) {
    address baru;
    baru = newNode(nama); 

    baru->next = (*ref);
        (*ref) = baru;
}

void insertAFTER(struct node** ref, string i, string nama) {
    address baru;
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
    address baru;
    baru = newNode(nama);

    if (*ref != NULL) {
        struct node* last = *ref;

        baru->next = NULL;

        while (last->next != NULL) {
            last = last->next;
        }

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
    struct node *head = NULL;

    insertLAST(&head, "Sugiono");
    insertFIRST(&head, "Mugiono");
    insertLAST(&head, "Pujianto");
    insertAFTER(&head, "Sugiono", "Legowo");

    cetak(head);
}