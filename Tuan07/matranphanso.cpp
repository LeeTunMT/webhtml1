#include <iostream>

using namespace std;

struct PhanSo
{
    int tu;
    int mau;
};

void nhapMaTranPhanSo(PhanSo A[][100], int m, int n);
int gcd(int a, int b);
void rut_gon_ps(PhanSo &ps);
void xuatMaTranPhanSo(PhanSo A[][100], int m, int n);
bool kt_doi_xung(PhanSo A[][100], int m, int n);
void tinh_dinh_thuc(PhanSo A[][100], int m, int n);
void mt_bac_thang(PhanSo A[][100], int m, int n);
PhanSo tich_2ps(PhanSo ps1, PhanSo ps2);
PhanSo cong_2ps(PhanSo ps1, PhanSo ps2);
PhanSo thuong_2ps(PhanSo ps1, PhanSo ps2);
PhanSo hieu_2ps(PhanSo ps1, PhanSo ps2);
int hang_ma_tran(PhanSo A[][100], int m, int n);
void nhap_2mt(PhanSo a[][100], PhanSo b[][100],int &m, int &n, int &p, int &q);
void tong_2mt(PhanSo a[][100], PhanSo b[][100], int m, int n, int p, int q);
void tich_2mt(PhanSo a[][100], PhanSo b[][100], int m, int n, int p, int q);

int main()
{
    PhanSo A[100][100];
    int m, n;

    cout << "Nhap so dong cua ma tran: ";
    cin >> m;

    cout << "Nhap so cot cua ma tran: ";
    cin >> n;

    nhapMaTranPhanSo(A, m, n);

    cout << endl << "Ma tran phan so vua nhap la:" << endl;
    xuatMaTranPhanSo(A, m, n);

    if(kt_doi_xung(A, m, n))
        cout << "Ma tran A la ma tran doi xung\n";
    else 
        cout << "Ma tran A khong doi xung\n";
    cout << "\n";

    tinh_dinh_thuc(A,m,n);
    cout << "\n";

    cout << "Ma tran bac thang cua A la: \n";
    mt_bac_thang(A, m, n);
    xuatMaTranPhanSo(A, m, n);

    cout << "Hang cua ma tran A la:" << hang_ma_tran(A,m,n) << "\n\n";

    PhanSo a[100][100];
    PhanSo b[100][100];
    int p,q;
    nhap_2mt(a,b,m,n,p,q);
    tong_2mt(a,b,m,n,p,q);
    tich_2mt(a,b,m,n,p,q);
    return 0;
}

void nhapMaTranPhanSo(PhanSo A[][100], int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
        {
            cout << "Nhap phan so tai vi tri [" << i << "][" << j << "]: ";
            cin >> A[i][j].tu >> A[i][j].mau;
            while(A[i][j].mau == 0){
                cout << "Nhap lai phan so tai vi tri [" << i << "][" << j << "]: ";
                cin >> A[i][j].tu >> A[i][j].mau;              
            }
        }
    }
}

int gcd(int a, int b) {         //Tìm UCLN cua 2 so
    if (b == 0) return a;
    return gcd(b, a % b);
}
void rut_gon_ps(PhanSo &ps){
    int ucln=gcd(ps.tu,ps.mau);
    ps.tu/=ucln;    //Rut gon bang cach chia ca hai cho UCLN
    ps.mau/=ucln;
}

void xuatMaTranPhanSo(PhanSo A[][100], int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            rut_gon_ps(A[i][j]);                //Rút gọn phân số
            cout << A[i][j].tu << "/" << A[i][j].mau << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool kt_doi_xung(PhanSo A[][100], int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if(A[i][j].tu!=A[j][i].tu || A[i][j].mau!=A[j][i].mau)      //Kiem tra co phan tu doi xung tren duong cheo chinh
                return false;
        }
    }
    return true;
    
}
PhanSo tich_2ps(PhanSo ps1, PhanSo ps2){
    PhanSo ps;
    ps.tu=ps1.tu*ps2.tu;
    ps.mau=ps1.mau*ps2.mau;
    rut_gon_ps(ps);
    return ps;
}
PhanSo cong_2ps(PhanSo ps1, PhanSo ps2){
    PhanSo ps;
    ps.tu=ps1.tu*ps2.mau + ps2.tu*ps1.mau;
    ps.mau=ps1.mau*ps2.mau;
    rut_gon_ps(ps);
    return ps;
}
PhanSo thuong_2ps(PhanSo ps1, PhanSo ps2){
    PhanSo ps;
    ps.tu=ps1.tu*ps2.mau;
    ps.mau=ps1.mau*ps2.tu;
    rut_gon_ps(ps);
    return ps;
}
PhanSo hieu_2ps(PhanSo ps1, PhanSo ps2){
    PhanSo ps;
    ps.tu=ps1.tu*ps2.mau - ps2.tu*ps1.mau;
    ps.mau=ps1.mau*ps2.mau;
    rut_gon_ps(ps);
    return ps;
}

