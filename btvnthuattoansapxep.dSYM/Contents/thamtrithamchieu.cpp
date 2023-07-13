#include <iostream>

using namespace std;

void thamlam(int &x){
    x=0;
}
int main(){
    int x =3;
    thamlam(x);
    cout << x;
    return 0;
}