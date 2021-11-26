#include <iostream>
#include <stdlib.h>
using namespace std;

#define Nil NULL

typedef int info;
typedef struct body *add;
typedef struct body {
    info data;
    add next;
} list;

struct link {
    add head;
};

void createHead(link *dat) {
    dat->head = new list;
}

int main() {
    link tampung;
    createHead(&tampung);
    tampung.head->data = 12;
}