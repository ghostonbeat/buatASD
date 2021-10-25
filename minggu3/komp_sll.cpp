#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node *address;
struct node  {
    int no_urut;
    string nama_mhs;
    address next;
} element;

address newNode(int no, string nama) {
    address baru;
    baru = (struct node*) malloc(sizeof(struct node));

    baru->no_urut = no;
    baru->nama_mhs = nama;
    baru->next = NULL;

    return baru;
}

void insertFIRST(struct node** ref, int no, string nama) {
    address baru;
    baru = newNode(no, nama);

    baru->next = (*ref);
    (*ref) = baru;
}

void insertAFTER(struct node* prev, int no, string nama) {
    address baru;
    baru = newNode(no, nama);

    baru->next = prev->next;
    prev->next = baru;
}

void insertLAST(struct node** ref, int no, string nama) {
    address baru;
    baru = newNode(no, nama);

    struct node* last = *ref;

    baru->next = NULL;

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = baru;
}

void cetak(node* n) {
    while (n != NULL) {
        cout<<" "<<n->no_urut<<" -> ";
        cout<<" "<<n->nama_mhs<<" ";
        n = n->next;
    }
}

int main() {
    struct node *head = NULL;

    insertFIRST(&head, 1, "Sugiono");
    insertAFTER(head, 2, "Mugiono");
    insertLAST(&head, 3, "Pujianto");
    insertAFTER(head->next, 4, "Legowo");

    cetak(head);
}