//Bai04
void tinh_dinh_thuc(PhanSo A[][100], int m, int n){
    if(m==n && m<=3){
        if(m==1)
            cout << "Det(A) = " << A[0][0].tu << "/" << A[0][0].mau << endl;
        if(m==2){
            PhanSo det;
            A[0][1].tu=-A[0][1].tu;
            det=cong_2ps(tich_2ps(A[0][0],A[1][1]),tich_2ps(A[0][1],A[1][0]));
            rut_gon_ps(det);
            cout << "Det(A) = " << det.tu << "/" << det.mau << endl;
        }
        if(m==3){              
//Cách 1: Biến đổi phần tử đầu tiên của dòng 2 và 3 thành 0 để dùng công thức CỘT 1. ĐỊNH THỨC TRỞ VỀ TÍNH ĐỊNH THỨC CẤP 2
            PhanSo det;
            if(A[0][0].tu != 0){
                for(int j=1; j<n; j++){     //không bắt đầu từ 0 vì giá trị của A[1][0] và A[2][0] sẽ thay đổi và các phần tử cùng hàng sẽ sai công thức.
                    A[1][j]=hieu_2ps(A[1][j],tich_2ps(thuong_2ps(A[1][0],A[0][0]),A[0][j]));
                    A[2][j]=hieu_2ps(A[2][j],tich_2ps(thuong_2ps(A[2][0],A[0][0]),A[0][j]));
                }
                det=tich_2ps(A[0][0],hieu_2ps(tich_2ps(A[1][1],A[2][2]),tich_2ps(A[1][2],A[2][1])));
                rut_gon_ps(det);                
            }
            else{   //Phần tử đầu tiên của hàng 1 bằng không thì tới bước này
                    if(A[1][0].tu != 0){     //Nếu phần tử đầu tiên dòng 1 khác 0 thì đổi hàng 0 với hàng 1
                        for(int v=0; v<n; v++){
                            swap(A[0][v],A[1][v]);
                        }
                    }
                    else if(A[2][0].tu != 0){   //Nếu phần tử đầu tiên dòng 2 khác 0 thì đổi hàng 0 với hàng 2
                        for(int v=0; v<n; v++){
                            swap(A[0][v],A[2][v]);
                        }
                    }
                    for(int j=1; j<n; j++){         //Tính định thức như trên
                        A[1][j]=hieu_2ps(A[1][j],tich_2ps(thuong_2ps(A[1][0],A[0][0]),A[0][j]));
                        A[2][j]=hieu_2ps(A[2][j],tich_2ps(thuong_2ps(A[2][0],A[0][0]),A[0][j]));
                    }
                    det=tich_2ps(A[0][0],hieu_2ps(tich_2ps(A[1][1],A[2][2]),tich_2ps(A[1][2],A[2][1])));
                    rut_gon_ps(det);
                    if(A[1][0].tu != 0 && A[2][0].tu != 0){     //Nếu tất cả phần tử của cột đầu tiên bằng 0 thì det=0
                        det.tu=0;
                        det.mau=1;
                    }
                }
            cout << "Det(A) = " << det.tu << "/" << det.mau << endl;

//Cách 2:(quy tắc sarrus)  
            // PhanSo det;
            // Tính tử số của kết quả bằng công thức định thức
            // det.tu = A[0][0].tu * A[0][0].mau * A[1][1].tu * A[1][1].mau * A[2][2].tu * A[2][2].mau
            //         + A[0][1].tu * A[0][1].mau * A[1][2].tu * A[1][2].mau * A[2][0].tu * A[2][0].mau
            //         + A[0][2].tu * A[0][2].mau * A[1][0].tu * A[1][0].mau * A[2][1].tu * A[2][1].mau
            //         - A[0][0].tu * A[0][0].mau * A[1][2].tu * A[1][2].mau * A[2][1].tu * A[2][1].mau
            //         - A[0][1].tu * A[0][1].mau * A[1][0].tu * A[1][0].mau * A[2][2].tu * A[2][2].mau
            //         - A[0][2].tu * A[0][2].mau * A[1][1].tu * A[1][1].mau * A[2][0].tu * A[2][0].mau;
            // // Tính mẫu số của kết quả bằng tích các mẫu số của các phần tử trong ma trận
            // det.mau = 1;
            // for (int i = 0; i < 3; i++) {
            //     for (int j = 0; j < 3; j++) {
            //         det.mau *= A[i][j].mau;
            //     }
            // }
            // rut_gon_ps(det);
            // cout << "Det(A) = " << det.tu << "/" << det.mau << endl;
        }
    }
    else 
        cout << "A khong phai la ma tran cap 1, 2, 3 nen khong tinh dinh thuc\n";
}

