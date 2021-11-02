#include <iostream>
#include <stdlib.h>
using namespace std;

struct node {
    string nama_mhs;
    node* next;
};

void cetak(node* n) {
    node* F;
    F = n;
    int count = 4;
    while (count > 0) {
        cout << " " << n->nama_mhs << " ";
        n = n->next;
        if (n == F) {
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
    middle->next = last;
    last->next = first;

    cetak(first);
}