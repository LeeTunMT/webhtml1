#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct SINHVIEN
{
    int ms;
    char ten[30];
    float gk,ck,th,tong;
};

void list_gdc(int &n);
double sum_Sn(int x, int n);
bool check_(float y, float z);
int find_n();

void nhap_mang_SV(SINHVIEN &sv);
void xuat_mang_SV(SINHVIEN sv);
bool ds_sv_qua_mon(SINHVIEN sv);
bool ds_thi_lai_thuc_hanh(SINHVIEN sv);

void nhap_mt_so_thuc(float a[][100], int m, int n);
void xuat_mt_so_thuc(float a[][100], int m, int n);
void dem_so_duong_tung_dong(float a[][100], int m, int n);
void dem_so_am_tung_dong(float a[][100], int m, int n);
void dem_hoang_hau(float a[][100], int m, int n);
void dem_yen_ngua(float a[][100], int m, int n);
bool isQueen(float a[][100], int m, int n, int i, int j);
int countQueen(float a[][100], int m, int n, int i, int j, int count);
bool isSaddle(float a[][100], int m, int n, int i, int j);
int countSaddle(float a[][100], int m, int n, int i, int j, int count);

int main(){
    int m,n;
    list_gdc(n);

    int x;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap x; ";
    cin >> x;
    cout << "Tong Sn= " << setprecision(2) << fixed << sum_Sn(x,n) << "\n";

    float y,z;
    cout << "Nhap 2 so thuc: ";
    cin >> y >> z;
    if(check_(y,z))
        cout << "Hai so tren cung dau!\n";
    else 
        cout << "Hai so tren trai dau!\n";

    cout << "So nguyen duong nho nhat can tim để 1+2+3+...+n > 10000 la: " << find_n() << "\n";

    SINHVIEN ds[100];
    int sl;
    cout << "Nhap so luong sinh vien: ";
    cin >> sl;
    cout << "---------------NHAP THONG TIN SINH VIEN---------------\n";
    for (int i = 0; i < sl; i++) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        nhap_mang_SV(ds[i]);
        cout << endl;
    }
    cout << "---------------XUAT THONG TIN SINH VIEN---------------\n";
    for (int i = 0; i < sl; i++) {
        cout << "Thong tin sinh vien thu " << i + 1 << endl;
        xuat_mang_SV(ds[i]);
        cout << endl;
    }
    cout << "---------------THONG TIN SINH VIEN QUA MON---------------\n" << endl;
    for (int i =0; i < sl; i++) {
        if (ds_sv_qua_mon(ds[i])) {
        xuat_mang_SV(ds[i]);
        cout << endl;
        }
    }
    cout << "---------------SINH VIEN THI LAI THUC HANH---------------\n" << endl;
    int dem=0;
    for (int i =0; i < sl; i++) {
        if (ds_thi_lai_thuc_hanh(ds[i])) {
        xuat_mang_SV(ds[i]);
        dem++;
        cout << endl;
        }
    }
    if(dem==0)
        cout << "Khong co sinh vien nao thi lai TH!\n";

    float a[100][100];
    cout << "Nhap so dong: ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;
    cout << "Nhap ma tran so thuc: \n";
    nhap_mt_so_thuc(a,m,n);
    cout << "Xuat ma tran so thuc: \n";
    xuat_mt_so_thuc(a,m,n);

    // dem_so_duong_tung_dong(a,m,n);
    // dem_so_am_tung_dong(a,m,n);

    dem_hoang_hau(a,m,n);
    dem_yen_ngua(a,m,n);
    int i=0,j=0, count=0;
    cout << "So diem Hoang Hau theo de quy: " << countQueen(a,m,n,i,j,count) << "\n";
    i=0; j=0; count=0;
    cout << "So diem Yen Ngua theo de quy: " << countSaddle(a,m,n,i,j,count) << "\n";
    return 0;
}

//Bai01
void list_gdc(int &n){
    cout << "Nhap so nguyen duong n: "; 
    cin >> n;
    cout << "Cac uoc cua so nguyen duong " << n << " la: ";
    for(int i=1; i<=n; i++){
        if(n%i==0){
            cout << i << "\t";
        }
    }
    cout << "\n";
}

