#include<bits/stdc++.h>
using namespace std;
void Nhap(int *a , int n) {
	for (int i = 0 ; i < n ; i++) {
		cin >> a[i];
	}
}
void Xuat(int *a, int &n) {
	for (int i = 0 ; i < n ; i++) cout << a[i] << " ";
}
void Sort(int *a , int n) {
	for (int i = 0 ; i< n ; i++) 
	for (int j = i + 1; j < n ; j++) {
		if (a[i] > a[j]) swap(a[i],a[j]);
	}
}
int main () {
	int n; cin >> n;
	int *a = new int[n];
	Nhap(a,n);
	Xuat(a,n);
	Sort(a,n);
	cout << "Sort : ";
	Xuat(a,n);
	return 0;
}