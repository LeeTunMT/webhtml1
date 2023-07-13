#include <iostream> 
using namespace std; 

int factorial(int n) {
    if (n == 1) //phần neo 
        return 1;
    else
        return (n * factorial(n - 1)); // phần đệ quy
}
int main(){
    cout << "Giai thua cua 5 la:" << factorial(4);
    return 0; 
}