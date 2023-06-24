#include <iostream>
#include <graphics.h>
#include <sstream>
#include <fstream>
#include <conio.h>
#include <string>
#include <math.h>
using namespace std;
#define MAX 20
#define BK 25
#define MAXX 32000
struct dinh
{
	int x;
	int y;
	char* name;
};

dinh dothi[MAX];
int n;
int truoc[MAX];
int G[MAX][MAX];
int G1[MAX][MAX];
bool chuaxet[MAX];
bool xetcanh[MAX][MAX];
int canh[MAX][MAX];
string name="";
//Hamilton
int i=0;
int d=0;
int G2[MAX][MAX];
int B[MAX*MAX];
int C[MAX*MAX];
// Prototype
void Button1(dinh a);
void DoiMauButton(dinh a);
void Menu(dinh  menu[10]);
void MenuFile(dinh file[3]);
void MTTS();
void note();
void MenuDinh(dinh file[6]);
void HuongDan();
void DoThi();
bool ClickChuot(dinh s);
void SetGiaoDien(dinh a[][10]);
void DkChuot(dinh s, int &x, int &y, bool &dem, int stt);
void GetChuot(dinh s[][10], int &a, int &b);
void Xuli(int stt);
float KhoangCach(int x1, int y1, int x2, int y2);
bool IsDinh(int x,int y);
string xoaKiTu(string a);
char* TenDinh();
void TaoDinh();
void VeDinh();
void VeDinh1(dinh a);
char* StringToChar(string c);
void clearmouse();
bool IsDinh1(int x, int y, dinh a);
void VeMuiTen(dinh dau, dinh cuoi, int color);
void TaoCanh();
int NhapTrongSo();
int StringToInt(string a);
string IntToString(int a);
void VeTrongSo(int dau, int cuoi);
void ResetCanh();
void ResetDinh();
void ResetDoThi();
void DinhCopy(dinh &a, dinh &b);
void XoaDinh();
void MoveDinh();
void DoiTenDinh();
void Info();
void ClearDoThi();
void DocFile();
void OpenFile();
void DoiMauDinh(int vt, int mau);
void DFS();
void BFS();
void Draw(int a[],int n1, int color, int speed);
void InitG();
void Init();
void Init1();
void Init2();
void dfs(int vt,int a[], int &sl);
void bfs (int vt, int a[], int &sl);
void XtoY();
int LienThong();
void DinhTru();
void CanhCau();
void Euler();
void EulerCycle(int vt,int kq[], int &sl);
void DinhThat();
void TPLT();
void Hamilton();
void HamiltonCycle(int *B, int *C, int i);
void Result();
void TopoShort();
void InitCanh();
void ReInitCanh();
void VeCanh(int dau, int cuoi, int color);
void dfs1(int v);
void Result1(int dau, int cuoi);
bool IsVoHuong();

int main()
{
}

void Button1(dinh a)
	{
		int c = getcolor();
		setcolor(3);
		setfillstyle(1, 9);
		bar(a.x, a.y, a.x + 100, a.y + 40);
		rectangle(a.x, a.y, a.x + 100, a.y + 40);
		setcolor(15);
		outtextxy(a.x + 17, a.y + 8, a.name);
		setcolor(c);
		setfillstyle(1, c);
	}

