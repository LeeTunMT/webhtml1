#include <iostream>
#include <cmath>

using namespace std;

float tong_1(int n);
int tong_2(int n);
int day_fibonacci(int n);
void in_day_fibonacci();
int dao_nguoc(int n);
void in_dao_nguoc(int n);
int dem_so_chu_so(int n);
void doi_sang_nhi_phan(int n);
int ucln(int a,int b);
int bcnn(int a,int b);
long long luy_thua(int a, int b);

int main(){
    int n;
    // //Bai01
    // cout << "Nhap n: ";
    // cin >> n;
    // cout << "Tong s1 la: " << (float)tong_1(n) << endl;
    // //Bai02
    // cout << "Nhap n: ";
    // cin >> n;
    // cout << "Tong s2 la: " << tong_2(n) << endl;
    // //Bai03
    // in_day_fibonacci();
    // //Bai04
    // cout << "Nhap so nguyen duong n: ";
    // cin >> n;
    // cout << "Dao nguoc cua " << n << " la: ";
    // in_dao_nguoc(n);
    // cout << endl;
    // //Bai05
    // cout << "Nhap so nguyen duong n: ";
    // cin >> n;
    // cout << "So chu so cua " << n << " la: " << dem_so_chu_so(n) << endl;
    //Bai06
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    doi_sang_nhi_phan(n);
    cout << endl;
    // //Bai 07
    // int a,b;
    // cout << "Nhap 2 so a, b: ";
    // cin >> a >> b;
    // cout << "Uoc chung lon nhat cua " << a << " va " << b << " la: " << ucln(a,b) << endl;
    // //Bai08
    // cout << "Nhap 2 so a, b: ";
    // cin >> a >> b;
    // cout << "Boi chung nho nhat cua " << a << " va " << b << " la: " << bcnn(a,b) << endl;
    // //Bai09
    // int m;
    // cout << "Nhap m,n: ";
    // cin >> m >> n;
    // cout << m << " luy thua " << n << " bang: " << luy_thua(m,n) << endl;

    return 0;
}

//Bai01
float tong_1(int n){
    if(n==1)
        return 1;
    else 
        return (float)1/n+tong_1(n-1);
}

//Bai02
int tong_2(int n){
    if(n==0)
        return 0;
    else
        return (n*(n+1) + tong_2(n-1));
}

//Bai03
int day_fibonacci(int n){
    int kq;
    if(n==0 || n==1)
        return n;
    else
        return day_fibonacci(n-1) + day_fibonacci(n-2);
}

void in_day_fibonacci(){
    int n;
    cout << "Nhap n so fibonacci muon in ra man hinh: ";
    cin >>n;
    cout << n << " so fibonacci dau tien: ";
    for(int i=0; i<n; i++){
        cout << day_fibonacci(i) << "   ";
    }
    cout << endl;
}

//Bai04
int dao_nguoc(int n){
    int s=0;
    if(n<10)
        return n;
    else
    return n%10;
}

void in_dao_nguoc(int n){
    for(int i=n; i>0; i/=10){
        cout << dao_nguoc(i);
    }
}

//Bai05
int dem_so_chu_so(int n){
    if(n==0)
        return 0;
    else
        return 1 + dem_so_chu_so(n/10);
}

//Bai06
void doi_sang_nhi_phan(int n){
    if(n!=0){
        doi_sang_nhi_phan(n/2);
        cout << n%2;
    }
}

//Bai07
int ucln(int a, int b){
    if (b == 0) return a;
    if (a % b == 0) return b;
    return ucln(b, a%b);
}

//Bai08
int bcnn(int a,int b){
    return (a*b/ucln(a,b));
}

//Bai09
long long luy_thua(int a, int b){
    if (b == 0) return 1;
    return a * luy_thua(a, b-1);
}
