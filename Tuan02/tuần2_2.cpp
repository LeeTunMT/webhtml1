#include <iostream>
#include <cmath>
#define max 100

using namespace std;

void input_numZ(int& n, int m[]);
void output(int n, int m[]);
void input_numR(int& k, float a[]);
void add_num(int n, int m[]);
void delete_num(int n, int m[]);
void fix_num(int n, int m[]);
void find_locate_min(int n, int m[]);
int find_low_2004(int n, int m[]);
bool check_snt(int a);
void count_low_100(int n, int m[]);
void sum_neg(int k, float a[]);
void sort_increase(int k, float a[]);
void list_even_num(int n, int m[]);
void loacate_neg_nums(int n, int m[]);
int pos_num_first(int k, float a[]);
int find_even_num_last(int n, int m[]);
int find_locate_even_num_first(int n, int m[]);
bool check_perfect_num(int n);
int find_locate_perfect_num_last(int n, int m[]);
int find_prime_num_first(int n, int m[]);
int find_pos_num_last(int k, float a[]);
int find_prime_last(int n, int m[]);
int find_perfect_num_min(int n,int m[]);
int find_prime_max(int n, int m[]);
void find_first_num_interval_xy(int n,int m[]);
int square_num_first(int n, int m[]);
int bai22(int n, int m[]);
void even_num_min(int n, int m[]);
int gcd_2num(int a,int b);
int lcm_2num(int a,int b);
void lcm_array(int n, int m[]);
void gcd_array(int n, int m[]);
void even_nums_intervalxy(int n, int m[]);

int main() {
	int n,k;
	int m[100];
	float a[100];
	input_numZ(n, m);	//Bai01: Nhap mang so nguyen
	output(n, m);	//Bai02: Xuat mang so nguyen
	// input_numR(k, a);	//Nhap mang so thuc//
	// add_num(n,m);	//Bai02a: them 1 phan tu vao mang	
	// delete_num(n,m);	//Bai02b: xoa mot phan tu khoi mang
	// fix_num(n,m);		//Bai 02c: Sua mot phan tu mang
	// find_locate_min(n, m);		//Bai03: vi tri cua gia tri nho nhat trong mang
	// find_low_2004(n,m);		 //Bai04: kiem tra mang so nguyen co ton tai gia tri nho hon 2004 khong
	// count_low_100(n,m);		//Bai05: dem so luong so nguyen to nho hon 100;
	// sum_neg(k,a);		//Bai06: tong cac gia tri am trong mang mot chieu so thuc
	// sort_increase(k, a);	//Bai07: sap xep mang mot chieu so thuc tang dan
	// list_even_num(n, m);	//Bai08: liet ke cac gia tri chan trong mang mot chieu cac so nguyen
	// loacate_neg_nums(n, m);		//Bai09: liet ke cac vi tri ma gia tri tai do la so am 
	// cout << "So duong dau tien trong mang so thuc: " << pos_num_first(k, a) << endl;	//Bai10
	// cout << "So chan cuoi cung trong mang so nguyen la: " << find_even_num_last(n, m) << endl;	//Bai11
	// cout << "Vi tri cua gia tri chan dau tien trong mang so nguyen la: " << find_locate_even_num_first(n, m) << endl;		//Bai12
	// cout << "Vi tri so hoan thien cuoi cung trong mang so nguyen: " << find_locate_perfect_num_last(n, m) << endl;		//Bai13
	// cout << "So nguyen to dau tien trong mang so nguyen: " << find_prime_num_first(n, m) << endl;		//Bai14
	// cout << "So duong cuoi cung trong mang so thuc: " << find_pos_num_last(k, a) << endl;		//Bai15
	// cout << "So nguuyen to cuoi trong mang so nguyen: " << find_prime_last(n,m) << endl; 		//Bai16
	// cout << "So hoan thien nho nhat trong mang so nguyen: " << find_perfect_num_min(n,m) << endl; 		//Bai17
	// cout << "So nguyen to lon nhat: " << find_prime_max(n,m) << endl;		//Bai18
	// find_first_num_interval_xy(n,m);	//Bai19
	// square_num_first(n,m);		//Bai21: tim so chinh phuong dau tien trong mang mot chieu so nguyen
	// bai22(n,m);		//Bai22: Tim gia tri dau tien co chu so dau tien la so le 
	// even_num_min(n,m);		//Bai23: Tim so chan nho nhat trong mang so nguyen
	lcm_array(n,m);		//Bai24: Tim BCNN cua tat ca phan tu trong mang so nguyen
	gcd_array(n,m);		//Bai25: Tim UCLN cua tat ca phan tu trong mang so nguyen
	even_nums_intervalxy(n,m);		//Bai27: liet ke cac so chan cua mang trong doan cho truoc
	
	system("pause");		
	return 0; 
}    

