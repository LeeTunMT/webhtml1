#include <iostream>
#include <cmath>

using namespace std;

long long  dayX_dequy(int n);
long long dayX_khong_dequy(int n);

int main(){
    int n;
    cout << "Nhap n: ";
    cin >>n;
    cout << "Tong day X theo de quy la: " << dayX_dequy(n) << endl;
    cout << "Tong day X khong de quy la: " << dayX_khong_dequy(n) << endl;
    return 0;
}

long long dayX_dequy(int n){
    if(n==0)
        return 1;
    if(n==1)
        return 1;
    long long sum=0;
    for(int i=0; i<=n;i++)
        sum+= (i)*dayX_dequy(i-1);
    return sum;
}

long long dayX_khong_dequy(int n){
    if(n==0)
        return 1;
    if(n==1)
        return 1;
    if(n==2)
        return 3;
    long long xn=3;
    for (int i=2; i<=n-1; i++){
        xn += (i+1)*xn;
    }
    return xn;
}