//Bai02
double sum_Sn(int x, int n){
    if(n==0)
        return 0;
    return 2*pow(x,n)/(n*(n+1)) + sum_Sn(x,n-1);
}

//Bai03
bool check_(float y, float z){
    if(y==0 && z==0)
        return 0;
    if(y>0 && z>0 || y<0 && z<0)
        return true;
    return false;
}

//Bai04
int find_n(){
    int h;
    h = sqrt(20000);  
    while(h*(h+1)<=10000){
        h++; 
    }
    return h;
}
//Giải thích: tổng trên có dạng n*(n+1)/2 nên (n+1)(n+1) > n(n+1) > 20000
//Căn bậc hai bất đẳng thức ta đươc: n+1 > sqrt(n*(n+1)) > sqrt(20000) > h (với h là sô nguyên như trên)
//=> n+1>h => n>h-1. Vậy ta chạy vòng lặp từ h cho tới khi h*(h+1)>10000 thì dừng lại và return về h

//Bai05
void nhap_mang_SV(SINHVIEN &sv){
    cout << "Nhap ma so sinh vien: ";
    cin >> sv.ms;
    while (sv.ms <= 0 || sv.ms > 99999999) {
        cout << "Ma so sinh vien khong hop le. Nhap lai: ";
        cin >> sv.ms;
  }
    cout << "Nhap ten sinh vien: ";
    cin.ignore(); 
    cin.getline(sv.ten, 30); 
    cout << "Nhap diem giua ki: ";
    cin >> sv.gk;
    cout << "Nhap diem cuoi ki: ";
    cin >> sv.ck;
    cout << "Nhap diem thuc hanh: ";
    cin >> sv.th;
    sv.tong = (sv.gk + sv.ck + sv.th) / 3;
}

void xuat_mang_SV(SINHVIEN sv){
    cout << "Ma so sinh vien: " << sv.ms << endl;
    cout << "Ten sinh vien: " << sv.ten << endl;
    cout << "Diem giua ki: " << sv.gk << endl;
    cout << "Diem cuoi ki: " << sv.ck << endl;
    cout << "Diem thuc hanh: " << sv.th << endl;
    cout << "Diem tong: " << sv.tong << endl;
}

bool ds_sv_qua_mon(SINHVIEN sv){
    return (sv.gk >= 5 && sv.ck >=5 && sv.th >=5);
}

bool ds_thi_lai_thuc_hanh(SINHVIEN sv){
    return (sv.th <5);
}

//Bai06
void nhap_mt_so_thuc(float a[][100], int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << "Nhap a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
}

void xuat_mt_so_thuc(float a[][100], int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << a[i][j] << "\t";
        }
        cout << "\n";
    }
}

//Bai07
void dem_so_duong_tung_dong(float a[][100], int m, int n){
    for(int i=0; i<m; i++){
        int dem=0;
        for(int j=0; j<n; j++){
            if(a[i][j]>0)
                dem++;
        }
        cout << "Dong " << i << " co " << dem << " so duong.\n";
    }
    cout << "\n";
}

//Bai08
void dem_so_am_tung_dong(float a[][100], int m, int n){
    for(int i=0; i<m; i++){
        int dem=0;
        for(int j=0; j<n; j++){
            if(a[i][j]<0)
                dem++;
        }
        cout << "Dong " << i << " co " << dem << " so am.\n";
    }
    cout << "\n";
}   

//Bai09
void dem_hoang_hau(float a[][100], int m, int n){
    int dem=0;
    for(int i=0; i<m;i++){
        for(int j=0;j<n;j++){
            bool flag=true;
            //Duyệt trên cột chứa phần tử đang xét a[i][j]]
            for(int u=0;u<m; u++){
                if(a[u][j]>a[i][j])
                    flag=false;
            }
            //Duyệt trên hàng chứa phần tử đang xét a[i][j]]
            for(int v=0;v<n;v++){
            if(a[i][v]>a[i][j])
                flag=false;
            }

            float val=a[i][j];
            //Duyệt qua đường chéo đi từ trái trên xuống phải dưới
            int x=i-1;
            int y=j-1;
            while(x>=0 && y>=0){   
                if(val<a[x][y])
                    flag=false;
                x--;
                y--;
            }
            x=i+1;
            y=j+1;
            while(x<m && y<n){
                if(val<a[x][y])
                    flag=false;
                x++;
                y++;
            }
            //Duyệt qua đường chéo đi từ phải trên xuống trái dưới
            x=i-1;
            y=j+1;
            while(x>=0 && y<n){
                if(val<a[x][y])
                    flag=false;
                x--;
                y++;
            }
            x=i+1;
            y=j-1;
            while(x<m && y>=0){
                if(val<a[x][y])
                    flag=false;
                x++;
                y--;
            }
            //Nếu flag vẫn đúng thì tăng biến đếm lên 1
            if(flag)
                dem++;
        }
    }
    cout << "So phan tu HOANG HAU trong mang la: " << dem << "\n";
}