//Bai01
void input_numZ(int& n, int m[]) { 
	cout << "___________________________________________________________________________________\n";
	cout << "Nhap so phan tu cua mang: ";
	cin >> n;
	while (n<0 || n> max) {
		cout << "So phan tu vuot qua gioi han. Vui long nhap lai: ";
		cin >> n;
	}
	cout << "Nhap mang so nguyen: ";
	for (int i = 0; i < n; i++) {
		cin >> m[i];
	}
	cout << "\n";
}

void output(int n, int m[]) {
	cout << "Danh sach mang: " << endl;
	for (int i = 0; i < n; i++) {
		cout << m[i] << "\t";
	}
	cout << endl;
	cout << "___________________________________________________________________________________\n";
}

void input_numR(int &k, float a[]) {
	cout << "Nhap so phan tu cua mang so thuc: ";
	cin >> k;
	while (k<0 || k> max) {
		cout << "So phan tu vuot qua gioi han. Vui long nhap lai: ";
		cin >> k;
	}
	cout << "Nhap mang so thuc: ";
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}
	cout << "___________________________________________________________________________________\n";
	cout << "\n";
}

//Bai02
void add_num(int n, int m[]) {
	int t[100];
	int g, h;
	cout << "Nhap vi tri muon them va gia tri cua phan tu do: ";
	cin >> g >> h;
	while (g<0 || g>n - 1) {
		cout << "Vi tri khong co trong mang. Nhap lai vi tri: ";
		cin >> g;
	}
	cout << endl;
	for (int i = 0; i < g; i++) {
		t[i] = m[i];
	}	//Tao mang moi giong nhu mang cu
	t[g] = h;
	for (int i = g; i < n; i++) {
		t[i + 1] = m[i];
	}
	cout << "Mang sau khi them la: \n";
	for (int i = 0; i < n + 1; i++) {
		cout << t[i] << "\t";
	}
	cout << endl;
	cout << "___________________________________________________________________________________\n";
}

void delete_num(int n, int m[]) {
	int t[100];
	int g;
	cout << "Nhap vi tri phan tu muon xoa: ";
	cin >> g;
	while (g<0 || g>n - 1) {
		cout << "Vi tri khong co trong mang. Nhap lai vi tri: ";
		cin >> g;
	}
	cout << endl;
	for (int i = 0; i < g; i++) {
		t[i] = m[i];
	}	// Tao mang moi giong nhu mang cu
	for (int i = g + 1; i < n; i++) {
		t[i - 1] = m[i];
	}
	cout << "Mang sau khi xoa la: \n";
	for (int i = 0; i < n - 1; i++) {
		cout << t[i] << "\t";
	}
	cout << endl;
	cout << "___________________________________________________________________________________\n";
}

void fix_num(int n, int m[]) {
	int t[100];
	int g, h;
	cout << "Nhap vi tri và gia tri phan tu muon sua: ";
	cin >> g >> h;
	while (g<0 || g>n - 1) {
		cout << "Vi tri khong co trong mang. Nhap lai vi tri: ";
		cin >> g;
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		t[i] = m[i];
	}	// Tao mang moi giong nhu mang cu
	t[g] = h;
	cout << "Mang sau khi sua la: \n";
	for (int i = 0; i < n; i++) {
		cout << t[i] << "\t";
	}
	cout << endl;
	cout << "___________________________________________________________________________________\n";
}

