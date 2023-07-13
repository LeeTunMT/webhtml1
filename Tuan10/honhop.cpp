#include <iostream>
#include <fstream>
using namespace std;

struct Diem {
    int x; // Hoành độ
    int y; // Tung độ
};
void nhapMang(Diem arr[], int &n, const char *fileName);
void xuatMang(Diem arr[], int n);
int demDiemDuong(Diem arr[], int n);
int timMaxY(Diem arr[], int n);
void timDiemMax(Diem arr[], int n, Diem result[], int &k);
int tongX(Diem arr[], int n);
int tongXDeQuy(Diem arr[], int n);
int tongY(Diem arr[], int n);
int tongYDeQuy(Diem arr[], int n);
Diem timPs(Diem arr[], int n);
Diem timPsDeQuy(Diem arr[], int n);

int main() {

   const char *fileName = "input4.txt"; // Tên file chứa dữ liệu
   const int MAX = 100;
   Diem arr[MAX][MAX]; // Mảng hai chiều để lưu trữ dữ liệu
   
   int m, n; // Số dòng và số cột của mảng
   
   nhapMang(arr, m, n, fileName); // Nhập dữ liệu từ file vào mảng
   
   cout << "Mang da nhap la: " << endl;
   
   xuatMang(arr, m, n); // Xuất dữ liệu từ mảng ra màn hình
   
   cout << "So luong diem co hoanh do duong la: " << demDiemDuong(arr, m, n) << endl; // Xuất số lượng điểm có hoành độ dương
   
   Diem result[MAX]; // Mảng để lưu kết quả
   
   int k; // Số lượng điểm có tung độ bằng giá trị lớn nhất
   
   timDiemMax(arr, m, n, result, k); // Tìm những điểm có tung độ bằng giá trị lớn nhất
   
   cout << "Cac diem co tung do bang gia tri lon nhat la: " << endl;
   
   xuatMang(result, k); // Xuất những điểm có tung độ bằng giá trị lớn nhất

   // Tìm điểm ps bằng vòng lặp
   Diem ps = timPs(arr, m, n);
   
   // Xuất điểm ps bằng vòng lặp
   cout << "Diem ps bang vong lap la: (" << ps.x << ", " << ps.y << ")" << endl;

   // Tìm điểm ps bằng đệ quy
   Diem psDeQuy = timPsDeQuy(arr, m, n);
   
   // Xuất điểm ps bằng đệ quy
   cout << "Diem ps bang de quy la: (" << psDeQuy.x << ", " << psDeQuy.y << ")" << endl;

}

// Hàm nhập mảng điểm từ file
void nhapMang(Diem arr[], int &n, const char *fileName) {
    // Mở file để đọc dữ liệu
    ifstream fin(fileName);
    if (!fin) {
        cout << "Không thể mở file " << fileName << endl;
        return;
    }

    // Đọc số lượng phần tử của mảng
    fin >> n;

    // Đọc từng phần tử của mảng
    for (int i = 0; i < n; i++) {
        fin >> arr[i].x >> arr[i].y;
    }

    // Đóng file
    fin.close();
}

// Hàm xuất mảng điểm ra màn hình
void xuatMang(Diem arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "(" << arr[i].x << ", " << arr[i].y << ") ";
    }
    cout << endl;
}

// Hàm đếm số lượng điểm có hoành độ dương trong mảng
int demDiemDuong(Diem arr[], int n) {
    int count = 0; // Biến đếm
    for (int i = 0; i < n; i++) {
        if (arr[i].x > 0) { // Nếu hoành độ dương thì tăng biến đếm
            count++;
        }
    }
    return count;
}

// Hàm tìm giá trị lớn nhất của tung độ trong mảng
int timMaxY(Diem arr[], int n) {
    int max = arr[0].y;
    for (int i = 1; i < n; i++) {
        if (arr[i].y > max) { 
            max = arr[i].y;
        }
    }
    return max;
}

// Hàm tìm những điểm có tung độ bằng giá trị lớn nhất trong mảng
void timDiemMax(Diem arr[], int n, Diem result[], int &k) {
    k = 0;
    int max = timMaxY(arr, n); 
    for (int i = 0; i < n; i++) {
        if (arr[i].y == max) {
            result[k] = arr[i];
            k++;
        }
    }
}

// Hàm tính tổng các hoành độ của các điểm trong mảng bằng vòng lặp
int tongX(Diem arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i].x;
    }
    return sum;
}

// Hàm tính tổng các hoành độ của các điểm trong mảng bằng đệ quy
int tongXDeQuy(Diem arr[], int n) {
    if (n == 0) {
        return 0;
    }
    else {
        return arr[n - 1].x + tongXDeQuy(arr, n - 1);
    }
}

// Hàm tính tổng các tung độ của các điểm trong mảng bằng vòng lặp
int tongY(Diem arr[], int n) {
    int sum = 0; 
    for (int i = 0; i < n; i++) {
        sum += arr[i].y;
    }
    return sum;
}

// Hàm tính tổng các tung độ của các điểm trong mảng bằng đệ quy
int tongYDeQuy(Diem arr[], int n) {
     if (n == 0) { 
        return 0;
     }
     else { 
         return arr[n - 1].y + tongYDeQuy(arr, n - 1);
     }
}

// Hàm tìm điểm ps theo yêu cầu bài toán bằng vòng lặp
Diem timPs(Diem arr[], int n) {
     Diem ps;
     
     ps.x = tongX(arr, n);
     
     ps.y = tongY(arr, n);
     
     return ps;
}

// Hàm tìm điểm ps theo yêu cầu bài toán bằng đệ quy
Diem timPsDeQuy(Diem arr[], int n) {
     Diem ps; 
     
     ps.x = tongXDeQuy(arr, n); 
     
     ps.y = tongYDeQuy(arr, n);
     
     return ps;
}