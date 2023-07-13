#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int decimalnum;
    cout << "Nhập vào số thập phân cần chuyển đổi: ";
    cin >> decimalnum;
    cout << "Số thập phân sau khi được chuyển thành số nhị phân là: " << bitset<32>(decimalnum).to_string();
    return 0;
}


// 2: 0010
// 6: 0110  2^2 +2^1
// 8: 1000
// 17: 2^4 + 2^0
// 1111: 8+4+2+1  
// 17: 0001 0001 
// -17 : 1 0001 