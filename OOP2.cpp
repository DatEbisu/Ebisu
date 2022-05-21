#include<iostream>
using namespace std;
#include<string>
#include<cstdio>

//=======KHAI BAO NHAN VIEN SUA ONG NUOC============
class NhanVienSuaOngNuoc
{
private:
	string hoten;
	int Tuoi;
	string gioi_tinh;	
	string dia_chi;	
	string sdt;		
	float chieu_cao;
	float can_nang;
	float so_gio_sua;
public:
	void Nhap();
	void Xuat();
	float Tinh_Tien_Luong();
	NhanVienSuaOngNuoc();
	~NhanVienSuaOngNuoc();		
	
};
//Ham nhap thong tin sua ong nuoc
void NhanVienSuaOngNuoc::Nhap()
{
	fflush(stdin);	
	cout<<"\nNhap ho ten: ";
	getline(cin,hoten);
	fflush(stdin);	
	cout<<"\nNhap tuoi: ";
	cin>>Tuoi;
	fflush(stdin);		
	cout<<"\nNhap gioi tinh: ";
	getline(cin,gioi_tinh);	
	fflush(stdin);	
	cout<<"\nNhap dia chi: ";
	getline(cin,dia_chi);
	fflush(stdin);	
	cout<<"\nNhap SDT: ";
	getline(cin,sdt);
	fflush(stdin);	
	cout<<"\nNhap chieu cao: ";
	cin>>chieu_cao;	
	cout<<"\nNhap can nang: ";
	cin>>can_nang;	
	cout<<"\nNhap so gio sua: ";
	cin>>so_gio_sua;						
}

//Ham xuat thong tin nhan vien sua ong nuoc
void NhanVienSuaOngNuoc::Xuat()
{
	cout<<"\nHo ten: "<<hoten;
	cout<<"\nTuoi: "<<Tuoi;
	cout<<"\nGioi tinh: "<<gioi_tinh;	
	cout<<"\nDia chi: "<<dia_chi;
	cout<<"\nSDT: "<<sdt;	
	cout<<"\nChieu cao: "<<chieu_cao;
	cout<<"\nCan nang: "<<can_nang;							
}
//Ham tinh tien luong nhan vien sua ong nuoc
float NhanVienSuaOngNuoc::Tinh_Tien_Luong()
{
	return so_gio_sua*50000;
}

//Ham tao
NhanVienSuaOngNuoc::NhanVienSuaOngNuoc()
{

}

//Ham huy
NhanVienSuaOngNuoc::~NhanVienSuaOngNuoc()
{
	
}
//========================================================================

//==========KHAI BAO NHAN VIEN GIAO HANG==============================
class NhanVienGiaoHang
{
private:
	string hoten;
	int Tuoi;
	string gioi_tinh;
	string dia_chi;
	string sdt;	
	float chieu_cao;
	float can_nang;
	int so_hang_giao;
public:
	void Nhap();
	void Xuat();
	float Tinh_Tien_Luong();
	NhanVienGiaoHang();
	~NhanVienGiaoHang();		
	
};
//Ham nhap thong tin sua ong nuoc
void NhanVienGiaoHang::Nhap()
{
	fflush(stdin);	
	cout<<"\nNhap ho ten: ";
	getline(cin,hoten);
	fflush(stdin);	
	cout<<"\nNhap tuoi: ";
	cin>>Tuoi;
	fflush(stdin);	
	cout<<"\nNhap gioi tinh: ";
	getline(cin,gioi_tinh);	
	cout<<"\nNhap dia chi: ";
	getline(cin,dia_chi);
	fflush(stdin);	
	cout<<"\nNhap SDT: ";
	getline(cin,sdt);
	fflush(stdin);	
	cout<<"\nNhap chieu cao: ";
	cin>>chieu_cao;	
	cout<<"\nNhap can nang: ";
	cin>>can_nang;	
	cout<<"\nNhap so hang giao: ";
	cin>>so_hang_giao;							
}

//Ham xuat thong tin nhan vien giao hang
void NhanVienGiaoHang::Xuat()
{
	cout<<"\nHo ten: "<<hoten;
	cout<<"\nTuoi: "<<Tuoi;
	cout<<"\nGioi tinh: "<<gioi_tinh;	
	cout<<"\nDia chi: "<<dia_chi;
	cout<<"\nSDT: "<<sdt;	
	cout<<"\nChieu cao: "<<chieu_cao;
	cout<<"\nCan nang: "<<can_nang;							
}

//Ham tao
NhanVienGiaoHang::NhanVienGiaoHang()
{
	
}

//Ham huy
NhanVienGiaoHang::~NhanVienGiaoHang()
{
	
}

