#include <iostream>
#include <cmath>
using namespace std;
int giai_thua(int a);
float dequy(float x, int n);

int main(){
    float x;
    int n;
    cout << "Nhap x, n: ";
    cin >> x >> n;
    cout << "Gia tri cua S(n)= )" << dequy(x,n);
    return 0;
}

int giai_thua(int a){
    int t=1;
    for(int i=a; i>=1; i--)
        t*=i;
    return t;
}
float dequy(float x, int n){
    if(n==0)
        return 1;
    return pow(x,2*n)/(giai_thua(2*n)) + dequy(x,n-1);
}