#include <iostream>
#include <stdlib.h>
using namespace std;

class node {
public:
    string nama_mhs;
    node* next;
    node* back;
};

struct link {
    node* head;
    node* tail;
};

void cetak(link* n) {
    node* temp = n->head;
    
    cout << "\nTraversal in forward direction \n";
    while (temp != NULL) {
        cout << " " << temp->nama_mhs << " ";
        temp = temp->next;
    }

    node* temp = n->tail;
 
    cout << "\nTraversal in reverse direction \n";
    while (temp != NULL) {
        cout << " " << temp->nama_mhs << " ";
        temp = temp->back;
    }
}

int main() {
    link data;
    data.head = new node();
    data.head->nama_mhs = "Yanto";
    
    node* middle = new node();
    middle->nama_mhs = "Yuli";

    data.tail = new node();
    data.tail->nama_mhs = "Katno";

    data.head->next = middle;
    middle->back = data.head;
    middle->next = data.tail;
    data.tail->back = middle;

    cetak(&data);
}
