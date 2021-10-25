#include <iostream>
#include <stdlib.h>
using namespace std;

class node {
public:
    string nama_mhs;
    node* next;
    node* back;
};

void cetak(node* n) {
    node* last;
    cout<<"\nTraversal in forward direction \n";
    while (n != NULL) {
        cout<<" "<<n->nama_mhs<<" ";
        last = n;
        n = n->next;
    }
 
    cout<<"\nTraversal in reverse direction \n";
    while (last != NULL) {
        cout<<" "<<last->nama_mhs<<" ";
        last = last->back;
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

    cetak(first);

}