void DoiMauButton(dinh a)
	{
		int c = getcolor();
		setcolor(3);
		setfillstyle(1, 11);
		bar(a.x, a.y, a.x + 100, a.y + 40);
		rectangle(a.x, a.y, a.x + 100, a.y + 40);
		setcolor(15);
		outtextxy(a.x + 17, a.y + 8, a.name);
		setcolor(c);
		setfillstyle(1, c);
	}
	// Menu //
	void Menu(dinh  menu[10])
	{
		const int weight = 110;
		const int height = 50;
		int count = 0;
		setfillstyle(1, 3);
		bar(20, 30, 350, 235);
		for (int i = 0; i < 10;)
		{
			for (int j = 0; j < 3 && i<10; j++)
			{
				menu[i].x = weight*j + 25;
				menu[i].y = height*count + 40;
				menu[i].name = new char[10];
				i++;
			}
			count++;
		}
		menu[0].name = "DFS";
		menu[1].name = "BFS";
		menu[2].name = "X->Y";
		menu[3].name = "DINH TRU";
		menu[4].name = "DINH THAT";
		menu[5].name = "CANH CAU";
		menu[6].name = "HAMILTON";
		menu[7].name = "EULER";
		menu[8].name = "TOPO SORT";
		menu[9].name = "TPLT";
		for (int i = 0; i < 10; i++)
		{
			Button1(menu[i]);
		}
		rectangle(20, 30, 350, 235);

	}

	void MenuFile(dinh file[3])
	{
		const int weight = 110;
		const int height = 50;
		setfillstyle(1, 3);
		bar(20, 245, 350, 295);
		for (int i = 0; i < 3; i++)
		{

			file[i].x = weight*i + 25;
			file[i].y = height + 200;
			file[i].name = new char[10];


		}
		file[0].name = "OPEN";
		file[1].name = "SAVE";
		file[2].name = "CLEAR";

		for (int i = 0; i < 3; i++)
		{
			Button1(file[i]);
		}
		rectangle(20, 245, 350, 295);

	}

	void MTTS()
	{
		
		int D=30;
		const int dai = 330;
		setfillstyle(1, 3);
		bar(20, 355, 20 + dai, 355 + dai);
		/*line(20, 355, 20 + dai, 355 + dai);
		line(20,355+ dai, 20+dai,355);
		outtextxy(130,515,"COMING SOON...");*/
		rectangle(20, 355, 20 + dai, 355 + dai);
		int xx=22;
		int yy=365;
		string temp;
		if (n<=10 && n!=0)
		{
			for (int i=0;i<=n;i++)
			{
				for (int j=0;j<n;j++)
				{	
					setfillstyle(1, 15);
					line(xx+j*D+28,25+dai,xx+j*D+28,25+dai+(n+1)*D);
					if (i==0)
					{
						outtextxy(xx+(j+1)*D,yy,dothi[j].name);
					}
					else
					{
						temp=IntToString(G[i-1][j]);
						outtextxy(xx,yy+i*D,dothi[i-1].name);
						outtextxy(xx+(j+1)*D,yy+i*D,&temp[0]);
					}
				}
				line(xx+n*D+28,25+dai,xx+n*D+28,25+dai+(n+1)*D);
				line(20,355+30+i*30,20+(n+1)*30,355+30+i*30);
			}
			setfillstyle(1, 3);
		}
		else 
		{
		line(20, 355, 20 + dai, 355 + dai);
		line(20,355+ dai, 20+dai,355);
		outtextxy(xx,355+160,"Khong the hien thi vi vai ly do ky thuat");
		}
		
	}

	void note()
	{
		const int dai = 330;
		setfillstyle(1, 3);
		bar(20, 300, 350, 350);
		rectangle(20, 300, 350, 350);
		outtextxy(170, 310, "MATRIX");
		if (n!=0)
		{
			setcolor(12);
		if (IsVoHuong()==true)
			outtextxy(130,325,"DO THI VO HUONG");
		else outtextxy(130,325,"DO THI CO HUONG");
		setcolor(15);
		}
	}

	void MenuDinh(dinh file[6])
	{
		const int weight = 110; //kc giua cac button (chieu x)
		const int height = 80; //kc giua cac button (chieu y)
		setfillstyle(1, 3);
		bar(355, 30, 355 + weight, 00 + height * 6);
		for (int i = 0; i < 6; i++)
		{

			file[i].x = 360;
			file[i].y = height*i + 35;
			file[i].name = new char[10];


		}
		file[0].name = "TAO DINH";
		file[1].name = "TAO CANH";
		file[2].name = "XOA DINH";
		file[3].name = "MOVE DINH";
		file[4].name = "RENAME";
		file[5].name = "INFO?";
		for (int i = 0; i < 6; i++)
		{
			Button1(file[i]);
		}
		rectangle(355, 30, 355 + weight, 00 + height * 6);

	}

	void HuongDan()
	{
		setfillstyle(1, 3);
		bar(355, 480, 1250, 685);
		rectangle(355, 480, 1250, 685);
		setfillstyle(1, 10);
		bar(355, 480, 465, 515);
		rectangle(355, 480, 465, 515);
		setcolor(15);
		outtextxy(360, 490, " INSTRUCTION:");
		outtextxy(480,490,"File: ");
		outtextxy(530,490,&name[0]);
	}
	void DoThi()
	{
		setfillstyle(1, 8);
		bar(465, 30, 1250, 685);
		rectangle(465, 30, 1250, 685);
		HuongDan();
	}
	bool ClickChuot(dinh s)
	{
		int x, y;

		getmouseclick(WM_LBUTTONDOWN,x,y);
		if (x != -1 && y != -1 && (x >= s.x && x <= s.x + 100) && (y >= s.y && y <= s.y + 40))
		{
			return true;
		}
		return false;
	}
	void SetGiaoDien(dinh a[][10])
	{
		setfillstyle(1, 7);
		bar(1, 1, 1279, 719);
		Menu(a[0]);
		MenuFile(a[1]);
		MTTS();
		note();
		DoThi();
		MenuDinh(a[2]);
		HuongDan();
	}
	void DkChuot(dinh s, int &x, int &y, bool &dem, int stt)
	{
		if ((x != -1 && y != -1) && (x >= s.x && x <= s.x + 100) && (y >= s.y && y <= s.y + 40))
		{
			DoiMauButton(s);
			if (ClickChuot(s))
			{
				Xuli(stt);
			}
			dem = true;
			delay(.001);
		}
		else if ((x != -1 && y != -1) && (dem == true) && (!(x >= s.x && x <= s.x + 100) || !(y >= s.y && y <= s.y + 40)))
		{
			Button1(s);
		}
	}
	void GetChuot(dinh s[][10], int &a, int &b)
	{

		int x, y;
		char c;
		int cout = 0;
		bool dem = false;
		while (.001)
		{
			delay(1);
			getmouseclick(WM_MOUSEMOVE, x, y);
			DkChuot(s[0][0], x, y, dem, 1);


			DkChuot(s[0][1], x, y, dem, 2);


			DkChuot(s[0][2], x, y, dem, 3);


			DkChuot(s[0][3], x, y, dem, 4);


			DkChuot(s[0][4], x, y, dem, 5);


			DkChuot(s[0][5], x, y, dem, 6);


			DkChuot(s[0][6], x, y, dem, 7);


			DkChuot(s[0][7], x, y, dem, 8);


			DkChuot(s[0][8], x, y, dem, 9);


			DkChuot(s[0][9], x, y, dem, 10);



			DkChuot(s[1][0], x, y, dem, 11);


			DkChuot(s[1][1], x, y, dem, 12);


			DkChuot(s[1][2], x, y, dem, 13);



			DkChuot(s[2][0], x, y, dem, 14);


			DkChuot(s[2][1], x, y, dem, 15);


			DkChuot(s[2][2], x, y, dem, 16);


			DkChuot(s[2][3], x, y, dem, 17);


			DkChuot(s[2][4], x, y, dem, 18);


			DkChuot(s[2][5], x, y, dem, 19);

			//Khi button DFS duoc nhap

			if (kbhit())
			{
				c = getch();
				if (c == 27)
				{
					break;
				}
			}
		}
	}
	
		
	void Init()
	{
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				if (G[i][j]!=0)
					G1[i][j]=G[i][j];
				else G1[i][j]=MAXX;
			}
			chuaxet[i]=true;
			C[i]=0;
		}
	}
	
	void Init1()
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (G[i-1][j-1]!=0)
					G2[i][j]=1;
				else G2[i][j]=0;
			}
			C[i]=0;
		}
	}
	
	void Init2()
	{
		for (int i=0;i<n;i++)
		{
				chuaxet[i]=true;
				truoc[i]=999;
		}
	}


	void DFS()
	{
	
		// Chon dinh
		Init();
		HuongDan();
		outtextxy(370, 520, "Nhap vao dinh xuat phat: ");
		int x,y,vt;
		while(true)
		{
			delay(.001);
			if (ismouseclick(WM_LBUTTONDOWN))
			{
				getmouseclick(WM_LBUTTONDOWN,x,y);
			}
			if (IsDinh(x,y))
			{
				break;
			}
		}
		
		for (int i=0;i<n;i++)
		{
			if (IsDinh1(x,y,dothi[i]))
			{
				vt=i;
				DoiMauDinh(i,2);
				break;
			}
		}
		
		//DFS
		int kq[MAX];
		int sl=0;
		int xx=370;
		dfs(vt,kq,sl);
		HuongDan();
		
		int t;
		for (int i=0;i<sl;i++)
		{
			t=kq[i];
			if (i!=sl-1)
			{
				outtextxy(xx,520,dothi[t].name);
				xx=xx+20;
				outtextxy(xx,520,"=>");
				xx=xx+20;
			}
			else outtextxy(xx,520,dothi[t].name);
		}
		Draw(kq,sl,2,500);	
		
		
		
		setcolor(15);
		
		
		outtextxy(370, 540, "Press any key to exit...");
		getch();
		HuongDan();
		ResetDoThi();
		return;
	}

	void dfs(int vt,int a[], int &sl)
	{
		int stack[MAX];
		int sp=1;
		int temp;
		stack[sp]=vt;
	
		a[sl]=vt;
		sl++;
		chuaxet[vt]=false;
		while (sp>0)
		{
			temp=stack[sp];
			sp--;
			for (int i=0;i<n;i++)
			{
				if ((G1[temp][i]!=MAXX) && (chuaxet[i]==true))
				{
					
					a[sl]=i;
					sl++;
					stack[++sp]=temp;
					stack[++sp]=i;
					chuaxet[i]=false;
					break;
				}
			}
		}	
	}
	
	void BFS()
	{
		
	
		// Chon dinh
		HuongDan();
		outtextxy(370, 520, "Nhap vao dinh xuat phat: ");
		int x,y,u;
		while(true)
		{
			delay(.001);
			if (ismouseclick(WM_LBUTTONDOWN))
			{
				getmouseclick(WM_LBUTTONDOWN,x,y);
			}
			if (IsDinh(x,y))
			{
				break;
			}
		}
		
		for (int i=0;i<n;i++)
		{
			if (IsDinh1(x,y,dothi[i]))
			{
				u=i;
				DoiMauDinh(i,2);
				break;
			}
		}
		
		//BFS
		int kq[MAX];
		int sl=0;
		bfs(u,kq,sl);
		int xx=370;	
		int t;
		HuongDan();
		
		for (int i=0;i<sl;i++)
		{
			t=kq[i];
			if (i!=sl-1)
			{
				outtextxy(xx,520,dothi[t].name);
				xx=xx+20;
				outtextxy(xx,520,"=>");
				xx=xx+20;
			}
			else outtextxy(xx,520,dothi[t].name);
		}
		Draw(kq,sl,2,500);
  	
		
		setcolor(15);
		outtextxy(370, 540, "Press any key to exit...");
		getch();
		HuongDan();
		ResetDoThi();

	}
	
	void bfs (int vt, int a[], int &sl)
	{
		Init();
		int queue[MAX*MAX];
		int high =1;
		int low =1;
		int t;
		queue[low]=vt;
		chuaxet[vt]=false;
		while (low<=high)
		{
			
			t=queue[low];
			low ++;
			a[sl]=t;
			sl++;
			for (int i=0;i<n;i++)
			{
				if (G1[t][i]!=MAXX && chuaxet[i]==true)
				{	
					high++;
					queue[high]=i;
				
					chuaxet[i]=false;
				}
			}
		}
	}
	
	
	void InitG()
	{
		for (int i=0;i<MAX;i++)
		{
			for(int j=0;j<MAX;j++)
			{
				G[i][j]=0;
			}
			
		}
	}
	
	void XtoY()
	{
		
			int x,y;
		int dau,cuoi;
		HuongDan();
		outtextxy(370,520,"Nhap vao dinh bat dau: ");
		while (1)
		{
			delay(.001);
			if (ismouseclick(WM_LBUTTONDOWN))
				getmouseclick(WM_LBUTTONDOWN,x,y);
			if (IsDinh(x,y))
				break;
		}
		for (int i=0;i<n;i++)
		{
			if (IsDinh1(x,y,dothi[i]))
			{
				dau=i;
				DoiMauDinh(i,2);
				break;
			}
		}
		
		HuongDan();
		outtextxy(370,520,"Nhap vao dinh ket thuc: ");
		while (1)
		{
			delay(.001);
			if (ismouseclick(WM_LBUTTONDOWN))
				getmouseclick(WM_LBUTTONDOWN,x,y);
			if (IsDinh(x,y) && !IsDinh1(x,y,dothi[dau]))
				break;
		}
		for (int i=0;i<n;i++)
		{
			if (IsDinh1(x,y,dothi[i]))
			{
				cuoi=i;
				DoiMauDinh(i,2);
				break;
			}
		}
		
		Init();
		int truoc[MAX];
		int d[MAX];
		for (int i=0;i<n;i++)
		{
			truoc[i]=dau;
			d[i]=G1[dau][i];
		}
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				if ((G1[i][j]!=MAXX) && (d[j]>d[i]+G1[i][j]))
				{
					d[j]=d[i]+G1[i][j];
					truoc[j]=i;
				}
			}
		}
		if (d[cuoi]==MAXX)
		{
			outtextxy(370,540,"KHONG CO DUONG DI");
		}
		else
		{
		int kq[MAX];
		int sl=0;
		int temp;
		kq[sl]=cuoi;
		sl++;
		temp=truoc[cuoi];
		while (temp!=dau)
		{
			kq[sl]=temp;
			sl++;
			temp=truoc[temp];
		}
		kq[sl]=dau;
		
		sl++;
		
		HuongDan();
			int xx=370;
		for (int i=sl-1;i>=0;i--)
		{
			if (i!=0)
			{
				outtextxy(xx,520,dothi[kq[i]].name);
				xx=xx+20;
				outtextxy(xx,520,"=>");
				xx=xx+20;
			}
			else outtextxy(xx,520,dothi[kq[i]].name);
		}
		int kq1[sl];
		for (int i=0;i<sl;i++)
		{
			kq1[i]=kq[sl-1-i];
		};
		string s;
		s=IntToString(d[cuoi]);
		outtextxy(370,540,"Do dai duong di: ");
		outtextxy(500,540,&s[0]);
		Draw(kq1,sl,14,500);
		}
		outtextxy(370,560,"Press any key...");
		
		
		getch();
		HuongDan();
		ResetDoThi();
	}


	void ResetDoThi()
{
	DoThi();
	HuongDan();
	VeDinh();
	ResetCanh();
	
}
	void ResetDinh()
	{
	DoThi();
	HuongDan();
	VeDinh();
	}
	
		void DinhThat()
	{
		int x,y;
		int dau,cuoi;
		HuongDan();
		outtextxy(370,520,"Nhap vao dinh bat dau: ");
		while (1)
		{
			delay(.001);
			if (ismouseclick(WM_LBUTTONDOWN))
				getmouseclick(WM_LBUTTONDOWN,x,y);
			if (IsDinh(x,y))
				break;
		}
		for (int i=0;i<n;i++)
		{
			if (IsDinh1(x,y,dothi[i]))
			{
				dau=i;
				DoiMauDinh(i,1);
				break;
			}
		}
		
		HuongDan();
		outtextxy(370,520,"Nhap vao dinh ket thuc: ");
		while (1)
		{
			delay(.001);
			if (ismouseclick(WM_LBUTTONDOWN))
				getmouseclick(WM_LBUTTONDOWN,x,y);
			if (IsDinh(x,y) && !IsDinh1(x,y,dothi[dau]))
				break;
		}
		for (int i=0;i<n;i++)
		{
			if (IsDinh1(x,y,dothi[i]))
			{
				cuoi=i;
				DoiMauDinh(i,1);
				break;
			}
		}
		HuongDan();
		Init();
		
		for (int i=0;i<n;i++)
			truoc[i]=999;
		for (int i=0;i<n;i++)
		{
			HuongDan();
			dfs1(dau);
			Result1(dau,cuoi);
			Init2();
		}
		
		
		getch();
		ResetDoThi();
	}
		void dfs1(int v)
	{
		chuaxet[v]=false;
		for (int i=0;i<n;i++)
		{
			if (G1[v][i]!=MAXX)
			{
				if (chuaxet[i]==true)
				{
					truoc[i]=v;
					G1[v][i]==MAXX;
					dfs1(i);
				}
			}
		}
	}
	
		void clearmouse()
	{
	clearmouseclick(WM_LBUTTONDOWN);
	clearmouseclick(WM_RBUTTONDOWN);
	clearmouseclick(WM_LBUTTONDBLCLK);
	}
