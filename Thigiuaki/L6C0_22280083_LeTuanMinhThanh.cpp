#include <iostream> 
#include <string>
#include <fstream>

using namespace std;

struct LOPA{
    char ten[30];
    short int diem;
};

void nhap_mang(LOPA a[], int &n);   
void xuat_mang(LOPA a[], int n);
int tong_diem_van(LOPA a[], int n);
int diem_van_cao_nhat(LOPA a[], int n, int &max);
void in_hoa_ten(char a[]);

int main(){
    int n;
    LOPA a[100];
    cout << "NHAP THONG TIN HOC SINH \n";
    nhap_mang(a, n);
    cout << "-------------------------------------------\n";
    cout << "XUAT THONG TIN HOC SINH \n";
    xuat_mang(a, n);
    cout << "-------------------------------------------\n";
    cout << "TONG DIEM VAN CUA LOPA LA: " << tong_diem_van(a,n) << "\n";
    float dtb = tong_diem_van(a,n)/n;
    cout << "DIEM TRUNG BINH CUA MON VAN CUA LOPA LA: " << dtb << "\n";
    cout << "-------------------------------------------\n";
    int max=0;         //khoi tao bien max = 0 
    cout << "HOC SINH CO DIEM VAN CAO NHAT LOP\n";
    for(int i=0; i<n; i++){     
        if(a[i].diem == diem_van_cao_nhat(a,n,max)){        //neu diem van cua hoc sinh nao bang max thi xuat thong tin
            cout << a[i].ten << " : " << a[i].diem << " diem.\n";
        }
    }
    cout << "-------------------------------------------\n";
    ofstream fout("monvan.txt");       //mo file ghi
    if (!fout)
        cout << "khong mo duoc file ghi. ";
    else 
        cout << "Da mo file ghi => click vao file monvan.txt de xem ket qua.";
    fout << "THONG TIN HOC SINH DUOC CHON DI THI HOC SINH GIOI VAN\n";
    for(int i=0; i<n; i++){         //chuyen chu thuong thanh chu hoa cua tat ca sinh vien
        in_hoa_ten(a[i].ten);
    }
    for(int i=0; i<n; i++){         //ghi vo file monvan.txt cac ban hoc sinh diem cao nhat voi chu in hoa   
        if(a[i].diem == diem_van_cao_nhat(a,n,max)){        
            fout << a[i].ten << " : " << a[i].diem << " diem.\n";
        }
    }
    fout.close();
    return 0;
}
void nhap_mang(LOPA a[], int &n){  
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;
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
        cout << "Diem mon van: " << a[i].diem << "\n";
    }
}

int tong_diem_van(LOPA a[], int n){
    if(n<1)         //dieu kien dung khi n <0
        return 0;
    return a[n-1].diem + tong_diem_van(a, n-1);
}

int diem_van_cao_nhat(LOPA a[], int n, int &max){       //ham de quy tim diem van lon nhat
    if(n<0)       //dieu kien dung khi n < 0
        return max;
    if(a[n-1].diem > max)          //neu diem cua vi tri bat ki lon hon max thi max bang diem o vi tri do
        max=a[n-1].diem;
    return diem_van_cao_nhat(a,n-1,max);        //goi lai ham voi bien n nho hon 1 don vi
}

void in_hoa_ten(char a[]){      //ham chuyen chu thuong thanh chu hoa
    for(int i=0; i < strlen(a); i++){
        if(a[i] >= 'a' && a[i] <= 'z')
            a[i] = a[i] - 32;
    }    
}