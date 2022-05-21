#include<iostream>
#include<string>
using namespace std;
/*trong 1 cong ty co 3 loai nhan vien
Nhan vien san xuat: ho  ten, ma so, nam sinh, so san pham
Nhan vien cong nhat: ho  ten, ma so, nam sinh, so ngay lam cong
Nhan vien quan li: ho  ten, ma so, nam sinh, he so luong*/

//====Khai bao lop cha=============
class NhanVien{
	protected:
		string hoten;
		string id;
		int namsinh;
	public:
		void Nhap();
		void Xuat();		
		
};
//===end khai bao lop cha==========

class NhanVienSanXuat:public NhanVien //cu phap Ke thua
{
	private:
		int so_san_pham;
	public:
		void Nhap();
		void Xuat();					
};

class NhanVienCongNhat:public NhanVien
{
	private:
		int so_ngay_cong;
	public:
		void Nhap();
		void Xuat();		
};

class NhanVienQuanLy:public NhanVien
{
	private:
		int he_so_luong;
	public:
		void Nhap();
		void Xuat();	
};



int main(){



	return 0;
}
