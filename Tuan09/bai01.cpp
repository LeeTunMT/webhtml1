#include <iostream> 

using namespace std;
void nhap_mang(int a[100], int n);
void xuat_mang(int a[100], int n);
void sap_xep(int a[], int n);
bool check(int a, int x);
void tong(int a[], int n, int x);

int main(){
    int a[100];
    int n;
    cout << "Nhap chieu dai mang: ";
    cin >> n;
    cout <<"Nhap mang: ";
    nhap_mang(a,n);
    cout << "Xuat mang: \n";
    xuat_mang(a,n);
    sap_xep(a,n);
    cout << "Mang sau khi sap xep tang dan la: \n";
    xuat_mang(a,n);
    cout <<"Nhap x: ";
    int x;
    cin >> x;
    tong(a,n,x);
    return 0;
}

void nhap_mang(int a[100], int n){
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
}

void xuat_mang(int a[100], int n){
    for(int i=0; i<n; i++){
        cout << a[i] << "\t";
    }
    cout <<"\n";
}

void sap_xep(int a[], int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] > a[j])
                swap(a[i],a[j]);
        }
    }
}

bool check(int a, int x){
    if(a/10<1)
        return false;
    else{
        a=a%100;
        if(a/10==x)
            return true;
    }
    return false;
}

void tong(int a[], int n, int x){
    int sum=0;
    for(int i=0; i<n; i++){
        if(check(a[i],x))
            sum+=a[i];
    }
    cout << "Tong la: " << sum;
}