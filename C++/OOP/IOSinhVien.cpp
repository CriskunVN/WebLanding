#include<bits/stdc++.h>
using namespace std;
class Sinhvien {
	private :
		string ten , lop , ns;
		float gpa;
	public : 
		string get_lop() {
			this->lop;
		}; 
		Sinhvien() {
			ten = lop = ns = "";
			gpa = 0;
		}
		Sinhvien(string name, string cl , string ns , float gpa) {
			this->ten = name;
			this->lop = cl;
			this->ns = ns;
			this->gpa = gpa;
		}
		friend istream& operator >> (istream& is,Sinhvien &a);
		friend ostream& operator << (ostream& os,Sinhvien a);
		bool operator < (Sinhvien another) {
			return this->lop < another.lop;
		}
		string get_name() {
			return this->ten;
		}
};
string chuanhoa_name(string name) {
	string res = "";
	stringstream ss(name);
	string token;
	while (ss >> token) {
		res += toupper(token[0]);
		for (int i = 1 ; i < token.length() ; i++) {
			res += tolower(token[i]);
		}
	res += " ";	
	}
	res.erase(res.length()-1);
	return res; 
}
istream& operator >> (istream& is , Sinhvien &a){
	is.ignore();
	cout << "Nhap ten sinh vien : "; getline(is,a.ten);
	cout << "Nhap lop : "; getline(is,a.lop);
	cout << "Nhap ngay sinh : "; is >> a.ns;
		if (a.ns[2] != '/' ) a.ns = "0" + a.ns;
		if (a.ns[5] != '/' ) a.ns.insert(3, "0");
	cout << "Nhap GPA : "; is >> a.gpa;
	is.ignore();
		
	return is;
}
ostream& operator << (ostream& os , Sinhvien a) {
	os << "B20DCCN001" << " " << a.ten << " " << a.lop << " " << a.ns << " " << fixed << setprecision(2) << " " <<  a.gpa;
	return os;
}
bool cmp(Sinhvien a, Sinhvien b) {
	return a.get_lop() < b.get_lop();
}
bool FindName(string name , string q) {
	for (char &x : name) x = tolower(x);
	for (char &x : q) x = tolower(x);
	// nếu ko tìm thấy thì hàm method find() sẽ trả về giá trị string::npos
	return name.find(q) != string::npos; 
}

int main () {
	int n ; cin >> n;
	// khai báo 1 vector chứa n sinh vien
	vector <Sinhvien> v(n);
	Sinhvien tmp;
	// nhập thông tin cho sinh viên
	while (cin >> tmp) {
		// thêm sinh viên vào trong vector
		v.push_back(tmp);
	}
	// sắp xếp sinh viên
		sort(v.begin(),v.end());
		string q;
		cout << "Nhap ten muon tim : "; getline(cin , q);
		for (Sinhvien x : v) {
			if (FindName(x.get_name(),q)) cout << x;
		}
	for (Sinhvien x : v) {
		cout << x << " ";
	}
	
	return 0;
}
