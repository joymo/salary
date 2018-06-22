#include <stdlib.h>#include <conio.h>//包含getch()和getche()
#include<stdio.h>
#include<string.h>
#include <fstream>
#define TRUE 1
#include <iostream>using namespace std;void read();
void write();
void find();
void list();
void modify();
void del();
void add();
float grsds(float m);
//定义各函数
struct zhigong   //声明结构体{	char gonghao[10];  //工号	char name[10];//姓名	float moy1;//岗位工资	float moy2;//薪级工资	float moy3;//职务津贴	float moy4;//绩效工资	float moy5;//应发工资	float moy6;//个人所得税	float moy7;//实发工资};   struct zhigong zggz[100];  //声明记录职工工资情况的100个袁术的结构体数组	int n=-1;  //声明工人个数的全局变量nvoid main(){	char ch;	while(TRUE)	{	system( "cls" ); //清屏	cout<<"1.读取职工工资数据："<<endl;	cout<<"2.保存职工工资数据："<<endl;	cout<<"3.查询职工工资数据："<<endl;	cout<<"4.浏览职工工资数据："<<endl;	cout<<"5.修改职工工资数据："<<endl;	cout<<"6.删除职工工资数据："<<endl;	cout<<"7.添加职工工资数据："<<endl;	cout<<"8.计算个人所得税："<<endl;	cout<<"你的选择是："<<endl;	ch=getche();	switch(ch)	  {    	case '1':write();break;		case '2':find();break;		case '3':list();break;		case '4':modify();break;		case '5':del();break;		case '6':add();break;		case '7':return;	  }	}	return;}/*********读取职工工资数据**********///从数据文件gx.dat中读取职工工资数据到结构数组zggz中void read(){	FILE *file;  //声明文件指针	if((file=fopen("gz.dat","rb"))==NULL)//rb以二进制方式打开职工工资数据文件并进行判断是否失败	{		cout<<"文件无法打开，或为空\n";		cout<<"按任意键进入主菜单\n";		getch();		return;	}	else  //文件打开成功时	{		n++;		while(fread(&zggz[n],sizeof(zggz[n]),1,file)==1)		{			n++;		}		fclose(file);		cout<<"职工工资数据读取完毕，共有"<<n<<"人\n";		n--;  // 计算职工记录总数	}/**********保存职工工资数据**************/void write(){	FILE *file;  //声明文件指针	if(n=-1)   //职工数为0	{		cout<<"没有数据可存，请返回主菜单\n";		getch();		return;	}	if((file=fopen("gz.dat","wb"))!=NULL)//打开职工工资数据文件		fwrite(&zggz[0],sizeof(zggz[0]),n+1,file);  //所有记录一次写入文件	fclose(file);	cout<<n+1<<"条记录保存完毕!\n";	else   //若文件打开不成功	{		cout<<"无法打开职工数据文件。\n";	}	cout<<"按任意键进入主菜单\n";		getch();}