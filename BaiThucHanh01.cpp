#include<iostream>
#include<algorithm>
using namespace std;

class Xe {
	private:
		int maXe;                  // Mã d?nh danh xe
		string loaiXe;             // "Car", "Motorcycle", "Bicycle"
		int gioVao;                // 0..23
		int thoiGianDo;           // 1..23
		double phiDoXe;            // VND
		bool dangChiemCho;
	public:
		Xe(){
			maXe = 0;
			loaiXe = "";
			gioVao = 0;
			thoiGianDo = 0;
			phiDoXe = 0;
			dangChiemCho = false;
			};		
		Xe(int ma, const string& loai, int gio, int thoiLuong);
		int layMaXe() const;
		string layLoaiXe() const;
		int layGioVao() const;
		int layThoiGianDo() const;
		double layPhiDoXe() const;
		bool layDangChiemCho() const;
		void ganMaXe(int ma);
		void ganLoaiXe(const string& loai);
		void ganGioVao(int gio);
		void ganThoiLuongDo(int thoiLuong);
		void ganPhiDoXe(double phi);
		void ganDangChiemCho(bool trangThai);
		static string chuanHoaLoaiXe(const string& loai);
		static bool laLoaiXeHopLe(const string& loai);
		void tinhPhiDoXe();
		void hienThi() const;
	}
}
void Xe::hienThi(){
	cout << "Ma xe: " << maXe << " Loai: " << loaiXe << " Gio vao: "
	<< gioVao << " Thoi gian do: " << thoiGianDo << " Phi Do Xe: "
	<< phiDoXe;
};
void Xe::tinhPhiDoXe(){
	double dongia = 0.0;
	string loaithuong = loaixe;
	transform(loaithuong.begin(),loaithuong.end(), loaithuong.begin(), ::tolower());
	
	if (loaithuong == "car"){
		dongia = 6.00;
	}
	if(loaithuong == "motorcycle"){
		dongia = 4.00;
	}
	if (loaithuong == "bicycle"){
		dongia = 2.00;
	}
	double tongphi = 0.0;
	for (int i = 1; i <= thoigianDo; i++){
		int GioHienTai = (gioVao + i -1) % 24;
		bool laGioCaoDiem = (((GioHienTai >= 6)&& (GioHienTai <= 9 )) || ((GioHienTai >= 15)&& (ioHienTai <= 18)));
			if ( i < 2){
				if (laGioCaoDiem){
					dongia *= 1.30;
				}
				else {
					dongia *= 0.95;
				}
			else dongia *= 0.90;
		tongphi += dongia;
	}
	phiDoXe = tongphi;
}
class  BaiDo{
	int MaBai;
	char KichThuoc;
	Xe xe1, xe2, xe3;
	bool CoXe1, CoXe2, CoXe3;
	public:
		BaiDo(){
			MaBai = 0;
			KichThuoc = "";
			CoXe1 = false;
			CoXe2 = false;
			CoXe3 = false;
		};
		BaiDo(int ID, char s){
			MaBai = ID;
			KichThuoc = toupper(s);
			CoXe1 = false;
			CoXe2 = false;
			CoXe3 = false;
		};
		bool ThemXe(const Xe& v);
		bool XoaXe(int vID);
		void HienThiThongTin();	
};
bool BaiDo::ThemXe(){
	if (KichThuoc== 'S'){
		if (!CoXe1){
			xe1 = v;
			CoXe1 = true;
			return true;
		}
	}
	else if(KichThuoc == 'M'){
		if(!CoXe1){
			xe1 = v;
			CoXe1 = true;
			return true;
		}
		if(!CoXe2){
			xe2 = v;
			CoXe2 = true;
			return true;
		}
	}
	else if (KichThuoc == 'L'){
		if(!CoXe1){
			xe1 = v;
			CoXe1 = true;
			return true;
		}
		if (!CoXe2){
			xe2 = v;
			CoXe2 = true;
			return true;
		}
		if (!CoXe3){
			xe3 = v;
			CoXe3 = true;
			return true;
		}
	}
	return false;
};
void BaiDo::HienThiThongTin(){
	cout << "Bai do Ma: " << MaBai << "Kich Thuoc: " << KichThuoc;
	if (CoXe1) cout << "Vi tri 1: " << xe1.hienthi();
	if (CoXe2) cout << "Vi tri 2: " << xe2.hienThi();
	if (CoXe3) cout << "Vi tri 3: " << xe3.hienthi();
};
