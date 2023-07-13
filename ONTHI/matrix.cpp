#include <iostream>

using namespace std;

void input(int a[][100], int m, int n);
void output(int a[][100], int m, int n);

int main(){
    int a[100][100];
    int m,n;
    cin >> m >> n;
    input(a,m,n);
    cout << "Your matrix: \n";
    output(a,m,n);
    return 0;
}

void input(int a[][100], int m, int n){
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
}

void output(int a[][100], int m, int n){
    for (int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << a[i][j] << "\t";
        }
        cout << "\n";
    }
}

bool check_extreme(int a[][100],int m, int n, int dong, int cot){
    bool cucdai = true, cuctieu = true;
    
}
