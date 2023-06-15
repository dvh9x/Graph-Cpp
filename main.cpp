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
	

