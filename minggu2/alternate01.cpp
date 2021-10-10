#include <iostream>
using namespace std;

int n;

void baca(float (*data)[2], int i, int j) {
    if (i<n) {
        if (j<n) {
            if (j != 1) {
                cout << *(*(data+i)+j) << "  ";
                baca(data, i, j+1);
            }
            else {
                cout << *(*(data+i)+j) << endl << endl;
                baca(data, i, j+1);
            }
        }
        else {
            baca(data, i+1, 0);
        }
    }
}

void swap(float (*data)[2]) {
    float temp = *(*(data+0)+0);
    *(*(data+0)+0) = *(*(data+1)+1);
    *(*(data+1)+1) = temp;
}

void negative(float (*data)[2]) {
    *(*(data+0)+1) *= -1;
    *(*(data+1)+0) *= -1;
}

void convert(float (*data)[2], int i, int j, float det) {
    if (i<n) {
        if (j<n) {
            *(*(data+i)+j) /= det;
            convert(data, i, j+1, det);
        }
        else {
            convert(data, i+1, 0, det);
        }
    }
}

void inverse(float (*data)[2]) {
    float a = *(*(data+0)+0);
    float b = *(*(data+0)+1);
    float c = *(*(data+1)+0);
    float d = *(*(data+1)+1);
    
    if ((a*d)-(b*c) != 0) {
        swap(data);
        negative(data);

        convert(data, 0, 0, float((a*d)-(b*c)));

        baca(data, 0, 0);
    }
    else {
        cout << "Tidak memenuhi syarat matriks invers" << endl;
    }
}

int main() {
    float matriks[2][2];
    n = 2;

    cout << "Masukkan Nilai :" << endl;
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            printf("Matriks [%d][%d] = ", i, j);
            cin >> matriks[i][j];
        }
    }

    cout << "Matriks Biasa :" << endl;
    baca(matriks, 0, 0);

    cout << "Matriks Invers :" << endl;
    inverse(matriks);
}