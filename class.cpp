#include <iostream>
#include <string>

//lop co so
class Phu_nu
{
	public:
		
		Phu_nu(const std::string &ht,unsigned char t, bool z=true)
			: ho_ten(ht),tuoi(t), con_zin(z)
		{}
		
		~Phu_nu(){
			std::cout<<"chia tay "<<ho_ten<<std::endl;
		}
		
		void trangDiem()	//phuong thuc
		{
	
		}
		virtual void choi_nhac_cu(std::string nhac_cu)
		{
			std::cout<<ho_ten<<" AAAA "<<nhac_cu<<std::endl;
		}
		void va_zin()
		{
			if(tuoi<25){con_zin = true;}
		}
		
		void show_hang()
		{
			std::cout<<ho_ten<<" "<<(con_zin?"con zin":"mat zin")<<std::endl;
		}	
	protected: //duoc truy cap bang class dan xuat
		std::string ho_ten;
		bool con_zin;
		unsigned char tuoi;
};

//lop dan xuat
class gaiNgoan : public Phu_nu //class gaiNgoan ke thua tat ca tinh chat class Phu_nu
{
	public:
		gaiNgoan(const std::string &ht,unsigned char t, bool z=true)
			: Phu_nu(ht,t,z)
		{}
	void noi_tro()
		{
			std::cout<<ho_ten<<" dang di cho"<<std::endl;
		}	
	void choi_nhac_cu(std::string nhac_cu)
		{
			std::cout<<ho_ten<<" OOOOO "<<nhac_cu<<std::endl;
		}	
};
class gaiHu : public Phu_nu
{
	public:
		gaiHu(const std::string &ht,unsigned char t, bool z=true)
			: Phu_nu(ht,t,z)
		{}
	void di_bar()
	{
		std::cout<<ho_ten<<" dang di bar "<<std::endl;
	}	
	void choi_nhac_cu(std::string nhac_cu)
		{
			std::cout<<ho_ten<<" UUUU "<<nhac_cu<<std::endl;
		}		
};
int main(){
	Phu_nu *thao = new gaiNgoan("thao",22,false); 
	thao->choi_nhac_cu("ken");						  
	thao->va_zin();									  
	thao->show_hang();                                
	dynamic_cast<gaiNgoan*>(thao)->noi_tro();
	delete thao;
	
	Phu_nu *linh = new gaiHu("linh",25,false); 
	linh->va_zin(); 
	linh->show_hang();
	linh->choi_nhac_cu("ken");
	dynamic_cast<gaiHu*>(linh)->di_bar();
	delete linh;
	return 0;
}
