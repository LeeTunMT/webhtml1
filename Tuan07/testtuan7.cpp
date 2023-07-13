
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void swap(int *a, int *b);
void sum(int *p, int *q);
int sum(int *arr, int n);
int count_char(char *chuoi);
void concatenate(char *str1, char *str2);
void count_vowels_consonants(char str[]);
void find_min_max_3num(float *ptr1,float *ptr2,float *ptr3);

int main() {
    int a, b;
    cout << "input a: ";
    cin >> a;
    cout << "input b: ";
    cin >> b;
    swap(&a, &b);
    cout << "Gia tri cua 2 bien sau khi hoan doi la: \n";
    cout << "a = " << a << ", b = " << b << endl;

    int firstNumber, secondNumber, *p, *q;
    cout << "Nhập hai số nguyên: ";
    cin >> firstNumber >> secondNumber;
    p = &firstNumber;
    q = &secondNumber;
    sum(p, q);  

    int n;
    cout << "Nhap so phan tu mang: ";
    cin >> n;
    int arr[100];
    cout << "Nhap mang: ";
    for (int i=0; i<n; i++)
        cin >> arr[i];
    cout << "Tong cac gia tri trong mang la: " << sum(arr,a) << endl;

    char chuoi[100];
    cout << "Nhap chuoi: ";
    cin >> chuoi;
    cout << "So ki tu trong chuoi la: " << count_char(chuoi) << endl;


    char str1[100], str2[100];
    cout << "Nhap chuoi thu nhat: ";
    cin >> str1;
    cout << "Nhap chuoi thu hai:";
    cin >> str2;
    concatenate(str1,str2);
    cout << "Hai chuoi sau khi ghep la: "<< str1 << "\n";

    char str[100];
    cout << "Nhap chuoi: ";
    cin >> str;
    count_vowels_consonants(str);
    
    float ptr1,ptr2,ptr3;
    cout << "Nhap 3 so: ";
    cin >> ptr1 >> ptr2 >> ptr3;
    find_min_max_3num(&ptr1,&ptr2,&ptr3);
    return 0;
}

//Bai01
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Bai02
void sum(int *p, int *q){
    int sum = *p + *q;
    cout << "Tong cua hai so la: " << sum << endl;
}

//Bai03
int sum(int *arr, int n) {
    int sum = 0;
    int *ptr =arr;
    for (int i = 0; i < n; i++) {
        sum += *ptr;
        ptr++;
    }
    return sum;
}

//Bai04
int count_char(char *chuoi){
    int count =0;
    while(*chuoi != '\0'){
        count ++;
        chuoi++;
    }
    return count;
}

//Bai05
void concatenate(char *str1, char *str2) {
    while (*str1) {
        str1++;
    }
    while (*str2) {  
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
}

//Bai06
void count_vowels_consonants(char *ptr)
{
    int vowels = 0, consonants = 0;

    while (*ptr != '\0')
    {
        if (*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u' ||
            *ptr == 'A' || *ptr == 'E' || *ptr == 'I' || *ptr == 'O' || *ptr == 'U')
        {
            vowels++;
        }
        else if ((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z'))
        {
            consonants++;
        }

        ptr++;
    }
    cout << "So nguyen am: " << vowels << endl;
    cout << "So phu am: " << consonants << endl;
}
//Bai07
void find_min_max_3num(float *ptr1,float *ptr2,float *ptr3){
    float min=*ptr1;
    float max=*ptr1;
    if(*ptr2<min)
        min=*ptr2;
    if(*ptr3<min)
        min=*ptr3;
    if(*ptr2>max)
        max=*ptr2;
    if(*ptr3>max)
        max=*ptr3;
    cout << "Min= " << min << endl;
    cout << "Max= " << max << endl; 

}
