#include <iostream>
#include <fstream>
#define MAX 100

using namespace std;

int main() {
    // Mở file input3.txt để đọc dữ liệu
    ifstream fin("input3.txt");
    if (!fin) {
        cout << "Không thể mở file input3.txt" << endl;
        return 0;
    }

    int arr[MAX][MAX];
    int m, n; 

    fin >> m >> n; 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fin >> arr[i][j]; 
        }
    }

    fin.close();

    // Mở file output3.txt để ghi kết quả
    ofstream fout("output3.txt");
    if (!fout) {
        cout << "Không thể mở file output3.txt" << endl;
        return 0;
    }

    // Tính tổng các phần tử của mảng
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum += arr[i][j];
        }
    }
    
    fout << "Tổng các phần tử của mảng là: " << sum << endl;

    // Đếm số lượng chẵn và lẻ trong mảng
    int even = 0; 
    int odd = 0; 
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] % 2 == 0) {
                even++;
            }
            else {
                odd++;
            }
        }
    }
    
    fout << "Số lượng chẵn trong mảng là: " << even << endl;
    
    fout << "Số lượng lẻ trong mảng là: " << odd << endl;

   fout.close();
   
}