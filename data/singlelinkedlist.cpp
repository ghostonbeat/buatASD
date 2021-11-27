#include <iostream>
#include <stdlib.h>
using namespace std;

#define Nil NULL

typedef int info;
typedef struct body *addList;
typedef struct body {
    info data;
    addList next;
} list;

typedef struct link *addLink;
struct link {
    addList head;
};

#define H(P) P->head
#define DAT (*dat)
#define N(P) P->next
#define D(P) P->data

void createEmpty(addLink *dat) {
    (*dat) = new link();
    H((*dat)) = Nil;
}

addList addNew(info masuk) {
    addList NewElmt;
    NewElmt = new list();
    D(NewElmt) = masuk;
    N(NewElmt) = Nil;
    return NewElmt;
}

void insertFirst(addLink *dat, info newData) {
    addList NewElmt = addNew(newData);

    if (H(DAT) == Nil) {
        H(DAT) = NewElmt;
    }
    else {
        addList Node = H(DAT);
        N(NewElmt) = Node;
        H(DAT) = NewElmt;
    }
}

void print(addLink role) {
    addList Temp = H(role);
    while (Temp != Nil) {
        cout << D(Temp) << endl;
        Temp = N(Temp);
    }
}

int main() {
    addLink tampung;
    createEmpty(&tampung);
    addList temp;
    /*temp = new list();
    D(temp) = 12;
    N(temp) = Nil;
    H(tampung) = temp;*/
    insertFirst(&tampung, 12);
    insertFirst(&tampung, 15);
    insertFirst(&tampung, 20);
    insertFirst(&tampung, 300);
    print(tampung);
}