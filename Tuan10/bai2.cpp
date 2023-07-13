#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

bool nguyenTo(int n);

int main() {
    // Mở file input2.txt để đọc dữ liệu
    ifstream fin("input2.txt");
    if (!fin) {
        cout << "Không thể mở file input2.txt" << endl;
        return 0;
    }

    // Khai báo mảng một chiều để lưu trữ dữ liệu
    const int MAX = 100;
    int arr[MAX];
    int n; // Số phần tử của mảng

    // Đọc dữ liệu từ file và lưu vào mảng
    fin >> n; // Đọc số lượng phần tử
    for (int i = 0; i < n; i++) {
        fin >> arr[i]; // Đọc từng phần tử
    }

    // Đóng file input2.txt
    fin.close();

    // Mở file output2.txt để ghi kết quả
    ofstream fout("output2.txt");
    if (!fout) {
        cout << "Không thể mở file output2.txt" << endl;
        return 0;
    }

    // Tính tổng các phần tử của mảng
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    fout << "Tổng các phần tử của mảng là: " << sum << endl;

    // Đếm số lượng số nguyên tố trong mảng
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (nguyenTo(arr[i])) {
            count++;
        }
    }
    
    fout << "Số lượng số nguyên tố trong mảng là: " << count << endl;

    
   // Tìm giá trị lớn thứ m trong mảng
   int m; // Chỉ số của giá trị lớn thứ m
   
   cout << "Nhập giá trị của m: ";
   cin >> m;
   
   if (m > n || m <= 0) {
       cout << "Giá trị của m không hợp lệ" << endl;
       return 0;
   }
   
   // Sao chép mảng sang một mảng khác để không làm thay đổi thứ tự ban đầu
   int temp[MAX];
   
   for (int i = 0; i < n; i++) {
       temp[i] = arr[i];
   }
   
   // Sắp xếp mảng tạm giảm dần
   sort(temp, temp + n, greater<int>());
   
   // Lấy giá trị lớn thứ m trong mảng tạm
   int max_m = temp[m - 1];
   
   fout << "Giá trị lớn thứ " << m << " trong mảng là: " << max_m << endl;

    
   // Sắp xếp mảng giảm dần
   
   sort(arr, arr + n, greater<int>());
   
   fout << "Mảng sau khi sắp xếp giảm dần là: ";
   
   for (int i = 0; i < n; i++) {
       fout << arr[i] << " ";
   }
   
   fout << endl;

    
   // Đóng file output2.txt
   
   fout.close();

}

// Hàm kiểm tra số nguyên tố
bool nguyenTo(int n) {
    // Nếu n nhỏ hơn 2 thì không phải số nguyên tố
    if (n < 2) {
        return false;
    }
    // Nếu n bằng 2 hoặc 3 thì là số nguyên tố
    if (n == 2 || n == 3) {
        return true;
    }
    // Nếu n chia hết cho 2 hoặc 3 thì không phải số nguyên tố
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    // Kiểm tra các ước từ 5 đến căn bậc hai của n
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    // Nếu không có ước nào thì là số nguyên tố
    return true;
}