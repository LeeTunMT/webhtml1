#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct mang {
    float real;     //Phan thuc
    float image;    //Phan ao
};

void nhap(mang sp[], int &n);
void xuat(mang sp[], int n);
mang tong_so_phuc(mang sp[], int n);
mang tich_2_so_phuc(mang sp1, mang sp2);
mang tich_so_phuc(mang sp[], int n);
void output(mang sphuc);
void modun(mang sp[], int n);
void min_modun(mang sp[], int n);
void max_modun(mang sp[], int n);
void SelectionSort(mang sp[], int n);

int main(){
    int n;
    mang sp[100];

    nhap(sp,n);     // Nhap so phuc 

    xuat(sp,n);     // Xuat so phuc

    cout << "Tong cac so phuc trong mang la: ";
    output(tong_so_phuc(sp,n));

    cout << "Tich cac so phuc trong mang la: ";
    output(tich_so_phuc(sp,n));

    cout << "Cac modun cua tung so phuc tỏng mang: \n";
    modun(sp,n);

    min_modun(sp,n);    // So phuc co modun nho nhat

    max_modun(sp,n);    // So phuc co modun lon nhat

    cout << "Danh sach mang so phuc sau khi sap xep: \n";
    SelectionSort(sp,n);    // Sap xep danh sach cac so phuc theo modun tang dan
    xuat(sp,n);

    return 0;
}

void nhap(mang sp[], int &n){
    cout << "Nhap do dai mang so phuc: ";
    cin >> n;
    while (n<0 || n>50){
        cout << "Nhap la so phan tu n: ";
        cin >> n;
    }
    cout << "Nhap cac so phuc: ";
    for (int i=0; i<n; i++){
        cin >> sp[i].real >> sp[i].image;
    }
}

void xuat(mang sp[], int n){
    cout << "Danh sach mang so phuc: ";
    for(int i=0;i<n;i++){
        cout << sp[i].real << " + " << sp[i].image << "i" << "\t";
    }
    cout <<"\n";
}

mang tong_so_phuc(mang sp[], int n){
    mang sum;
    for (int i=0; i<n; i++){
        sum.real += sp[i].real;
        sum.image += sp[i].image;
    }
    return sum;
}

mang tich_2_so_phuc(mang sp1, mang sp2){
    mang tich;
    tich.real = sp1.real*sp2.real - sp1.image*sp2.image;
    tich.image = sp1.real*sp2.image + sp2.real*sp1.image;
    return tich;
}

mang tich_so_phuc(mang sp[], int n){
    mang tich =sp[0];
    for(int i=1; i<n; i++){
        tich = tich_2_so_phuc(tich, sp[i]);
    } 
    return tich;
}
void output(mang sphuc){
	cout << sphuc.real << "+" << sphuc.image << "i" << "\n";
}

void modun(mang sp[], int n){
    float modun[100];
    for(int i=0; i<n; i++){
        modun[i] = sqrt(pow(sp[i].real,2) + pow(sp[i].image,2));
    }
    for (int i=0; i< n; i++){
        cout << " modun cua " << sp[i].real << " + " << sp[i].image << "i" << " la: " << fixed << setprecision(2) << modun[i] << "\n";
    }
}

void min_modun(mang sp[], int n){
    int j=0 ;
    for (int i=1; i<n; i++){
        if(sqrt(pow(sp[i].real,2) + pow(sp[i].image,2)) < sqrt(pow(sp[j].real,2) + pow(sp[j].image,2))){
            j=i;
        }
    }
    cout << "So phuc co modun nho nhat la: " << sp[j].real << " + " << sp[j].image << "i" << "\n";
}

void max_modun(mang sp[], int n){
    int j=0 ;
    for (int i=1; i<n; i++){
        if(sqrt(pow(sp[i].real,2) + pow(sp[i].image,2)) > sqrt(pow(sp[j].real,2) + pow(sp[j].image,2))){
            j=i;
        }
    }
    cout << "So phuc co modun lon nhat la: " << sp[j].real << " + " << sp[j].image << "i" << "\n";
}

void SelectionSort(mang sp[], int n){
    for (int i = 0; i < n-1; i++) {
        int k = i;
        for (int j = i+1; j < n; j++){
            if (sqrt(pow(sp[j].real,2) + pow(sp[j].image,2)) < sqrt(pow(sp[k].real,2) + pow(sp[k].image,2))) 
                k = j;
        }
        swap(sp[i],sp[k]);
    }
}

