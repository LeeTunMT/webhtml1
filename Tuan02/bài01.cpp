#include <iostream>
#include <cmath>
#define max 100
using namespace std;

void input(int &n, int m[]);
void output(int n, int m[]);

int main(){
    int n;
    int m[100];
    input(n,m);
    output(n,m);
    return 0;
}

void input(int &n, int m[]){
    cout << "===============NHAP MANG===============" << endl;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    while (n<0 || n> max){
        cout <<"So phan tu vuot qua gioi han. Vui long nhap lai: ";
        cin >>n;
    }
    cout << "Nhap mang: ";
    for (int i=0; i<n; i++){
        cin >> m[i];
    }
    cout << "\n";
}

void output(int n, int m[]){
    cout << "===============XUAT MANG===============" << endl;
    for (int i=0; i<n; i++){
        cout << "m[" << i << "]: " << m[i] << endl;
    }
}
