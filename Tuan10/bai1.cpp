#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
bool nguyenToCungNhau(int a, int b);

int main() {
    // Mở file input.txt để đọc dữ liệu
    ifstream fin("input.txt");
    if (!fin) {
        cout << "Không thể mở file input.txt" << endl;
        return 0;
    }
    else 
        cout << "Da doc file input.txt.\n";

    // Khai báo mảng một chiều để lưu trữ dữ liệu
    const int MAX = 100;
    int arr[MAX];
    int n = 0; // Số phần tử của mảng

    // Đọc dữ liệu từ file và lưu vào mảng
    while (fin >> arr[n]) {
        n++;
    }

    // Đóng file input.txt
    fin.close();

    // Mở file output.txt để ghi kết quả
    ofstream fout("output.txt");
    if (!fout) {
        cout << "Không thể mở file output.txt" << endl;
        return 0;
    }
    else    
        cout << "Da mo file output.txt\n";

    // Tính tổng các phần tử của mảng
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    fout << "Tổng các phần tử của mảng là: " << sum << endl;

    // Đếm số cặp số nguyên tố cùng nhau trong mảng
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nguyenToCungNhau(arr[i], arr[j])) {
                count++;
            }
        }
    }
    fout << "Số cặp số nguyên tố cùng nhau trong mảng là: " << count << endl;

    // Tìm giá trị lớn nhì trong mảng
    int max1 = arr[0]; // Giá trị lớn nhất
    int max2 = arr[0]; // Giá trị lớn nhì
    for (int i = 1; i < n; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] > max2 && arr[i] < max1) {
            max2 = arr[i];
        }
    }
    fout << "Giá trị lớn nhì trong mảng là: " << max2 << endl;

    // Sắp xếp mảng tăng dần
    sort(arr, arr + n);
    
    fout << "Mảng sau khi sắp xếp tăng dần là: ";
    
    for (int i = 0; i < n; i++) {
        fout << arr[i] << " ";
    }
    
    fout << endl;

    // Đóng file output.txt
    fout.close();

}

// Hàm kiểm tra hai số nguyên tố cùng nhau
bool nguyenToCungNhau(int a, int b) {
    // Tìm ước chung lớn nhất của a và b
    while (a != b) {
        if (a > b) {
            a = a - b;
        }
        else {
            b = b - a;
        }
    }
    // Nếu ước chung lớn nhất là 1 thì hai số nguyên tố cùng nhau
    return (a == 1);
}