#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 100;

void NhapMaTranSoNguyen(int a[][MAX], int &m, int &n);
void XuatMaTranSoNguyen(int a[][MAX], int m, int n);
void NhapMaTranSoThuc(float b[][MAX], int &m, int &n);
void XuatMaTranSoThuc(float b[][MAX], int m, int n);
int Tim_gia_tri_max_MTST(float b[][MAX], int m, int n);
bool check_snt(int a);
int Dem_snt(int a[][MAX], int m, int n);
void Sap_xep_tang_dan_MTST(float b[][MAX], int m, int n);
int count_maximum_num(float b[][MAX], int m, int n);
bool checkPositive(float b[][MAX], int m, int n);

int main() {
    int a[MAX][MAX], m, n;
    float b[MAX][MAX];
    // cout << "Nhap ma tran so nguyen" << endl;
    // NhapMaTranSoNguyen(a, m, n);
    // cout << "Xuat ma tran so nguyen" << endl;
    // XuatMaTranSoNguyen(a, m, n);
    cout << "-------------------------------------------------------------------------------------\n";
    cout << "Nhap ma tran so thuc" << endl;
    NhapMaTranSoThuc(b,m,n);
    cout << "Xuat ma tran so thuc" << endl;
    XuatMaTranSoThuc(b,m,n);
    cout << "-------------------------------------------------------------------------------------\n";
    // cout << "Gia tri lon nhat trong ma tran so thuc la: " << Tim_gia_tri_max_MTST(b,m,n) << endl;
    // cout << "So luong so nguyen to trong mang so nguyen la: " << Dem_snt(a,m,n) << endl;
    // Sap_xep_tang_dan_MTST(b,m,n);
    // cout << "Ma tran so thuc sau khi sap xep la:\n ";
    // XuatMaTranSoThuc(b,m,n);
    cout << "So cac so cuc dai trong ma tran la: " << count_maximum_num(b,m,n) << endl;
    if(checkPositive(b,m,n)){
        cout << "ma tran co so duong\n ";
    }
    else 
        cout << "Ma tran khong co so duong\n";
    return 0;
}

void NhapMaTranSoNguyen(int a[][MAX], int &m, int &n) {
    cout << "Nhap so dong: ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Nhap phan tu a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
}

void XuatMaTranSoNguyen(int a[][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

void NhapMaTranSoThuc(float b[][MAX], int &m, int &n) {
    cout << "Nhap so dong: ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Nhap phan tu a[" << i << "][" << j << "]: ";
            cin >> b[i][j];
        }
    }
}

void XuatMaTranSoThuc(float b[][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[i][j] << "\t";
        }
        cout << endl;
    }
}

int Tim_gia_tri_max_MTST(float b[][MAX], int m, int n){
    float max=b[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++){
            if(max<b[i][j]){
                max=b[i][j];
            }
        }
    }
    return max;
}

bool check_snt(int a) {
	if (a < 2)
		return false;
	if (a % 2 == 0)
		return false;
	for (int i = 3; i < sqrt((float)a); i += 2) {
		if (a % i == 0)
			return false;
	}
	return true;
}

int Dem_snt(int a[][MAX], int m, int n){
    int count=0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(check_snt(a[i][j])){
                count++;
            }
        }
    }
    return count;
}

void Sap_xep_tang_dan_MTST(float b[][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m - i - 1; k++) {
                if (b[k][j] > b[k + 1][j]) {
                    swap(b[k][j], b[k + 1][j]);
                }
            }
        }
    }
}
int count_maximum_num(float b[][MAX], int m, int n){
    int count = m*n;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(b[i+1][j]>b[i][j] || b[i][j+1]>b[i][j] || b[i-1][j]>b[i][j] || b[i][j-1]>b[i][j]){
                count--;
            }
        }
    }
    return count;
}

bool checkPositive(float b[][MAX], int m, int n) {
    bool flag = false;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (b[i][j] > 0) {
                flag = true;
                break;
            }
        }
    }
    return flag;
}

