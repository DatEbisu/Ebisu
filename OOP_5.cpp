#include<iostream>
#include<string>
#include<conio.h>
#include<cstdlib>
using namespace std;

//===khai bao lop cha XE====
class Xe {
	protected:
		string hoten;
		float so_h_thue;
	public:
		void Nhap() {
			while(getchar()!='\n'); //xoa bo nho dem truoc khi nhap chuoi
			cout<<"\nNhap ho ten nguoi thue:\n";
			getline(cin,hoten);
			cout<<"\nNhap so gio thue:\n";
			cin>>so_h_thue;
		}
		void Xuat() {
			cout<<"\nHo ten nguoi thue: "<<hoten;
			cout<<"\nSo gio thue: "<<so_h_thue;
		}
};

//======Khai bao lop con XE DAP=======
class XeDap:public Xe {
	private:
	public:
		float Tinh_tien_thue_xe() {
			return size_t(10000 + (so_h_thue-1)*8000);
		}
};

//======Khai bao lop con XE MAY=======
class XeMay:public Xe {
	private:
		int loai_xe;
		string bien_so;
	public:
		void Nhap() {
			Xe::Nhap();
			cout<<"\nNhap loai xe can thue 100cc hoac 250cc:\n";
			cin>>loai_xe;
			while(getchar()!='\n');
			cout<<"\nNhap bien so:\n";
			getline(cin,bien_so);
		}
		void Xuat() {
			Xe::Xuat();
			cout<<"\nLoai xe:"<<loai_xe;
			cout<<"\nBien so:"<<bien_so;
		}
		float Tinh_tien_thue_xe() {
			float tien_xe_gio_dau_tien = 0;
			if(loai_xe==100) 
			{
				tien_xe_gio_dau_tien = 150000;
			} 
			else if(loai_xe==250) 
			{
				tien_xe_gio_dau_tien = 200000;
			}
			return size_t(tien_xe_gio_dau_tien +(so_h_thue-1)*100000);
		}
		//GETTER - Loai xe - truy cap 1 thuoc tinh private
		int Getter_Loaixe()
		{
			return loai_xe;
		}
		void Setter_Loaixe(int LOAIXE)
		{
			loai_xe = LOAIXE;
		}		
};

//======Ham xuat tat ca thong tin====================
void XuatTatCaThongTin(XeDap ds_xedap[],int n,XeMay ds_xemay[],int m) {
	cout<<"\nDanh sach thue XE DAP\n";
	for(int i=0; i<n; i++) {
		ds_xedap[i].Xuat();
		cout<<"\nTien thue: "<<size_t(ds_xedap[i].Tinh_tien_thue_xe());
	}
	cout<<"\nDanh sach thue XE MAY\n";
	for(int i=0; i<m; i++) {
		ds_xemay[i].Xuat();
		cout<<"\nTien thue: "<<size_t(ds_xemay[i].Tinh_tien_thue_xe());
	}
}

//======Tinh tong tien thue xe dap va xe may====================
float Tong_Tien_Thue_Xe(XeDap ds_xedap[],int n,XeMay ds_xemay[],int m) {
	float tong=0;
	for(int i=0; i<n; i++) {
		tong+=ds_xedap[i].Tinh_tien_thue_xe();
	}

	for(int i=0; i<m; i++) {
		tong+=ds_xemay[i].Tinh_tien_thue_xe();
	}
	return tong;
}
//======Ham quan li cac loai xe==========
void Menu(XeDap ds_xedap[],int n,XeMay ds_xemay[],int m) {
	int luachon;
	while(1) {
		system("cls");
		cout<<"\n====================QUAN LI XE==================\n";
		cout<<"\n=====1.Nhap danh sach thue xe dap va xe may=====\n";
		cout<<"\n=====2.Xuat tat ca thong tin thue xe============\n";
		cout<<"\n=====3.Tinh tong so tien cho thue xe dap va xe may\n";
		cout<<"\n=====4.Xuat tat ca thong tin lien quan den viec cho thue xe dap\n";
		cout<<"\n=====5.Tinh tong so tien cho thue xe may loai 250cc\n";
		cout<<"\n=====0.Ket thuc====================================\n";
		cout<<"\n==========================END========================\n";
		cout<<"\nNhap lua chon: ";
		cin>>luachon;
		if(luachon==1) {
			int chon;
			while(1) {
				system("cls");
				cout<<"\n1.thue XE DAP\n";
				cout<<"\n2.thue XE MAY\n";
				cout<<"\n0.ket thuc\n";
				cout<<"\nNhap lua chon xe: ";
				cin>>chon;
				if(chon==1) {

					cout<<"\nNhap thong tin thue XE DAP\n";
					XeDap x;
					x.Nhap();
					ds_xedap[n] = x;
					n++;
				} else if(chon==2) {
					cout<<"\nNhap thong tin thue XE MAY\n";
					XeMay x;
					x.Nhap();
					ds_xemay[m] = x;
					m++;
				} else if(chon==0) break;
			}
		} else if(luachon==2) {
			XuatTatCaThongTin(ds_xedap,n,ds_xemay,m);
			system("pause");
		} 
		else if(luachon==3) {
			float tongtien = Tong_Tien_Thue_Xe(ds_xedap,n,ds_xemay,m);
			cout<<"\nTong tien thue xe la:"<<size_t(tongtien)<<"\n";
			system("pause");
		} 
		else if(luachon==4){
			cout<<"\nThong tin cua thue XE DAP\n";
			cout<<"\nDanh sach thue XE DAP\n";
				for(int i=0; i<n; i++) {
					ds_xedap[i].Xuat();
					cout<<"\nTien thue: "<<size_t(ds_xedap[i].Tinh_tien_thue_xe());
				}	
			system("pause");
		}
		else if(luachon==5){
			float tong=0;
				for(int i=0;i<m;i++){
					if(ds_xemay[i].Getter_Loaixe()==250){
						tong+=ds_xemay[i].Tinh_tien_thue_xe();
					}
				}
			cout<<"\nTong tien thue cua loai XE 250CC: "<<tong;	
			system("pause");										
		}				
		
		else if(luachon==0) break;
	}
}


int main() {
	XeDap ds_xedap[100];
	int n=0;
	XeMay ds_xemay[100];
	int m=0;
	Menu(ds_xedap,n,ds_xemay,m);

	return 0;
}
