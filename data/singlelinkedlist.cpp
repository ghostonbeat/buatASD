#include <iostream>
#include <stdlib.h>
using namespace std;

#define Nil NULL

bool lanjut = true;

typedef string info;
typedef struct body *addList;
typedef struct body {
    info data;
    addList next;
} list;

typedef struct link *addLink;
struct link {
    addList head;
};

#define H(A) A->head
#define DAT (*dat)
#define N(A) A->next
#define D(A) A->data

void createEmpty(addLink *dat) {
    DAT = new link();
    H(DAT) = Nil;
}

addList addNew(info masuk) {
    addList NewElmt;
    NewElmt = new list();
    D(NewElmt) = masuk;
    N(NewElmt) = Nil;
    return NewElmt;awda
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
    
    if (index >= 0 && index < MaxEl) {
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

void deleteFirst(addLink *dat) {
    if (H(DAT) != Nil) {
        addList Temp = H(DAT);
        H(DAT) = N(Temp);
        free(Temp);
    }
    else {
        cout << "It's Empty" << endl;
    }
}

void deleteLast(addLink *dat) {
    if (H(DAT) != Nil) {
        addList Before = H(DAT);
        while (N(N(Before)) != Nil) {
            Before = N(Before);
        }
        addList Temp = N(Before);
        N(Before) = Nil;
        free(Temp);
    }
    else {
        cout << "It's Empty" << endl;
    }
}

void deleteAfter(addLink *dat, int index) {
    int MaxEl = scanning(*dat);

    if (index >= 0 && index < MaxEl) {
        if (index == 0 && H(DAT) != Nil) {
            deleteFirst(dat);
        }
        else if (index == MaxEl-1 && H(DAT) != Nil) {
            deleteLast(dat);
        }
        else {
            addList Before, Temp, After;
            Before = H(DAT);
            for (int i=0; i<MaxEl-3; i++) {
                Before = N(Before);
                Temp = N(Before);
                After = N(Temp);
                cout << "1. " <<D(Before) << endl;
                cout << "1. " <<D(Temp) << endl;
                cout << "1. " <<D(After) << endl;
            }
        N(Before) = After;
        free(Temp);
        }
    }
    else if (H(DAT) == Nil) {
        cout << "It's Empty" << endl;
    }
    else {
        cout << "Out of Range!!!" << endl;
    }
}

void print(addLink *role) {
    addList Temp = H((*role));
    while (Temp != Nil) {
        cout << D(Temp) << endl;
        Temp = N(Temp);
    }
}

int main() {
    addLink tampung;
    createEmpty(&tampung);
}