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

int scanning(addLink role) {
    int count = -1;
    addList temp = H(role);
    while (temp != Nil) {
        count++;
        temp = N(temp);
    }
    count++;
    return count;
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

void insertLast(addLink *dat, info newData) {
    addList NewElmt = addNew(newData);

    if (H(DAT) == Nil) {
        H(DAT) = NewElmt;
    }
    else {
        addList Node = H(DAT);
        while (N(Node) != Nil) {
            Node = N(Node);
        }
        N(Node) = NewElmt;
    }
}

void insertAfter(addLink *dat, info newData, int index) {
    int MaxEl = scanning(*dat);
    addList NewElmt = addNew(newData);
    
    if (index > 0 && index < MaxEl) {
        addList Node = H(DAT);
        for (int i=0; i<index; i++) {
            Node = N(Node);
        }
        addList Temp = N(Node);
        N(NewElmt) = Temp;
        N(Node) = NewElmt;
    }
    else if (index == 0 && H(DAT) == Nil) {
        H(DAT) = NewElmt;
    }
    else {
        cout << "Out of Range!!!" << endl;
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
    insertFirst(&tampung, 12);
    insertFirst(&tampung, 15);
    insertLast(&tampung, 20);
    insertLast(&tampung, 300);
    insertAfter(&tampung, 1212, 2);
    insertAfter(&tampung, 50, 1);
    print(tampung);
}