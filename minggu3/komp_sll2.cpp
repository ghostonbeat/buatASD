#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node *address;
struct node  {
    int no_urut;
    string nama_mhs;
    address next;
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

void insertAFTER(struct node** ref, string i, int no, string nama) {
    address baru;
    baru = newNode(no, nama);

    if ((*ref) != NULL) {
        struct node* prev = *ref;

        while (prev->nama_mhs != i) {
            prev = prev->next;
        }

        baru->next = prev->next;
        prev->next = baru;
    }
    else {
        insertFIRST(ref, no, nama);
    }
}

void insertLAST(struct node** ref, int no, string nama) {
    address baru;
    baru = newNode(no, nama);

    if (*ref != NULL) {
        struct node* last = *ref;

        baru->next = NULL;

        while (last->next != NULL) {
            last = last->next;
        }

        last->next = baru;
    }
    else {
        insertFIRST(ref, no, nama);
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

    insertLAST(&head, 1, "Sugiono");
    insertFIRST(&head, 2, "Mugiono");
    insertLAST(&head, 3, "Pujianto");
    insertAFTER(&head, "Sugiono", 4, "Legowo");

    cetak(head);
}