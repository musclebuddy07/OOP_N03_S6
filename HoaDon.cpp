#include<iostream>
#include<string>
using namespace std;
class KhachHang{
	private:
		string ten;
		string sdt;
		string diachi;
	public:
		KhachHang(){ten = "", sdt = "", diachi = "";};
		KhachHang(string ten, string sdt, string diachi){
			this->ten = ten;
			this->sdt = sdt;
			this->diachi = diachi;
		};
		friend class HoaDon;
		void Nhap();
};
void KhachHang::Nhap(){
	cout << "Ten khach hang: "; getline(cin, ten);
	cout << "So dien thoai: "; getline(cin, sdt);
	cout << "Dia chi: "; getline(cin, diachi);
}
class HangHoa{
	private:
		string Tenhh;
		int sl;
		int donggia;
	public:
		friend class HoaDon;
		HangHoa(){Tenhh = "",sl = 0, donggia = 0;};
		HangHoa(string Tenhh, int sl, int donggia){
			this->Tenhh= Tenhh;
			this->sl = sl;
			this->donggia = donggia;
		};
		void Nhap();
};
void HangHoa::Nhap(){
	cout << "Ten hang hoa: "; getline(cin, Tenhh);
	cout << "So luong: "; cin >> sl;
	cout << "Dong gia: "; cin >> donggia;
	cin.ignore();
	
}
class HoaDon{
	private:
		KhachHang kh; 
		HangHoa hh[15];
		string soHD, ngay;
		int n;
	public:
		void Nhap();
		HoaDon(){
			soHD ="";
			ngay = "";
			n = 0;
		};
		int TongDon(int i){
			return hh[i].sl* hh[i].donggia;
		}
		int TongTien();
		void Xuat();
};
int HoaDon::TongTien(){
	int tong = 0;
	for( int i = 0; i < n ; i++){
		tong += hh[i].sl* hh[i].donggia;
	}
	return tong;
}
void HoaDon:: Nhap(){
	cout << "So HD: "; getline(cin,soHD);
	cout << "Ngay: "; getline(cin, ngay);
	kh.Nhap();
	cout << "So mat hang ( toi da 15): "; cin >> n;
	cin.ignore();
	for ( int i = 0; i < n ; i++){
		cout << "---Mat Hang" << i + 1 << "---\n";
		hh[i].Nhap();
	}
}
void HoaDon::Xuat(){
	cout << "\n=====Hoa Don Ban Hang=====\n";
	cout << "So HD: " << soHD << "Ngay: " << ngay << "\n";
	cout << "Ten Khach Hang: " << kh.ten << " \n";
	cout << "So dien thoai: " << kh.sdt << "\n";
	cout << "Dia chi: " << kh.diachi << "\n";
	for ( int i = 0; i < n; i++){
		cout << i + 1 << "\t" << hh[i].Tenhh << "\t" << hh[i].sl << "\t" << hh[i].donggia << "\t" <<TongDon(i) << "\n" ;
	}
	cout << "Tong thanh toan: " << TongTien();
}
int main(){
	HoaDon hd;
	hd.Nhap();
	hd.Xuat();
	return 0;
}