//bai03
void find_locate_min(int n, int m[]) {
	int k = 0, min = m[0];
	for (int i = 0; i < n; i++) {
		if (m[i] < min) {
			min = m[i];
			k = i;
		}
	}
	cout << "Vi tri ma tai do la gia tri nho nhat trong mang so nguyen la: " << k << "\n";
}

//Bai04
int find_low_2004(int n, int m[]) {
	for (int i = 0; i < n; i++) {
		if (m[i] < 2004 && m[i] % 2 == 0) {
			cout << "Mang ton tai so nguyen chan nho hon 2004\n";
			return 0;
		}
	}
	cout << "Mang khong ton tai so nguyen chan nho hon 2004\n";
	return 0;
}

//Bai05
bool check_snt(int a) {
	if (a < 2)
		return false;
	if (a % 2 == 0)
		return false;
	for (int i = 3; i < sqrt((float)a); i += 2) {
		if (a % i == 0)
			return false;
	}
	return true;
}

void count_low_100(int n, int m[]) {
	cout << "Cac so nguyen to nho hon 100: ";
	int dem = 0;
	for (int i = 0; i < n; i++) {
		if (m[i] < 100 && check_snt(m[i]) == true) {
			cout << m[i] << "\t";
			dem++;
		}
	}
	if (dem == 0)
		cout << "khong co so nao ca!!!\n";
	cout << endl;
}

//Bai06
void sum_neg(int k, float a[]) {
	float sum = 0;
	for (int i = 0; i < k; i++) {
		if (a[i] < 0)
			sum += a[i];
	}
	cout << "Tong cac gia tri am trong mang so thuc: " << sum << endl;
}

//Bai07
void sort_increase(int k, float a[]) {
	float t[100];
	for (int i = 0; i < k; i++) {
		t[i] = a[i];
	}
	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < k; j++) {
			if (t[i] > t[j])
				swap(t[i], t[j]);
		}
	}
	cout << "Mang so thuc sau khi sap xep tang dan la: ";
	for (int i = 0; i < k; i++) {
		cout << t[i] << "\t";
	}
	cout << endl;
}

//Bai08
void list_even_num(int n, int m[]) {
	cout << "Cac phan tu chan trong mang nguyen la: ";
	for (int i = 0; i < n; i++) {
		if (m[i] % 2 == 0)
			cout << m[i] << "\t";
	}
	cout << "\n";
}

//Bai09
void loacate_neg_nums(int n, int m[]) {
	cout << "Cac vi tri ma tai do phan tu am trong mang nguyen la: ";
	for (int i = 0; i < n; i++) {
		if (m[i] < 0)
			cout << i << "\t";
	}
	cout << endl;
}

//Bai10
int pos_num_first(int k, float a[]) {
	for (int i = 0; i < k; i++) {
		if (a[i] > 0) {
			return a[i];
		}
	}
	return -1;
}

//Bai11
int find_even_num_last(int n, int m[]) {
	for (int i = n - 1; i > 0; i--) {
		if (m[i] % 2 == 0) {
			return m[i];
		}
	}
	return -1;
}

//Bai12
int find_locate_even_num_first(int n, int m[]) {
	for (int i = 0; i < n; i++) {
		if (m[i] % 2 == 0) {
			return i;
		}
	}
	return -1;
}

//Bai13
bool check_perfect_num(int n) {
	int sum = 0;
	for (int i = 1; i <= n / 2; i++) {
		if (n % i == 0)
			sum += i;
	}
	if (sum == n)
		return true;
	return false;
}

int find_locate_perfect_num_last(int n, int m[]) {
	for (int i = n - 1; i > 0; i--) {
		if (check_perfect_num(m[i])) {
			return i;
		}
	}
	return -1;
}

//Bai14
int find_prime_num_first(int n, int m[]) {
	for (int i = 0; i < n; i++) {
		if (check_snt(m[i])) {
			return m[i];
		}
	}
	return -1;
}

//Bai 15
int find_pos_num_last(int k, float a[]) {
	for (int i = k - 1; i > 0; i--) {
		if (a[i] > 0) {
			return a[i];
		}
	}
	return -1;
}

//Bai16
int find_prime_last(int n, int m[]){
	for(int i=n-1; i>0; i--){
		if(check_snt(m[i]))
			return m[i];
	}
	return -1;
}

