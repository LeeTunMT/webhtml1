#include <iostream>
#include <cmath>
#define max 100

using namespace std;

void nhap_mang_2_chieu(int &m, int &n, float a[][max]);
void xuat_mang_2_chieu(int &m, int &n, float a[][max]);
void sao_chep_cot(int m, int n, float a[][max]);
void hoan_doi_cot_dau_cuoi(int m, int n, float a[][max]);
void loai_bo_cot(int m, int n, float a[][max]);
int so_nguyen(float a);
int tinh_tong_chan(int m, int n, float a[][max]);

int main(){
    int m, n;
    float a[max][max];
    nhap_mang_2_chieu(m,n,a);
    xuat_mang_2_chieu(m,n,a);
    sao_chep_cot(m,n,a);
    hoan_doi_cot_dau_cuoi(m,n,a);
    loai_bo_cot(m,n,a);
    cout << "Tong cac gia tri chan trong mang: " << tinh_tong_chan(m,n,a) << endl;
    return 0;
}

//Bai01 
void nhap_mang_2_chieu(int &m, int &n, float a[][max]){     //Nhap mang
    cout << "Nhap so dong: ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;
    cout << "Nhap mang so thuc: ";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
}

void xuat_mang_2_chieu(int &m, int &n, float a[][max]){     //Xuat mang
    cout << "Xuat mang 2 chieu: \n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << a[i][j] << "\t";
        }
        cout << "\n";
    }
}

//Bai03
void sao_chep_cot(int m, int n, float a[][max]){
    int k,h;
    cout << "Nhap cot co gia tri duoc sao chep: ";
    cin >> k;
    cout << "Nhap cot duoc sao chep vao: ";
    cin >> h;
    for(int i=0; i<m; i++){     //Chay tu dong 0 den dong m-1
        a[i][h] = a[i][k];      //gan gia tri cua phan tu dong i, cot h bang gia tri phan tu dong i cot k
    }
    cout << "Mang sau khi sao chep la: \n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << a[i][j] << "\t";
        }
        cout << "\n";
    }       //Xuat mang sau khi sao chep gia tri
    cout << "\n";
}

//Bai05
void hoan_doi_cot_dau_cuoi(int m, int n, float a[][max]){
    for (int i=0; i<m; i++){
        swap(a[i][0], a[i][n-1]);
    }
    cout << "Mang sau khi hoan doi la: \n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << a[i][j] << "\t";
        }
        cout << "\n";
    }   
    cout << "\n";
}

//Bai07
void loai_bo_cot(int m, int n, float a[][max]){
    int k;
    cout << "Nhap cot can loai bo: ";
    cin >> k;
    for(int i=0; i<m; i++){
        for(int j=k; j<n-1; j++){
            a[i][j]=a[i][j+1];         //lui cot 
        }
    }
    cout << "Mang sau khi xoa cot " << k << " la: \n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << a[i][j] << "\t";
        }
        cout << "\n";
    }   
    cout << "\n";
}

//Bai09
int so_nguyen(float a){
    return (int)a;
}

int tinh_tong_chan(int m, int n, float a[][max]){
    int sum =0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(so_nguyen(a[i][j]) %2 == 0){
                sum+=so_nguyen(a[i][j]);
            }
        }
    }
    return sum;
}