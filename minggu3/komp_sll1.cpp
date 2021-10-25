#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node *address;
class node {
public:
    int no_urut;
    string nama_mhs;
    node* next;
};

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

void push(node** n, int no, string nama) {
    if (n == NULL) {
        insertFIRST(n, no, nama);
    }
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

    push(&head, 1, "Legiono");

    cetak(head);
}