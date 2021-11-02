#include <iostream>
#include <stdlib.h>
using namespace std;

class node {
public:
    string nama_mhs;
    node* next;
    node* back;
};

void cetak(node* F, node* L) {
    node* patok1;
    node* patok2;
    patok1 = F;
    patok2 = L;

    cout << "\nTraversal in forward direction \n";
    int count = 4;
    while (count > 0) {
        cout << " " << F->nama_mhs << " ";
        F = F->next;
        if (F == patok1) {
            count -= 1;
        }
    }

    cout << "\nTraversal in reverse direction \n";
    count = 4;
    while (count > 0) {
        cout << " " << L->nama_mhs << " ";
        L = L->back;
        if (L == patok2) {
            count -= 1;
        }
    }
}

int main() {
    node* first = NULL;
    node* middle = NULL;
    node* last = NULL;

    first = new node();
    middle = new node();
    last = new node();

    first->nama_mhs = "Yanto";
    middle->nama_mhs = "Yuli";
    last->nama_mhs = "Katno";

    first->next = middle;
    middle->back = first;
    middle->next = last;
    last->back = middle;
    last->next = first;
    first->back = last;

    cetak(first, last);

}