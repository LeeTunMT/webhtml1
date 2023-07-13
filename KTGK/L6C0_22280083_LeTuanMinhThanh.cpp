#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct LOPA{
    char ten[30];
    short int diem;
};
void nhap_mang(LOPA a[], int &n);
void xuat_mang(LOPA a[], int n);
int tong_diem_van(LOPA a[], int n);
void diem_van_giam(LOPA a[], int n);

int main(){
    LOPA a[100];
    int n;

    cout << "Nhap thong tin sinh vien\n";
    nhap_mang(a,n);
    cout << "-----------------------------------------------------\n";
    cout << "Xuat thong tin sinh vien\n";
    xuat_mang(a,n);
    cout << "-----------------------------------------------------\n";
    cout << "Tong diem toan cua lop la: " << tong_diem_van(a,n) << "\n";
    cout << "Diem trung binh mon toan cua lop la: " << (float) tong_diem_van(a,n)/n << "\n";
    cout << "-----------------------------------------------------\n";
    cout << "Danh sach lop sau khi sap xep diem toan giam dan\n";
    diem_van_giam(a,n);
    xuat_mang(a,n);
    cout << "-----------------------------------------------------\n";

    float dtb = tong_diem_van(a,n)/n;
    ofstream fout("montoan.txt");   //Mở file montoan.txt để ghi
    if(!fout)
        cout << "Khong the mo file.";
    else 
        cout << "Da mo file ghi.";
    fout << "CAC HOC SINH DUOC CHON THI HSG\n";
    for (int i=0; i<n; i++){
        if(a[i].diem > dtb)
            fout << a[i].ten << " : " << a[i].diem << " diem" << "\n";
    }
    fout.close();

    return 0;
}

void nhap_mang(LOPA a[], int &n){
    cout << "Nhap so luong sinh vien: ";
    cin >>n;
    for(int i=0; i<n; i++){
        cout << "Nhap ten: ";
        cin.ignore();
        cin.getline(a[i].ten,30);
        cout << "Nhap diem van: ";
        cin >> a[i].diem;
    }
}

void xuat_mang(LOPA a[], int n){
    for(int i=0; i<n; i++){
        cout << "Sinh vien thu " << i+1 << ": \n";
        cout << "Ho va ten: " << a[i].ten << "\n";
        cout << "Diem mon toan: " << a[i].diem << "\n";
    }
}

int tong_diem_toan(LOPA a[], int n){
    if(n==-1)
        return 0;
    return a[n-1].diem + tong_diem_toan(a,n-1);
}

void diem_toan_giam(LOPA a[], int n){            //Hàm đệ quy sắp xếp học sinh theo điểm toán giảm dần 
    if (n == 1) 
        return;
    for (int i = 0; i < n - 1; i++) {
        if (a[i].diem < a[i + 1].diem) {
            swap(a[i],a[i+1]);
        }
    }
    diem_toan_giam(a, n - 1);
}