//Bai17
int find_perfect_num_min(int n,int m[]){
	int minp;
	for(int i=0;i<n;i++){
		if(check_perfect_num(m[i])){
			minp=m[i];
		}
	}
		for(int i=0;i<n;i++){
		if(check_perfect_num(m[i]) && m[i]< minp){
			minp=m[i];
		}
	}
	if(check_perfect_num(minp))
		return minp;
	return -1;
}

//Bai18
int find_prime_max(int n, int m[]){
	int maxp;
	for(int i=0;i<n;i++){
		if(check_snt(m[i])){
			maxp=m[i];
		}
	}
		for(int i=0;i<n;i++){
		if(check_snt(m[i]) && m[i]> maxp){
			maxp=m[i];
		}
	}
	if(check_snt(maxp))
		return maxp;
	return -1;
}

//Bai19
void find_first_num_interval_xy(int n,int m[]){
	float x,y;
	cout << " Nhập đoạn [x,y]: ";
	cin >> x >>y;
	int j=-1;
	for(int i=0; i<n; i++)
		if(m[i]>=x && m[i] <=y){
			cout << "Gia tri dau tien thuoc khoang [" << x <<"," << y << "] là: " << m[i] << endl;
			j = 0;
			break; 
		}	
	if(j==-1)
		cout << j;
}

//Bai21
int square_num_first(int n, int m[]){
	for (int i=0; i<n; i++){
		if(pow((int)sqrt(m[i]),2) == m[i]){
			cout << "So chinh phuong dau tien trong mang so nguyen la: " << m[i] << endl;
			return 0;
		}
	}
	cout << "Mang khong co so chinh phuong \n";
	return 0;
}

//Bai22
int bai22(int n, int m[]){
	for(int i=0; i< n; i++){
		int temp = m[i];
		while (abs(m[i]) > 9){
			m[i] = m[i]/10;
		}	
		if(m[i] %2!=0){
			cout << "Gia tri dau tien co chu so dau tien la so le la: " << temp << endl;
			return 0;
		}
	}
	cout << "Mang khong co gia tri nao ma no co chu so dau tien la so le \n";
	return 0;
}

//Bai23
void even_num_min(int n, int m[]){
	int j,min;
	for (int i=0; i<n; i++){
		if(m[i]%2 ==0){
			min = m[i];
			j=i;
			break;
		}
	}
	for(int i=j+1; i<n; i++){
		if(m[i] %2 ==0 && m[i] < min){
			min = m[i];
		}
	}
	if(min)
		cout << "So chan nho nhat trong mang la: " << min << endl;
	else 
		cout << "Mang khong co so chan\n";
}

//Bai24
int gcd_2num(int a,int b){		//Tim uoc chung lon nhat cua 2 phan tu
	a=abs(a);
	b=abs(b);
	if (a == 0 || b == 0){
        return a + b;
    }
    while (a != b){
        if (a > b){
            a -= b; 
        }else{
            b -= a;
        }
    }
    return a;
}

int lcm_2num(int a,int b){
	return (abs(a*b/gcd_2num(a,b)));
}

void lcm_array(int n, int m[]){
	int temp=lcm_2num(m[0],m[1]);
	for(int i=2;i<n;i++){
		temp= lcm_2num(temp,m[i]);
	}
	cout << "BCNN cua mang so nguyen la: " << temp << endl;
}

//Bai25
void gcd_array(int n, int m[]){
	int temp = gcd_2num(m[0],m[1]);
	for(int i=2;i<n;i++){
		temp = gcd_2num(temp,m[i]);
	}
	cout << "UCLN cua mang so nguyen la: " << temp << endl;
}

//Bai26
void even_nums_intervalxy(int n, int m[]){
	int x,y, j=0;
	cout << " Nhập đoạn [x,y]: ";
	cin >> x >>y;
	cout << "cac gia tri chan thuoc [" << x <<"," << y << "] là: ";
	for(int i=0; i<n; i++){
		if(m[i]>=x && m[i] <=y && m[i] %2 ==0){
		cout << m[i] << " ";	
		j++;
		}	
	}
	if(j==0)
		cout << "khong co gia tri nao\n";
	else 
		cout << endl;
}
