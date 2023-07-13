#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;
int max_index(int a[], int n);

int main(){
    int a[100];
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cout << "Max index: ";
    for(int i=0; i<n; i++){
        if(a[i] == max_index(a,n))
            cout << i+1 << " ";
    }
    return 0;
}

int max_index(int a[], int n){
    if(n==1)
        return a[0];
    else{
        if(a[n-1]>max_index(a,n-1))
            return a[n-1];
        else
            return max_index(a, n-1);
    }
}
