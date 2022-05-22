#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
class nhanVien{
	protected:
		string hoTen;
		int namSinh;
	public:
		void Nhap(){
			while(getchar()!='\n');			
			cout<<"\nNhap ho ten: ";
			getline(cin,hoTen);
			cout<<"\nNhap nam sinh: ";	
			cin>>namSinh;		
		}
		void Xuat(){
			cout<<"\nHo ten: "<<hoTen;
			cout<<"\nNam sinh: "<<namSinh;
		}
		virtual void lamViec(){
			cout<<"\nNHAN VIEN dang lam viec...";
		}
};
class nhanVienThoiVu:public nhanVien{
	private:
		float soGioLam;
	public:
		void Nhap(){
			nhanVien::Nhap();
			cout<<"\nNhap so gio lam: ";
			cin>>soGioLam;
		}
		void Xuat(){
			nhanVien::Xuat();
			cout<<"\nSo gio lam: "<<soGioLam;
		}
		float tinhLuong(){
			return 16000*soGioLam;
		}
		void lamViec(){
			cout<<"\nNV THOI VU dang lam viec...";
		}				
};
class nhanVienFullTime:public nhanVien{
	private:
		float soNgayLam;
		int chucVu;
	public:
		void Nhap(){
			nhanVien::Nhap();
			cout<<"\nNhap so ngay lam: ";
			cin>>soNgayLam;
			cout<<"\nNhap chuc vu: ";
			cin>>chucVu;			
		}
		void Xuat(){
			nhanVien::Xuat();
			cout<<"\nSo ngay lam: "<<soNgayLam;
			cout<<"\nChuc vu 1 hoac 0: "<<chucVu;			
		}			
		float tinhLuong(){
			if(chucVu==0){
				return 150000*soNgayLam;
			}
			else if (chucVu==1){
				return 200000*soNgayLam;
			}
		}
		void lamViec(){
			cout<<"\nNV FULL TIME dang lam viec...";
		}			
		int Getter_chucVu()
		{
			return chucVu;
		}
		void Setter_chucVu(int chucvu_update)
		{
			chucVu = chucvu_update;
		}		
};
void Menu(nhanVienThoiVu *nv_thoivu[],int n,nhanVienFullTime *nv_fulltime[], int m)
{
	int luachon;
	while(1)
	{
		system("cls");
		cout<<"=======QUAN LY NHAN VIEN===========";
		cout<<"\n0.Ket thuc====================";		
		cout<<"\n1.Nhap thong tin nhan vien====";
		cout<<"\n2.Xuat thong tin nhan vien====";
		cout<<"\n3.Tong luong nhan vien FULL TIME chuc vu 0";
		cout<<"\nNHAP LUA CHON: ";		
		cin>>luachon;
		if (luachon==0) break;
		else if(luachon==1)
		{
			int chon;
			cout<<"\n0.Ket thuc================";			
			cout<<"\n1.Nhan vien thoi vu=======";
			cout<<"\n2.Nhan vien full time=====";
			cout<<"\nNHAP LUA CHON: ";
			cin>>chon;
			if (chon==0) break;	
			else if(chon==1)
			{
				nhanVienThoiVu *x = new nhanVienThoiVu();
				x->Nhap();
				nv_thoivu[n] = x;
				n++;	
			}
			else if(chon==2)
			{
				nhanVienFullTime *x = new nhanVienFullTime();
				x->Nhap();
				nv_fulltime[m] = x;
				m++;	
			}						
		}
		else if(luachon==2)
		{
			int dem=1;
			cout<<"\n===Danh sach nv THOI VU===";
			for(int i=0;i<n;i++)
			{
				cout<<"\nNhan vien thoi vu thu: "<<dem;
				nv_thoivu[i]->Xuat();
				dem++;
			}
			dem = 1;
			cout<<"\n===Danh sach nv FULL TIME===";
			for(int i=0;i<m;i++)
			{
				cout<<"\nNhan vien full time thu: "<<dem;
				nv_fulltime[i]->Xuat();
				dem++;
			}			
			system("pause");
		}
		else if(luachon==3)
		{
			int tong=0;
			for(int i=0;i<m;i++)
			{
				if(nv_fulltime[i]->Getter_chucVu()==0)
				{
					tong+=nv_fulltime[i]->tinhLuong();
				}
			}
			cout<<"\nTong luong: "<<size_t(tong);
			system("pause");			
		}	
	}
	//giai phong doi tuong con tro nv_thoivu
	for(int i=0;i<n;i++)
	{
		delete nv_thoivu[i];
	}
	//giai phong doi tuong con tro nv_fulltime
	for(int i=0;i<m;i++)
	{
		delete nv_fulltime[i];
	}	
}
int main(){
//	nhanVienThoiVu *nv_thoivu[100];
//	int n=0;
//	nhanVienFullTime *nv_fulltime[100];
//	int m=0;	
//	Menu(nv_thoivu,n,nv_fulltime,m);
	nhanVien *nv_a = new nhanVienThoiVu();
	nhanVien *nv_b = new nhanVienFullTime();
	nv_a->lamViec();
	nv_b->lamViec();
	return 0;
}
