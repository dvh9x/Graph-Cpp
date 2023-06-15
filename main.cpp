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

int main()
{
}