float KhoangCach(int x1, int y1, int x2, int y2)
	{
		float kc;
		kc = sqrt((float)(x1 - x2)*(x1 - x2) + (float)(y1 - y2)*(y1 - y2));
		return kc;
	}
	
	bool IsDinh(int x,int y)
	{
		for(int i=0;i<n;i++)
		{
			if (KhoangCach(x,y,dothi[i].x,dothi[i].y)<=BK)
			{
				return true;
			}
		}
		return false;
	}
	
	string xoaKiTu(string a)
	{
		string s = "";
		for (int i = 0; i < a.length() - 1; i++)
			s += a[i];
		return s;
	}
	
	char* StringToChar(string c)
	{
		char *temp = new char[4];
		int i = 0;
		for (; i < c.length(); i++)
		{
			temp[i] = c[i];
		}
		temp[i] = '\0';
		return temp;
	}
	char* TenDinh()
	{
		HuongDan();
		char c;
		char* kq = new char[3];
		string s;
		outtextxy(370, 520, "Nhap toi da 3 chu, nhan ENTER de ket thuc");
		outtextxy(370, 540, "Ten dinh: ");
		outtextxy(495, 540, &s[0]);
		int i = 0;
		do{
			fflush(stdin);
			while (!kbhit());
			c = getch();
			if (c != 13 && c != 8 && i < 3 && ((c>=65 && c<=90) ||(c>=97 && c<=122) ))
			{
				i++;
				s += c;
			}
			else if (c == 8 && i > 0){
				i--;
				s = xoaKiTu(s);
			}
			kq = StringToChar(s);
			HuongDan();
			outtextxy(370, 520, "Nhap toi da 3 chu, nhan ENTER de ket thuc");
			outtextxy(370, 540, "Ten dinh: ");
			outtextxy(495, 540, &s[0]);
			if (n-1 >2 )
			{
				for (int j = 0; j < n-1; j++)
				{
					if (strcmp(kq, dothi[j].name) == 0)
					{
						do
						{
							fflush(stdin);
						} 
						while (!kbhit());
						c = getch();
						if (c != 13 && c != 8 && i < 3 && c >= 65 && c <= 90)
						{
							i++;
							s += c;
						}
						else if (c == 8 && i > 0){
							i--;
							s = xoaKiTu(s);
						}
						kq = StringToChar(s);

					}
				}
			}
			HuongDan();
			outtextxy(370, 520, "Nhap toi da 3 chu, nhan ENTER de ket thuc");
			outtextxy(370, 540, "Nhap ten dinh: ");
			outtextxy(495, 540, &s[0]);
		} while (c != 13 || i == 0);
		return kq;
	}
	
	void TaoDinh()
	{	
		clearmouse();
		int x, y;
		char* c = new char[3];
		HuongDan();
		outtextxy(370, 520, "Click vao noi can tao dinh");
		while (n<=MAX-1)
		{
			delay(.001);
			if (ismouseclick(WM_LBUTTONDOWN))
			{
				getmouseclick(WM_LBUTTONDOWN, x, y);
				if (x >= (465+BK) && x <= (1250-BK) && y >= (30+BK) && y <= (480-BK) && x!=-1 && y!=-1 && !IsDinh(x,y))
				{
					dothi[n].x = x;
					dothi[n].y = y;
					setfillstyle(1, 5);
					setcolor(5);
					pieslice(dothi[n].x, dothi[n].y, 0, 0, BK);
					n++;
					break;
				}
			}

		};
		dothi[n - 1].name = new char[3];
		c = TenDinh();
		c = strupr(c);
		if (n > 1)
		{
			ad:
			for (int i = 0; i < n; i++)
			{
				while (strcmp(c, dothi[i].name) == 0)
				{
					c = TenDinh();
					c = strupr(c);
					goto ad;
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			dothi[n - 1].name[i] = c[i];
		}
		setcolor(15);
		outtextxy(dothi[n - 1].x - 9, dothi[n - 1].y - 9, dothi[n - 1].name);
		ResetDoThi();
	}

	void VeDinh()
	{
		for (int i=0;i<n;i++)
		{
		setfillstyle(1, 5);
		setcolor(5);
		pieslice(dothi[i].x, dothi[i].y, 0, 0, BK);	
		setcolor(15);
		outtextxy(dothi[i].x - 9, dothi[i].y - 9, dothi[i].name);
		}
		MTTS();
		note();
	}
	
	void VeDinh1(dinh a)
	{
	setfillstyle(1, 5);
	setcolor(5);
	pieslice(a.x, a.y, 0, 0, BK);
	setcolor(15);	
	outtextxy(a.x - 9, a.y - 9, a.name);	
	}

	bool IsDinh1(int x, int y, dinh a)
	{
		
			if (KhoangCach(x,y,a.x,a.y) <= BK)
			{
				return true;
			}
		return false;
	}
	
	void VeMuiTen(dinh dau, dinh cuoi, int color)
	{
	const int R = 12;
	const double PI = 3.14159265;
	dinh d1, d2, d3, d;
	setcolor(color);
	line(dau.x, dau.y, cuoi.x, cuoi.y);
	d.x = (dau.x + cuoi.x) / 2;
	d.y = (dau.y + cuoi.y) / 2;
	setcolor(BLACK);
	double result;
	double param = 0;
	struct arccoordstype h;
	if (cuoi.x > dau.x && cuoi.y < dau.y){
		param = 1.0*(dau.y - cuoi.y) / (cuoi.x - dau.x);
		result = atan(param) * 180 / PI;
		arc(d.x, d.y, 0, result + 90, R);
		getarccoords(&h);
		d1.x = h.xend;
		d1.y = h.yend;
		arc(d.x, d.y, result + 90, result + 90 + 180, R);
		getarccoords(&h);
		d2.x = h.xend;
		d2.y = h.yend;
		arc(d.x, d.y, 0, result, R);
		getarccoords(&h);
		d3.x = h.xend;
		d3.y = h.yend;
	}
	else if (cuoi.x < dau.x && cuoi.y > dau.y){
		param = 1.0*(cuoi.y - dau.y) / (dau.x - cuoi.x);
		result = atan(param) * 180 / PI;
		arc(d.x, d.y, 0, result + 90, R);
		getarccoords(&h);
		d1.x = h.xend;
		d1.y = h.yend;
		arc(d.x, d.y, result + 90, result + 90 + 180, R);
		getarccoords(&h);
		d2.x = h.xend;
		d2.y = h.yend;
		arc(d.x, d.y, result, 180 + result, R);
		getarccoords(&h);
		d3.x = h.xend;
		d3.y = h.yend;
	}
	else if (cuoi.x < dau.x && cuoi.y < dau.y){
		param = 1.0*(cuoi.y - dau.y) / (cuoi.x - dau.x);
		result = atan(param) * 180 / PI;
		arc(d.x, d.y, 0, 90 - result, R);
		getarccoords(&h);
		d1.x = h.xend;
		d1.y = h.yend;
		arc(d.x, d.y, 90 - result, 90 - result + 180, R);
		getarccoords(&h);
		d2.x = h.xend;
		d2.y = h.yend;
		arc(d.x, d.y, 0, 180 - result, R);
		getarccoords(&h);
		d3.x = h.xend;
		d3.y = h.yend;
	}
	else if (cuoi.x > dau.x && cuoi.y > dau.y){
		param = 1.0*(cuoi.y - dau.y) / (cuoi.x - dau.x);
		result = atan(param) * 180 / PI;
		arc(d.x, d.y, 0, 90 - result, R);
		getarccoords(&h);
		d1.x = h.xend;
		d1.y = h.yend;
		arc(d.x, d.y, 90 - result, 90 - result + 180, R);
		getarccoords(&h);
		d2.x = h.xend;
		d2.y = h.yend;
		arc(d.x, d.y, -result, 0, R);
		getarccoords(&h);
		d3.x = h.xstart;
		d3.y = h.ystart;
	}
	else if (dau.y == cuoi.y){
		arc(d.x, d.y, 0, 90, R);
		getarccoords(&h);
		d1.x = h.xend;
		d1.y = h.yend;
		arc(d.x, d.y, 90, 90 + 180, R);
		getarccoords(&h);
		d2.x = h.xend;
		d2.y = h.yend;
		if (dau.x < cuoi.x){
			arc(d.x, d.y, 0, 0, R);
			getarccoords(&h);
			d3.x = h.xstart;
			d3.y = h.ystart;
		}
		else{
			arc(d.x, d.y, 0, 180, R);
			getarccoords(&h);
			d3.x = h.xend;
			d3.y = h.yend;
		}
	}
	else{
		arc(d.x, d.y, 0, 180, R);
		getarccoords(&h);
		d1.x = h.xend;
		d1.y = h.yend;
		d2.x = h.xstart;
		d2.y = h.ystart;
		if (cuoi.y > dau.y){
			arc(d.x, d.y, 0, 270, R);
			getarccoords(&h);
			d3.x = h.xend;
			d3.y = h.yend;
		}
		else{
			arc(d.x, d.y, 0, 90, R);
			getarccoords(&h);
			d3.x = h.xend;
			d3.y = h.yend;
		}
	}
	setcolor(color);
	setfillstyle(SOLID_FILL, color);
	int a[] = { d3.x, d3.y, d1.x, d1.y, d2.x, d2.y, d3.x, d3.y };
	fillpoly(4, a);
	setcolor(1);
}

	int StringToInt(string a)
{
	int tong = 0;
	for (int i = 0; i < a.length(); i++)
	{
		tong *= 10;
		tong += (a[i] - '0');
	}
	return tong;
}

	string IntToString(int a)
{
	/*string kq;
	int chia = 100;
	while (chia != 0)
	{
		kq += a / chia + '0';
		a %= chia;
		chia /= 10;
	}*/
	std::stringstream ss;
	ss<<a;
	std::string kq = ss.str();
	return kq;
}

	int NhapTrongSo()
{
	
	HuongDan();
	int kq;
	char c;
	string s;
	outtextxy(370, 520, "Nhap toi da 3 chu so, nhan ENTER de ket thuc");
	outtextxy(370, 540,"Nhap trong so: ");
	outtextxy(370, 560, "Trong so thuoc 001 den 999");
	outtextxy(370, 580, "Nhap trong so bang 0 neu muon xoa canh");
	outtextxy(495, 540, &s[0]);
	int i = 0;
	do{
		fflush(stdin);
		while (!kbhit());
		c = getch();
		if (c != 13 && c != 8 && i < 3 && toupper(c) >= '0' && toupper(c) <= '9'){
			i++;
			s += c;
		}
		else if (c == 8 && i > 0){
			i--;
			s = xoaKiTu(s);
		}
		HuongDan();
		outtextxy(370, 520, "Nhap toi da 3 chu so, nhan ENTER de ket thuc");
		outtextxy(370, 540, "Nhap trong so: ");
		outtextxy(370, 560, "Trong so thuoc 001 den 999");
		outtextxy(370, 580, "Nhap trong so bang 0 neu muon xoa canh");
		outtextxy(495, 540, &s[0]);
	} while (c != 13 || i == 0);
	kq = StringToInt(s);
	return kq;
}

	void VeTrongSo(int dau, int cuoi)
{
	char *temp = new char[3];
	int x,y;
	x = ((dothi[dau].x + dothi[cuoi].x) / 2);
	y = ((dothi[dau].y + dothi[cuoi].y) / 2);
	string c = IntToString(G[dau][cuoi]);
	int i = 0;
	for (; i < c.length(); i++)
	{
		temp[i] = c[i];
	}
	temp[i] = '\0';
	outtextxy(x + 10, y - 10, temp);
}

	void TaoCanh()
	{
		clearmouse();
		HuongDan();
		int trongso;
		if (n <= 1)
		{
			outtextxy(370, 520, "Ban khong the tao canh do so luong dinh chua du");
			
			return;
		}
		HuongDan();
		outtextxy(370, 520, "Click vao dinh dau");
		int x, y;
		int temp1, temp2;
		while (true)
	{
		delay(.001);
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
			break;
		}
	}



	while (!IsDinh(x, y) && x != -1 && y != -1)
	{
		while (true)
		{
			delay(.001);
			if (ismouseclick(WM_LBUTTONDOWN))
			{
				getmouseclick(WM_LBUTTONDOWN, x, y);
				break;
			}
		}
	
	}
	for (int i=0;i<n;i++)
				{
					if(IsDinh1(x,y,dothi[i]))
					{
						DoiMauDinh(i,2);
						temp1=i;
						break;
					}
				}
		clearmouse();
		HuongDan();
		outtextxy(370, 520, "Click vao dinh cuoi");
		while (true)
	{
		delay(.001);
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
			break;
		}
	}

	while (!IsDinh(x, y) || IsDinh1(x, y, dothi[temp1]))
	{
		while (true)
		{
			delay(.001);
			if (ismouseclick(WM_LBUTTONDOWN))
			{
				getmouseclick(WM_LBUTTONDOWN, x, y);
				break;
			}
		}

	}
	for (int i=0;i<n;i++)
				{
					if(IsDinh1(x,y,dothi[i]) && !IsDinh1(x,y,dothi[temp1]))
					{
						DoiMauDinh(i,2);
						temp2=i;
						break;
					}
				}
		
		VeMuiTen(dothi[temp1],dothi[temp2],15);
		VeDinh1(dothi[temp1]);
		VeDinh1(dothi[temp2]);
		trongso=NhapTrongSo();
		if (trongso==0)
		{
			G[temp1][temp2]=0;
		}
		else G[temp1][temp2]=trongso;
		VeTrongSo(temp1,temp2);
		
		
		ReInitCanh();
		clearmouse();
		ResetDoThi();
	}	
	
	void ResetCanh()
	{
		dinh tempdau,tempcuoi;
		tempdau.name= new char [3];
		tempcuoi.name- new char [3];
		int dem=-1;
		int x,y;
		string trongso;
		for (int i=0;i<n;i++)
		{    // for (int j=0;j<i;j++)
			for (int j=0;j<n;j++)
			{
				if (G[i][j]!=0)
					{
						VeCanh(i,j,15);
						trongso = IntToString(G[i][j]);
						if (canh[i][j]==0)
						{
						x = ((dothi[i].x+dothi[j].x) / 2);
						y = ((dothi[i].y+dothi[j].y) / 2);
						}
						else if (canh[i][j]==1)
						{
							x=(((dothi[i].x+10)+(dothi[j].x+10))/2);
							y=(((dothi[i].y+10)+(dothi[j].y+10))/2);
						}
						else
						{
							x=(((dothi[i].x-10)+(dothi[j].x-10))/2);
							y=(((dothi[i].y-10)+(dothi[j].y-10))/2);
						}
						VeDinh1(dothi[i]);
						VeDinh1(dothi[j]);
						outtextxy(x + 10, y + 10, &trongso[0]);
					}
			}
		}
		MTTS();
		note();
	}
	
		
	void DocFile()
	{
		HuongDan();
		char c;
		string tenfile;
		char* kq = new char[20];
		string s;
		outtextxy(370, 520, "Nhap toi da 20 chu, khong can ghi duoi mo rong cua file. Nhan ENTER de ket thuc");
		outtextxy(370, 540, "Ten file: ");
		outtextxy(495, 540, &s[0]);
		int i = 0;
		do
		{
			fflush(stdin);
			while (!kbhit());
			c = getch();
			if (c != 13 && c != 8 && i < 20 && ((c>=65 && c<=90) ||(c>=97 && c<=122) || (c>=48 && c<=57) ))
			{
				i++;
				s += c;
			}
			else if (c == 8 && i > 0){
				i--;
				s = xoaKiTu(s);
			}
			kq = StringToChar(s);
			HuongDan();
			outtextxy(370, 520, "Nhap toi da 3 chu, nhan ENTER de ket thuc");
			outtextxy(370, 540, "Ten dinh: ");
			outtextxy(495, 540, &s[0]);
			if (n-1 >19 )
			{
				for (int j = 0; j < n-1; j++)
				{
					if (strcmp(kq, dothi[j].name) == 0)
					{
						do
						{
							fflush(stdin);
						} 
						while (!kbhit());
						c = getch();
						if (c != 13 && c != 8 && i < 3 && c >= 65 && c <= 90)
						{
							i++;
							s += c;
						}
						else if (c == 8 && i > 0){
							i--;
							s = xoaKiTu(s);
						}
						kq = StringToChar(s);

					}
				}
			}
			HuongDan();
			outtextxy(370, 520, "Nhap toi da 20 chu, khong can ghi duoi mo rong cua file. Nhan ENTER de ket thuc");
			outtextxy(370, 540, "Nhap ten file: ");
			outtextxy(495, 540, &s[0]);
		} while (c != 13 || i == 0);
		tenfile=s;
		ofstream f;
		
		tenfile += ".txt";
		f.open(&tenfile[0]);
		
		f<<n<<endl;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
					f<<G[i][j]<<" ";
			}
			f<<endl;
		}
		for (int i=0;i<n;i++)
		{
			f<<dothi[i].x<<" "<<dothi[i].y<<" "<<dothi[i].name<<endl;
		}
		outtextxy(370, 560, "LUU FILE HOAN TAT !!!");
		f.close();	
		outtextxy(370,580,"Press any key...");
		getch();
		HuongDan();
	}
	
	void OpenFile()
	{
		
		HuongDan();
		char c;
		string tenfile;
		char* kq = new char[20];
		string s;
		outtextxy(370, 520, "Nhap toi da 20 chu, khong can ghi duoi mo rong cua file. Nhan ENTER de ket thuc");
		outtextxy(370, 540, "Ten file: ");
		outtextxy(495, 540, &s[0]);
		int i = 0;
		do
		{
			fflush(stdin);
			while (!kbhit());
			c = getch();
			if (c != 13 && c != 8 && i < 20 && ((c>=65 && c<=90) ||(c>=97 && c<=122) || (c>=48 && c<=57) ))
			{
				i++;
				s += c;
			}
			else if (c == 8 && i > 0){
				i--;
				s = xoaKiTu(s);
			}
			kq = StringToChar(s);
			HuongDan();
			outtextxy(370, 520, "Nhap toi da 20 chu, khong can ghi duoi mo rong cua file. Nhan ENTER de ket thuc");
			outtextxy(370, 540, "Ten file: ");
			outtextxy(495, 540, &s[0]);
			if (n-1 >19 )
			{
				for (int j = 0; j < n-1; j++)
				{
					if (strcmp(kq, dothi[j].name) == 0)
					{
						do
						{
							fflush(stdin);
						} 
						while (!kbhit());
						c = getch();
						if (c != 13 && c != 8 && i < 3 && c >= 65 && c <= 90)
						{
							i++;
							s += c;
						}
						else if (c == 8 && i > 0){
							i--;
							s = xoaKiTu(s);
						}
						kq = StringToChar(s);

					}
				}
			}
			HuongDan();
			outtextxy(370, 520, "Nhap toi da 20 chu, khong can ghi duoi mo rong cua file. Nhan ENTER de ket thuc");
			outtextxy(370, 540, "Nhap ten file: ");
			outtextxy(495, 540, &s[0]);
		} while (c != 13 || i == 0);
		tenfile=s;
		
		tenfile+=".txt";
		
		ifstream f;
		f.open(&tenfile[0]);
		if (f.fail())
		{
			HuongDan();
			outtextxy(370, 520, "File khong ton tai");
			return;
		}
		else name=strupr(&tenfile[0]);
		f>>n;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				f>>G[i][j];
				if (G[i][j]==0)
				{
					G[i][j]=NULL;
				}
			}
		}
		for (int i=0;i<n;i++)
		{
			dothi[i].name = new char[3];
			f>>dothi[i].x;
			f>>dothi[i].y;
			f>>dothi[i].name;
		}
			outtextxy(370, 560, "DOC FILE HOAN TAT !!!");
		f.close();
		ReInitCanh();
		ResetDoThi();
	}
	
	
	void DinhCopy(dinh &a, dinh &b)
	{
		a.x=b.x;
		a.y=b.y;
		strcpy(a.name,b.name);
	}

	void XoaDinh()
	{
		int x,y,vt;
		outtextxy(370, 520, "Nhap vao dinh can xoa");
	
		//Nhan Click dinh
		while (true)
		{
			delay(.001);
			if (ismouseclick(WM_LBUTTONDOWN))
			{
				getmouseclick(WM_LBUTTONDOWN,x,y);
			}
			if (IsDinh(x,y))
			{
				break;
			}
		}
		
		//Tim vi tri dinh duoc click
		for (int i=0;i<n;i++)
		{
			if (IsDinh1(x,y,dothi[i]))
			{
				vt=i;
				break;
			}
		}
		
		//Xoa dinh
			//Vi tri cuoi
		if (vt==n-1)
		{
			dothi[n-1].x=NULL;
			dothi[n-1].y=NULL;
			dothi[n-1].name=NULL;
		}
			//Vi tri bat ki
		else
		{
			for (int i=vt;i<n-1;i++)
			{
				DinhCopy(dothi[i],dothi[i+1]);
			}
		}
		dothi[n-1].x=NULL;
		dothi[n-1].y=NULL;
		dothi[n-1].name=NULL;
		//Xoa canh	
			//Vi tri dau
		if(vt==n-1)
		{
			for (int i=0;i<n;i++)
			{
				G[i][n-1]=0;
				G[n-1][i]=0;
			}
			
		}
			//Vi tri bat ki
		else
		{
			for (int i=0;i<n;i++)
			{
				for (int j=vt;j<n-1;j++)
				{
					G[i][j]=G[i][j+1];
				}
				G[i][n-1]=0;
			}
			
			for(int j=0;j<n;j++)
			{
				for(int i=vt;i<n-1;i++)
				{
					G[i][j]=G[i+1][j];
				}
				G[n-1][j]=0;
			}
			
		}
		n--;
		ReInitCanh();
		ResetDoThi();
		
	}
	
	void MoveDinh()
	{
		int x,y,vt;
	
		outtextxy(370, 520, "Nhap vao dinh can di chuyen");
		while (true)
		{
			delay(.001);
			if (ismouseclick(WM_LBUTTONDOWN))
			{
				getmouseclick(WM_LBUTTONDOWN,x,y);
			}
			if (IsDinh(x,y))
			break;
		
		}
		
		//Tim vi tri dinh duoc click
		for (int t=0;t<n;t++)
		{
			if (IsDinh1(x,y,dothi[t]))
			{
				vt=t;
				DoiMauDinh(t,2);
				break;
			}
		}
		HuongDan();
		outtextxy(370, 520, "Nhap vao noi den");
		while(true)
		{
			delay(.001);
			if(ismouseclick(WM_LBUTTONDOWN))
			{
				getmouseclick(WM_LBUTTONDOWN,x,y);
			}
			if(x >= (465+BK) && x <= (1250-BK) && y >= (30+BK) && y <= (480-BK) && x!=-1 && y!=-1 && !IsDinh(x,y))
			{
				dothi[vt].x=x;
				dothi[vt].y=y;
				break;
			}
		}
		ResetDoThi();
	}
	
	void DoiTenDinh()
	{
	int x,y,vt;
		outtextxy(370, 520, "Nhap vao dinh can doi ten");
		outtextxy(370, 540, "Ten dinh phai khac voi cac dinh khac");
		while (true)
		{
			delay(.001);
			if (ismouseclick(WM_LBUTTONDOWN))
			{
				getmouseclick(WM_LBUTTONDOWN,x,y);
			}
			if (IsDinh(x,y))
			{
				break;
			}
		}
		
		//Tim vi tri dinh duoc click
		for (int i=0;i<n;i++)
		{
			if (IsDinh1(x,y,dothi[i]))
			{
				vt=i;
				break;
			}
		}
		//Nhap ten moi
		char* c= new char[3];
		c = TenDinh();
		c = strupr(c);
		if (n > 1)
		{
			ad:
			for (int i = 0; i < n; i++)
			{
				while (strcmp(c, dothi[i].name) == 0)
				{
					c = TenDinh();
					c = strupr(c);
					goto ad;
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			dothi[vt].name[i] = c[i];
		}
		ResetDoThi();	
	}
	void DoiMauDinh(int vt, int mau)
	{
	setfillstyle(1, mau);
	setcolor(mau);
	pieslice(dothi[vt].x, dothi[vt].y, 0, 0, BK);
	setcolor(15);	
	outtextxy(dothi[vt].x - 9, dothi[vt].y - 9, dothi[vt].name);
	setcolor(mau-1);
	circle(dothi[vt].x,dothi[vt].y,BK);
	setcolor(15);
	}
	
		void Euler()
	{
		Init();
		HuongDan();
		int a[MAX*MAX];
		int sl=0;
		string thongbao="";
		int dem1, dem2;
		bool euler =true;
		dfs(0,a,sl);
		if (sl!=(n))
		{
			outtextxy(370,520,"KHONG CO CHU TRINH EULER!");
		}
		else 
		{
			for (int i=0;i<n;i++)
			{
				dem1=0;
				dem2=0;
				for (int j=0;j<n;j++)
				{
					if (G1[i][j]!=MAXX)
						dem1++;
					if (G1[j][i]!=MAXX)
						dem2++;
				}
				if (dem1!=dem2)
				{
					outtextxy(370,520,"KHONG CO CHU TRINH EULER!");
					euler=false;
					break;
					
				}
			}
			if (euler==true)
			{
				EulerCycle(0,a,sl);
				for (int i=0;i<sl-1;i++)
				{
					thongbao=thongbao+dothi[a[i]].name+">";
				}
				thongbao=thongbao+dothi[a[sl-1]].name;
			
				outtextxy(370,520,"Chu trinh Euler: ");
				outtextxy(370,540,&thongbao[0]);
				
			//	Draw(a,sl,14,500);
				int truoc=a[0];
				for (int i=0;i<sl;i++)
				{
					delay(500);
					DoiMauDinh(a[i],14);
					VeCanh(truoc,a[i],13);
					DoiMauDinh(truoc,14);
					DoiMauDinh(a[i],14);	
					truoc=a[i];
				}
				outtextxy(370,560,"Press any key...");
				getch();
				HuongDan();
				ResetDoThi();
			}
		}
	}
	
	void EulerCycle(int vt,int kq[], int &sl)
	{
		Init();
		int stack[MAX*MAX];
		int CE[MAX*MAX];
		int p=0;
		int sp=1;
		int s;
		int t;
		bool ke=false;
		stack[sp]=vt;
		while (sp!=0)
		{
			ke=false;
			s=stack[sp];
			for (int i=0;i<n;i++)
			{
				if (G1[s][i]!=MAXX)
				{
					sp++;
					stack[sp]=i;
					G1[s][i]=MAXX;
					ke = true;
					break;
				}
			}
			if (!ke)
			{
				sp--;
				CE[p]=s;
				p++;
			}
			
		}
	
		
		
		sl=p;
		for (int i=0;i<p;i++)
		{
			kq[i]=CE[p-1-i];
		}
	}

	
	void TopoSort()
	{
		int S[MAX*MAX];
		int low =1;
		int high=1;
		int L[MAX];
		int Lp=-1;
		int dem;
		int temp;
		Init();
		HuongDan();
		for (int i=0;i<n;i++)
		{
			dem=0;
			for (int j=0;j<n;j++)
			{
				if (G1[j][i]!=MAXX)
					dem++;
			}
			if (dem==0)
			{
				cout<<dothi[i].name<<" ";
				S[high]=i;
				high++;
				chuaxet[i]=false;
			}
		}
		high--;
		while (low<=high)
		{
			Lp++;
			L[Lp]=S[low];
			temp=S[low];
			low++;
			
			for (int i=0;i<n;i++)
			{
				if (G1[temp][i]!=MAXX)
					G1[temp][i]=MAXX;
					
				dem=0;
				for (int j=0;j<n;j++)
				{
					if (G1[j][i]!=MAXX)
					{
						dem++;
					}
				}
				if (dem==0 && chuaxet[i]==true)
				{
					high++;
					S[high]=i;
					chuaxet[i]=false;
				}
			}
		}
		string s="Ket Qua: ";
		bool isdone=true;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				if (G1[i][j]!=MAXX)
				{
					isdone=false;
					break;
				}
			}
			if (isdone==false)
				break;
		}
		if (isdone == false)
			outtextxy(370,520,"Khong du dieu kien");
		else
		{
			for (int i=0;i<=Lp;i++)
			{
				delay(500);
				s=s+" "+dothi[L[i]].name;
				outtextxy(370,520,&s[0]);
				DoiMauDinh(L[i],2);
			}
		}
		outtextxy(370,540,"Press any key...");
		getch();
		ResetDoThi();
	}

	void InitCanh()
	{
		for (int i=0;i<MAX;i++)
		{
			for (int j=0;j<MAX;j++)
			{
				xetcanh[i][j]=false;
				canh[i][j]=0;
			}
		}
	}
	
	void ReInitCanh()
	{
		InitCanh();
		
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				if (xetcanh[i][j]==false)
				{
					if (G[i][j]!=0 && xetcanh[i][j]==false)
					{
						if (G[j][i]==0)
						{
							canh[i][j]=0;
						}
						else if (xetcanh[j][i]==false)
							{
								canh[i][j]=1;
								canh[j][i]=-1;
								xetcanh[j][i]=true;
							}
							else canh[i][j]=-1;
						
				}
				}
				xetcanh[i][j]=true;
			}
		}
	}
	
		
	void Hamilton()
	{
		HuongDan();
		int x,y;
		int vt;
		HuongDan();
		outtextxy(370,520,"Nhap vao dinh bat dau: ");
		while (1)
		{
			delay(.001);
			if (ismouseclick(WM_LBUTTONDOWN))
				getmouseclick(WM_LBUTTONDOWN,x,y);
			if (IsDinh(x,y))
				break;
		}
		for (int i=0;i<n;i++)
		{
			if (IsDinh1(x,y,dothi[i]))
			{
				vt=i+1;
				DoiMauDinh(i,1);
				break;
			}
		}
		B[0]=vt;
		i=1;
		d=0;
		
		Init1();
		HuongDan();
		HamiltonCycle(B,C,i);
		if (d==0)
			outtextxy(370,520,"KHONG CO CHU TRINH HAMILTON");
		outtextxy(370,540,"Press any key...");
		getch();
		ResetDoThi();		
	}
	
	void HamiltonCycle(int *B, int *C, int i)
	{
		int j, k;
  		for(j=1; j<=n; j++){
    	if(G2[B[i-1]][j]==1 && C[j]==0){
     	 B[i]=j; C[j]=1;
     	 if(i<n) HamiltonCycle(B, C, i+1);
      	else if(B[i]==B[0]) Result();
     	 C[j]=0;
    }
  }
	}
	

	void TPLT()
	{
		HuongDan();
		int kq[MAX*MAX];
		int sl=0;
		
		if(IsVoHuong()==false)
		{
			Init();
			bool IsLT=true;
			for (int i=0;i<n;i++)
			{
				dfs(i,kq,sl);
				if (sl!=n)
				{
					IsLT=false;
					break;
				}
			}
			if (IsLT==true)
				outtextxy(370,520,"DO THI LIEN THONG MANH");
			else outtextxy(370,520,"DO THI LIEN THONG YEU");
			
		}
		else 
		{
			outtextxy(700,520,"CAC THANH PHAN LIEN THONG CUA DO THI:");
		Init();
	
		int yy=540;
		int xx=370;
		int dem=1;
		
		int color=2;
		dfs(0,kq,sl);
		string s="";
		string temp="";
		for (int i=0;i<sl;i++)
		{
			s=s+" "+dothi[kq[i]].name;
		}
		temp="TPLT "+ IntToString(dem)+": ";
		outtextxy(xx,yy,&temp[0]);
		outtextxy(xx+60,yy,&s[0]);
		yy=yy+20;
		Draw(kq,sl,color,400);
		for (int i=0;i<n;i++)
		{
			if (chuaxet[i]==true)
			{
				temp="";
				if (color==15)
					color=0;
				else color++;
				sl=0;
				dfs(i,kq,sl);
				dem++;
				s="";
				for (int i=0;i<sl;i++)
				{
					s=s+" "+dothi[kq[i]].name;
				}
				temp="TPLT "+ IntToString(dem)+": ";
				outtextxy(xx,yy,&temp[0]);
				outtextxy(xx+60,yy,&s[0]);
				if (yy>640)
				{
					xx=xx+150;
					yy=540;
				}
				else yy=yy+20;
				Draw(kq,sl,color,500);
			}
		
		}
		}
		
		getch();
		ResetDoThi();
	}
	
	int LienThong()
	{
		for (int i=0;i<n;i++)
		{
			if (chuaxet[i]==true)
				return 1;
			
		}
		return 0;
	}
	
	void VeCanh(int dau, int cuoi, int color)
	{
		dinh t1,t2;
		t1.name=new char [3];
		t2.name = new char [3];
		if (canh[dau][cuoi]==0)
			{
				VeMuiTen(dothi[dau],dothi[cuoi],color);
			
			}
		else if (canh[dau][cuoi]==1)
			{
				t1.x=dothi[dau].x;
				t1.y=dothi[dau].y;
				t2.x=dothi[cuoi].x;
				t2.y=dothi[cuoi].y;
				t1.x+=10;
				t1.y+=10;
				t2.x+=10;
				t2.y+=10;
				VeMuiTen(t1,t2,color);
				
			}
			else 
			{
				t1.x=dothi[dau].x;
				t1.y=dothi[dau].y;
				t2.x=dothi[cuoi].x;
				t2.y=dothi[cuoi].y;
				t1.x-=10;
				t1.y-=10;
				t2.x-=10;
				t2.y-=10;
				VeMuiTen(t1,t2,color);
				
			}
	}

	bool IsVoHuong()
	{
		bool cheo=true;
		bool canh=true;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				if (i==j)
				{
					if (G[i][j]!=0)
					{
						cheo=false;
						break;
					}
				}
				else 
				{
					if (G[i][j]!=G[j][i])
					{
						canh=false;
						break;
					}
				}
			}
			if ((canh==false) || (cheo==false))
				break;
		}
		if ((canh==false) || (cheo==false))
			return false;
		else return true;
	}
	
	void DinhTru() 
	{
		if (IsVoHuong()==true)
		{
			int a[MAX];
		int sl=0;
		int xx=370;
		int d=0;
		HuongDan();
		outtextxy(370,520,"Cac dinh tru: ");
		Init();
		for(int i=0;i<n;i++)
		{	
			chuaxet[i]=false;
			if (i!=n-1)
				dfs(i+1,a,sl);
			else dfs(1,a,sl);
			if(LienThong()==1)
			{
				d++;
				outtextxy(xx,540,dothi[i].name);
				DoiMauDinh(i,1);
				xx=xx+20;
			}
			Init();
		}
		if (d==0)
			outtextxy(370,540,"KHONG CO :)");
		}
		else outtextxy(370,540,"DAY KHONG PHAI DO THI VO HUONG");
		outtextxy(370,560,"Press any key...");
		getch();
		HuongDan();
		ResetDoThi();
				
	}
	void CanhCau()
	{
		if(IsVoHuong()==true)
		{
			int a[MAX];
		int sl=0;
		int xx=370;
		int yy=520;
		int d=0;
		Init();
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				if (G1[i][j]!=MAXX)
				{
					G1[i][j]=MAXX;
					dfs(1,a,sl);
					if(LienThong()==1)
					{
					VeCanh(i,j,4);
					DoiMauDinh(i,5);
					DoiMauDinh(j,5);
					setcolor(15);
					outtextxy(xx,yy,dothi[i].name);
					outtextxy(xx+20,yy,"=>");
					outtextxy(xx+40,yy,dothi[j].name);
					if (yy>640)
					{
						xx=500;
						yy=520;
					}
					else	yy=yy+20;
					d++;
					}
				}
				Init();
			}
		}
		if (d==0)
		{
			outtextxy(370,520,"Khong co canh cau");
			outtextxy(370,540,"Press any key...");
		}
		}
		else
		{
			outtextxy(370,520,"DAY KHONG PHAI DO THI VO HUONG");
			outtextxy(370,540,"Press any key...");
			
		}
		
		
		getch();
		HuongDan();
		ResetDoThi();
	}

	