//Bai10
void dem_yen_ngua(float a[][100], int m, int n){
    int dem=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n; j++){
            bool flag=true;
            //Check trên cột
            for(int u=0;u<m; u++){
                if(a[u][j]<a[i][j])
                    flag=false;
            }
            //Check trên hàng
            for(int v=0;v<n;v++){
                if(a[i][v]>a[i][j])
                    flag=false;
            }
            if(flag)
                dem++;
        }
    }
    cout << "So diem YEN NGUA tren mang la: " << dem << "\n";
}

//Bai11
bool isQueen(float a[][100], int m, int n, int i, int j) {
    //Duyệt trên cột chứa phần tử đang xét a[i][j]]
    for(int u=0;u<m; u++){
        if(a[u][j]>a[i][j])
            return false;
    }
    //Duyệt trên hàng chứa phần tử đang xét a[i][j]]
    for(int v=0;v<n;v++){
        if(a[i][v]>a[i][j])
            return false;
    }

    float val=a[i][j];
    //Duyệt qua đường chéo đi từ trái trên xuống phải dưới
    int x=i-1;
    int y=j-1;
    while(x>=0 && y>=0){   
        if(val<a[x][y])
            return false;
        x--;
        y--;
    }
    x=i+1;
    y=j+1;
    while(x<m && y<n){
        if(val<a[x][y])
            return false;
        x++;
        y++;
    }
    //Duyệt qua đường chéo đi từ phải trên xuống trái dưới
    x=i-1;
    y=j+1;
    while(x>=0 && y<n){
        if(val<a[x][y])
            return false;
        x--;
        y++;
    }
    x=i+1;
    y=j-1;
    while(x<m && y>=0){
        if(val<a[x][y])
            return false;
        x++;
        y--;
    }
    return true;
}

// Hàm đệ quy để đếm số lượng giá trị "Hoàng hậu" trên ma trận
int countQueen(float a[][100], int m, int n, int i, int j, int count) {
    // Nếu đã duyệt hết ma trận thì trả về biến đếm
    if (i == m) {
        return count;
    }
    // Nếu phần tử hiện tại là "Hoàng hậu" thì tăng biến đếm lên 1
    if (isQueen(a, m, n, i, j)) {
        count++;
    }
    // Nếu đã duyệt hết cột thì chuyển sang dòng tiếp theo
    if (j == n - 1) {
        i++;
        j = 0;
    }
    // Ngược lại thì chuyển sang cột tiếp theo
    else {
        j++;
    }
    // Gọi lại hàm đệ quy với các chỉ số và biến đếm mới
    return countQueen(a, m, n, i, j, count);
}

//Bai12
bool isSaddle(float a[][100], int m, int n, int i, int j){
    //Duyệt trên cột chứa phần tử đang xét a[i][j]] (nhỏ nhất trên cột)
    for(int u=0;u<m; u++){
        if(a[u][j]<a[i][j])
            return false;
    }
    //Duyệt trên hàng chứa phần tử đang xét a[i][j]] (lớn nhất trên hàng)
    for(int v=0;v<n;v++){
        if(a[i][v]>a[i][j])
            return false;
    }
    return true;
}

int countSaddle(float a[][100], int m, int n, int i, int j, int count){
    if (i == m) {
        return count;
    }
    if (isSaddle(a, m, n, i, j)) {
        count++;
    }
    if (j == n - 1) {
        i++;
        j = 0;
    }
    else {
        j++;
    }
    return countSaddle(a, m, n, i, j, count);