#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node *add;
class node {
public:
    string nama_mhs;
    add next;
    add back;
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
    
    cetak(list);
}
