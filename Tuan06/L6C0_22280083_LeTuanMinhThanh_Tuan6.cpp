#include <iostream>
#include <cmath>

using namespace std;

int virus(int n);
int truy_hoi_n(int n);
int Xn(int n);
int Yn(int n);
double ngan_hang(int n, double a, double x);
float tong_mang(float ar[], int n);
int maxIndex(int arr[], int n);
int minIndex(int arr[], int n);

int main(){
    int n;
    cout << "Bai 01: Tinh luong virus sau n gio\n";
    cout << "Nhap so gio: ";
    cin >> n;
    cout << "Luong virus sau " << n << " gio la: " << virus(n) << endl;
    cout << "----------------------------------------------------------\n";
    cout << "Bai02: Xac dinh day truy hoi \n";
    cout << "Nhap n: ";
    cin >> n;
    cout << "So hang thu " << n << " cua day truy hoi la: " << truy_hoi_n(n) << endl;
    cout << "----------------------------------------------------------\n";
    cout << "Bai 03: Tim Xn va Yn bang de quy ho tuong\n";
    cout << "Nhap n: ";
    cin >> n;
    cout << "Gia tri cua X" << n << " va Y" << n << " lan luot la: " << Xn(n) << ", " << Yn(n) << endl;
    cout << "----------------------------------------------------------\n";
    cout << "Bai04: Bai toan lai suat\n";
    cout << "Nhap lai suat: ";
    double a;
    cin >> a;
    cout << "Nhap so tien gui ngan hang (don vi: trieu dong): ";
    double x;
    cin >> x;
    cout << "Nhap so nam gui ngan hang: ";
    cin >> n;
    cout << "So tien sau khi gui ngan hang la: " << ngan_hang(n,a,x) << " trieu dong\n";
    cout << "So tien nhan duoc sau 5 nam voi so tien gui 10 trieu, lai suat 2% mot nam la: " << ngan_hang(5,2,10) << " trieu dong \n";
    cout << "----------------------------------------------------------\n";
    cout << "Bai05: Tinh tong cac gia tri trong mang bang de quy\n";
    float ar[100];
    cout << "Nhap so phan tu mang: ";
    cin >> n;
    cout << "Nhap mang: ";
    for(int i=1; i<=n; i++)
        cin >> ar[i];
    cout << "Tong mang la: " << tong_mang(ar,n) << endl;
    cout << "----------------------------------------------------------\n";
    cout << "Bai 06: Tim chi so gia tri lon nhat va nho nhat trong mang mot chieu\n";
    int arr[100];
    cout << "Nhap so phan tu mang: ";
    cin >> n;
    cout << "Nhap mang: ";
    for(int i=0; i<n; i++)
        cin >>arr[i];
    cout << "Vi tri cua gia tri lon nhat mang la: " << maxIndex(arr,n) << endl;
    cout << "Vi tri cua gia tri nho nhat mang la: " << minIndex(arr,n) << endl;
    return 0;
}   

//Bai01
int virus(int n){
    if(n==0)
        return 2;
    else
        return 2*virus(n-1);
}

//Bai02
int truy_hoi_n(int n){
    if(n==0)
        return 1;
    long s=0;
    for(int i=1; i<=n; i++)
        s+=pow(i,2)*truy_hoi_n(n-i);
    return s;
}
//Bai03
int Xn(int n){
    if(n==0)
        return 1;
    else 
        return Xn(n-1) + Yn(n-1);
}

int Yn(int n){
    if(n==0)
        return 1;
    else
        return n^2*Xn(n-1) + Yn(n-1);
}

//Bai04
double ngan_hang(int n, double a, double x){
    if(n==0)
        return x;  
    else
        return (ngan_hang(n-1,a,x)*(1+a/100));
}

//Bai05
float tong_mang(float ar[], int n){
    if(n==0)
        return 0;
    else
        return tong_mang(ar,n-1) + ar[n];
}

//Bai06

int maxIndex(int arr[], int n) {
    if (n == 1) 
        return 0;
    // Gọi hàm đệ quy cho mảng con từ vị trí thứ hai đến cuối
    int subMaxIndex = maxIndex(arr + 1, n - 1) + 1;
    // So sánh phần tử đầu tiên với phần tử lớn nhất của mảng con
    if (arr[0] > arr[subMaxIndex]) 
        return 0; // Nếu lớn hơn, trả về 0
    else 
        return subMaxIndex; // Ngược lại, trả về subMaxIndex
}
int minIndex(int arr[], int n) {
    if (n == 1) 
        return 0;
    // Gọi hàm đệ quy cho mảng con từ vị trí thứ hai đến cuối
    int subMinIndex = minIndex(arr + 1, n - 1) + 1;
    // So sánh phần tử đầu tiên với phần tử nhỏ nhất của mảng con
    if (arr[0] < arr[subMinIndex]) 
        return 0; // Nếu nhỏ hơn, trả về 0
    else 
        return subMinIndex; // Ngược lại, trả về subMinIndex
}