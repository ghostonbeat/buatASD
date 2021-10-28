#include <iostream>
#include <stdlib.h>
using namespace std;

class node {
public:
    string nama_mhs;
    node* next;
};

struct link {
    node* head;
};

void cetak(link* n) {
    node* temp = n->head;
    while (temp != NULL) {
        cout << " " << temp->nama_mhs << " ";
        temp = temp->next;
    }
}

int main() {
    link data;
    data.head = new node();
    data.head->nama_mhs = "Yanto";
    
    node* middle = new node();
    middle->nama_mhs = "Yuli";

    node* last = new node();
    last->nama_mhs = "Katno";

    data.head->next = middle;
    middle->next = last;

    cetak(&data);
}