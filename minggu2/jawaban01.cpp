#include <iostream>
using namespace std;

void baca(float (*data)[2]) {
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            if (j != 1) {
                cout << *(*(data+i)+j) << "  ";
            }
            else {
                cout << *(*(data+i)+j) << endl << endl;
            }
        }
    }
}

void inverse(float (*data)[2]) {
    float a = *(*(data+0)+0);
    float b = *(*(data+0)+1);
    float c = *(*(data+1)+0);
    float d = *(*(data+1)+1);
    
    if ((a*d)-(b*c) != 0) {
        *(*(data+0)+0) = d;
        *(*(data+0)+1) = -b;
        *(*(data+1)+0) = -c;
        *(*(data+1)+1) = a;

        for (int i=0; i<2; i++) {
            for (int j=0; j<2; j++) {
                *(*(data+i)+j) /= ((a*d)-(b*c));
            }
        }

        baca(data);
    }
    else {
        cout << "Tidak memenuhi syarat matriks invers" << endl;
    }
}

int main() {
    float matriks[2][2];

    cout << "Masukkan Nilai :" << endl;
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            printf("Matriks [%d][%d] = ", i, j);
            cin >> matriks[i][j];
        }
    }

    cout << "Matriks Biasa :" << endl;
    baca(matriks);

    cout << "Matriks Invers :" << endl;
    inverse(matriks);
}