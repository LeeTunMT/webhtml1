#include <iostream>
#define max 100
using namespace std;

void input(int &n, int m[]);
void Sx_Duongtang_Amgiam(int &n, int m[]);

int main(){
    int n;
    int m[100];
    input(n,m);
    Sx_Duongtang_Amgiam(n,m);
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

void Sx_Duongtang_Amgiam(int &n, int m[]){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j< n; j++){
            if(m[i]>0 && m[j]>0 && m[j] < m[i]){    // Nếu cả hai phần tử đều dương và phần tử sau bé hơn phần tử trước thi đổi vị trí cho nhau.

                swap(m[i],m[j]); 
            }
            if(m[i]<0 && m[j]<0 && m[j] > m[i]){    // Nếu cả hai phần tử đều âm và phần tử sau lớn hơn phần tử trước thi đổi vị trí cho nhau.
                swap(m[i],m[j]);
            }
        }
    }
    cout <<"===============MANG SAU KHI SAP XEP===============\n";
    for (int i=0; i<n; i++){
        cout << m[i] << "\t";
    }
}
