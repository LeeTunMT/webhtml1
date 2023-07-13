#include <iostream> 

using namespace std;

struct SOPHUC
{
    float pt;   //Phần thực
    float pa;   //Phần ảo
};
void nhap_mang_so_phuc(SOPHUC a[], int n);
void xuat_mang_so_phuc(SOPHUC a[], int n);
float tong_pt(SOPHUC a[], int n);
float tong_pa(SOPHUC a[], int n);

int main(){
    SOPHUC a[100];
    int n;
    cout << "Nhap do dai mang so phuc: ";
    cin >> n;
    nhap_mang_so_phuc(a,n);
    xuat_mang_so_phuc(a,n);

    cout << "Tong mang so phuc la: " << tong_pt(a,n) << " + " << tong_pa(a,n) << "i" << "\n";
    return 0;
}

void nhap_mang_so_phuc(SOPHUC a[], int n){
    for (int i=1; i<=n; i++){
        cout << "Nhap so phuc thu " << i << ": ";
        cin >> a[i].pt >> a[i].pa;
    }
}

void xuat_mang_so_phuc(SOPHUC a[], int n){
    for(int i=1; i<=n; i++){
        cout << "So phuc thu " << i << ": " << a[i].pt << " + " << a[i].pa << "i" << "\n";
    }
}

float tong_pt(SOPHUC a[], int n){
    if(n==0)
        return 0;
    return a[n].pt + tong_pt(a,n-1);
}

float tong_pa(SOPHUC a[], int n){
    if(n==0)
        return 0;
   return a[n].pa + tong_pa(a,n-1);
}