//tinh tien luong nhanvien giao hang
float NhanVienGiaoHang::Tinh_Tien_Luong()
{
	return so_hang_giao*33500;
}
//======SAP XEP GIAM DAN THEO LUONG NV SUA ONG NUOC====================
void sapxep_suaongnuoc(NhanVienSuaOngNuoc ds_nv_suaongnuoc[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(ds_nv_suaongnuoc[i].Tinh_Tien_Luong()<ds_nv_suaongnuoc[i+1].Tinh_Tien_Luong()){
				NhanVienSuaOngNuoc t;
				t=ds_nv_suaongnuoc[i];
				ds_nv_suaongnuoc[i]=ds_nv_suaongnuoc[i+1];
				ds_nv_suaongnuoc[i+1]=t;
			}
		}
	}
}
//======SAP XEP GIAM DAN THEO LUONG NV GIAO HANG====================
void sapxep_giaohang(NhanVienGiaoHang ds_nv_giaohang[],int m){
	for(int i=0;i<m-1;i++){
		for(int j=i+1;j<m;j++){
			if(ds_nv_giaohang[i].Tinh_Tien_Luong()<ds_nv_giaohang[i+1].Tinh_Tien_Luong()){
				NhanVienGiaoHang t;
				t=ds_nv_giaohang[i];
				ds_nv_giaohang[i]=ds_nv_giaohang[i+1];
				ds_nv_giaohang[i+1]=t;
			}
		}
	}
}
//thiet ke menu
void Menu(NhanVienSuaOngNuoc ds_nv_suaongnuoc[],NhanVienGiaoHang ds_nv_giaohang[],int n, int m)
{
	int luachon;
	while(1)
	{
		cout<<"\n=====CHUONG TRINH QUAN LI===============\n";
		cout<<"\n=====1.Nhap thong tin nv SUA ONG NUOC===\n";
		cout<<"\n=====2.Nhap thong tin nv GIAO HANG======\n";
		cout<<"\n=====3.Xuat thong tin nv SUA ONG NUOC===\n";
		cout<<"\n=====4.Xuat thong tin nv GIAO HANG======\n";
		cout<<"\n=====5.Sap xep NV SUA ONG NUOC giam dan theo luong\n";
		cout<<"\n=====6.Sap xep NV GIAO HANG giam dan theo luong\n";		
		cout<<"\n=====7.THOAT============================\n";				
		cout<<"\n===========END==========================\n";
		cout<<"\n====NHAP LUA CHON========\n";
		cin>>luachon;	
		if(luachon<1 || luachon>7){
			cout<<"\nLUA CHON KHONG HOP LE\n";
		}
		if(luachon==1)
		{
			NhanVienSuaOngNuoc nv_suaongnuoc;
			cout<<"\nNhap thong tin nv SUA ONG NUOC\n";
			nv_suaongnuoc.Nhap();
			ds_nv_suaongnuoc[n] = nv_suaongnuoc;
			n++;
		}
		else if(luachon==2)
		{
			NhanVienGiaoHang nv_giaohang;
			cout<<"\nNhap thong tin nv GIAO HANG\n";
			nv_giaohang.Nhap();
			ds_nv_giaohang[m] = nv_giaohang;
			m++;
		}
		else if(luachon==3)
		{
			cout<<"\nDanh sach nhan vien SUA ONG NUOC\n";
			for(int i=0;i<n;i++){
				cout<<"\nNhan vien SUA ONG NUOC thu "<<i+1<<":\n";
				ds_nv_suaongnuoc[i].Xuat();
				cout<<"\nLuong: "<<ds_nv_suaongnuoc[i].Tinh_Tien_Luong();
			}
		}
		else if(luachon==4)
		{
			cout<<"\nDanh sach nhan vien GIAO HANG\n";
			for(int i=0;i<m;i++){
				cout<<"\nNhan vien GIAO HANG thu "<<i+1<<":\n";
				ds_nv_giaohang[i].Xuat();
				cout<<"\nLuong: "<<ds_nv_giaohang[i].Tinh_Tien_Luong();				
			}
		}
		else if(luachon==5){
			cout<<"\nDanh sach giam dan theo luong NV SUA ONG NUOC\n";
			sapxep_suaongnuoc(ds_nv_suaongnuoc,n);	
			for(int i=0;i<n;i++){
				cout<<"\nNhan vien SUA ONG NUOC thu "<<i+1<<":\n";
				ds_nv_suaongnuoc[i].Xuat();
				cout<<"\nLuong: "<<ds_nv_suaongnuoc[i].Tinh_Tien_Luong();
			}						
		}
		else if(luachon==6){
			cout<<"\nDanh sach giam dan theo luong NV GIAO HANG\n";
			sapxep_giaohang(ds_nv_giaohang,m);	
			for(int i=0;i<m;i++){
				cout<<"\nNhan vien GIAO HANG thu "<<i+1<<":\n";
				ds_nv_giaohang[i].Xuat();
				cout<<"\nLuong: "<<ds_nv_giaohang[i].Tinh_Tien_Luong();
			}						
		}		
		else if(luachon==7){
			break;
		}				
	}	
	
}



int main(){
	NhanVienSuaOngNuoc ds_nv_suaongnuoc[100]; //100 doi tuong,moi 1 doi tuong trong mang la 1 class nhan vien
	NhanVienGiaoHang ds_nv_giaohang[100];
	int m=0;
	int n=0;

	Menu(ds_nv_suaongnuoc,ds_nv_giaohang,n,m);		
	return 0;
}
