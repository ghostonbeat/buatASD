#include <iostream>
using namespace std;
void tukar (int *a, int *b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
int main(){
	int n=7;
	int a[]={2,4,6,1,3,15,10};
	for (int i=0;i<n;i++){
		for(int j=n-1;j>i;j--){
			if(a[j]<a[j-1]){
				tukar(&a[j-1],&a[j]);
			}
		}
	}
	cout << endl << "Setelah pengurutan = ";
	for (int i=0; i<n; i++){
		cout << a[i] << " ";
	}
	return 0;
}
