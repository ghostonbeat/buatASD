#include <iostream>
#include <stdlib.h>
using namespace std;

#define Nil NULL

typedef string info;
typedef struct body *addList;
typedef struct body {
    info data;
    addList next;
    addList prev;
} list;

typedef struct link *addLink;
struct link {
    addList head;
    addList tail;
};

#define H(A) A->head
#define T(A) A->tail
#define DAT (*dat)
#define ROLE (*role)
#define N(A) A->next
#define P(A) A->prev
#define D(A) A->data

void createEmpty(addLink *dat) {
    DAT = new link();
    H(DAT) = Nil;
    T(DAT) = Nil;
}

addList addNew(info masuk) {
    addList NewElmt;
    NewElmt = new list();
    D(NewElmt) = masuk;
    N(NewElmt) = Nil;
    P(NewElmt) = Nil;
    return NewElmt;
}

int scanning(addLink role) {
    int count1 = -1;
    addList temp1 = H(role);
    while (temp1 != Nil) {
        count1++;
        temp1 = N(temp1);
    }
    count1++;
    int count2 = -1;
    addList temp2 = T(role);
    while (temp2 != Nil) {
        count2++;
        temp2 = P(temp2);
    }
    count2++;
    return int((count1+count2)/2);
}

void insertFirst(addLink *dat, info newData) {
    addList NewElmt = addNew(newData);

    if (H(DAT) == Nil && T(DAT) == Nil) {
        H(DAT) = NewElmt;
        T(DAT) = NewElmt;
    }
    else {
        addList Node = H(DAT);
        N(NewElmt) = Node;
        P(Node) = NewElmt;
        H(DAT) = NewElmt;
    }
}

void insertLast(addLink *dat, info newData) {
    addList NewElmt = addNew(newData);

    if (H(DAT) == Nil && T(DAT) == Nil) {
        H(DAT) = NewElmt;
        T(DAT) = NewElmt;
    }
    else {
        addList Node = T(DAT);
        N(Node) = NewElmt;
        P(NewElmt) = Node;
        T(DAT) = NewElmt;
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
        addList Temp = T(DAT);
        for (int i=MaxEl-1; i>index+1; i--) {
            Temp = P(Temp);
        }
        N(NewElmt) = Temp;
        P(Temp) = NewElmt;
        N(Node) = NewElmt;
        P(NewElmt) = Node;
    }
    else if (index == 0 && H(DAT) == Nil) {
        H(DAT) = NewElmt;
        T(DAT) = NewElmt;
    }
    else {
        cout << "Out of Range!!!" << endl;
    }
}

/*void deleteFirst(addLink *dat) {
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
}*/

void print(addLink *role) {
    cout << "Dari Depan ke Belakang...." << endl;
    addList Temp = H(ROLE);
    while (Temp != Nil) {
        cout << D(Temp) << endl;
        Temp = N(Temp);
    }
    cout << endl << "Dari Belakang ke Depan...." << endl;
    Temp = T(ROLE);
    while (Temp != Nil) {
        cout << D(Temp) << endl;
        Temp = P(Temp);
    }
}

int main() {
    addLink tampung;
    createEmpty(&tampung);
    insertFirst(&tampung, "Yuli");
    insertFirst(&tampung, "Katno");
    insertLast(&tampung, "Ade");
    insertLast(&tampung, "Rohman");
    insertAfter(&tampung, "Mawar", 1);
    insertAfter(&tampung, "Tio", 3);
    print(&tampung);
}