//Bai05
void mt_bac_thang(PhanSo A[][100], int m, int n){
    int i=0, j=0;       //Bước 1
    while(i<m && j<n){      //Bước 2
        if(A[i][j].tu !=0){     //Đúng sang bước 3
            for(int k=i+1; k<m; k++){       //Bước 3
                PhanSo temp;
                temp=thuong_2ps(A[k][j],A[i][j]);
                for(int u=0; u<n; u++){
                    A[k][u]=hieu_2ps(A[k][u],tich_2ps(temp,A[i][u]));
                }   
            }
        }
        else {      //Sai sang bước 4
            int dem=0;
            for(int k=i+2; k<m; k++){       //Bước 4
                if(A[k][j].tu != 0){
                    for(int v=0; v<n; v++){
                        swap(A[i][v],A[k][v]);
                    }
                    for(int k=i+1; k<m; k++){       //Quay về bước 3
                        PhanSo temp;
                        temp=thuong_2ps(A[k][j],A[i][j]);
                        for(int u=0; u<n; u++){
                            A[k][u]=hieu_2ps(A[k][u],tich_2ps(temp,A[i][u]));
                        }   
                    }
                    dem++;
                    break;       
                }
            }
            if(dem==0){     //Nếu A(kj) = 0 với mọi k thì j=j+1 và quay về bước 2
                i--;        //Vì chạy tiếp thì i tăng một và j tăng 1 nên ở đây trừ 1 của i để i không đổi
            }
        }
        i++;
        j++;
    }
}

//Bai06
int hang_ma_tran(PhanSo A[][100], int m, int n) {
    // Biến đếm số hàng khác không
    int count = 0;
    for (int i = 0; i < m; i++) {    // Duyệt qua từng hàng của ma trận
        bool zero = true;       // Biến kiểm tra hàng có toàn số 0 hay không
        for (int j = 0; j < n; j++) {    // Duyệt qua từng phần tử của hàng
            if (A[i][j].tu != 0) {      // Nếu phần tử khác 0, đặt zero bằng false và thoát khỏi vòng lặp
                zero = false;
                break;
            }
        }
        if (!zero) {    // Nếu hàng không toàn số 0, tăng biến đếm lên 1
            count++;
        }
    }
    return count;
}
//Bai07

void nhap_2mt(PhanSo a[][100], PhanSo b[][100],int &m, int &n, int &p, int &q){
    cout << "Nhap so dong ma tran a: ";
    cin >> m;
    cout << "Nhap so cot ma tran a: ";
    cin >> n;
    nhapMaTranPhanSo(a,m,n);
    xuatMaTranPhanSo(a,m,n);

    cout << "Nhap so dong ma tran b: ";
    cin >> p;
    cout << "Nhap so cot ma tran b: ";
    cin >> q;
    nhapMaTranPhanSo(b,p,q);
    xuatMaTranPhanSo(b,p,q);
}
void tong_2mt(PhanSo a[][100], PhanSo b[][100], int m, int n, int p, int q){
    PhanSo c[100][100];
    if(m==p && n==q){
        for (int i=0; i<m; i++){
            for(int j=0;j<n; j++){
                c[i][j]=cong_2ps(a[i][j], b[i][j]);
            }
        }
        cout << "Tong hai ma tran tren la:\n ";
        xuatMaTranPhanSo(c,m,n);
    }
    else
        cout << "Hai ma tran khong cung cap nen khong the tinh tong\n";
}

void tich_2mt(PhanSo a[][100], PhanSo b[][100], int m, int n, int p, int q){
    PhanSo c[100][100];
    if(n==p){           //a(mn) x b(pq) = c(mq)
        for(int i=0; i<m; i++){
            for(int j=0; j<q; j++){
                c[i][j].tu=0;   
                c[i][j].mau=1;
                for(int k=0; k<n; k++){
                    c[i][j]= cong_2ps(c[i][j],tich_2ps(a[i][k],b[k][j]));       //phần tử vị trí ij của c bằng dòng i của ma trận a nhân cột j của ma trận b
                }
            }
        }
        cout << "Tich hai ma tran a.b la: \n";
        xuatMaTranPhanSo(c,m,q);
    }

    if(q==m){           //b(pq) x a(mn) = c(pn)
        for(int i=0; i<p; i++){
            for(int j=0; j<n; j++){
                c[i][j].tu=0;
                c[i][j].mau=1;
                for(int k=0; k<q; k++){
                    c[i][j]= cong_2ps(c[i][j],tich_2ps(b[i][k],a[k][j]));       
                }
            }
        }           
        cout << "Tich hai ma tran b.a la: \n";
        xuatMaTranPhanSo(c,p,n);
    }

    if(n!=p && q!=m) 
        cout << "Khong the tinh tich hai ma tran nay\n";
}

