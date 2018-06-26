
#include <stdlib.h>#include <conio.h>//包含getch()和getche()
#include<stdio.h>
#include<string.h>
#include <fstream>
#define TRUE 1
#include <iostream>using namespace std;void read();
void write();
void find();
void list();
void modify();
void del();
void add();
float grsds(float m);
//定义各函数
struct zhigong   //声明结构体
{	char gonghao[10];  //工号	
char name[10];//姓名	
float moy1;//岗位工资	
float moy2;//薪级工资	
float moy3;//职务津贴	
float moy4;//绩效工资	
float moy5;//应发工资	
float moy6;//个人所得税	
float moy7;//实发工资
};   
struct zhigong zggz[100];  //声明记录职工工资情况的100个袁术的结构体数组	
int n=-1;  //声明工人个数的全局变量
nvoid main()
{	char ch;	
while(TRUE)	{	
	system( "cls" ); //清屏	
	cout<<"1.读取职工工资数据："<<endl;	
	cout<<"2.保存职工工资数据："<<endl;	
	cout<<"3.查询职工工资数据："<<endl;	
	cout<<"4.浏览职工工资数据："<<endl;	
	cout<<"5.修改职工工资数据："<<endl;	
	cout<<"6.删除职工工资数据："<<endl;	
	cout<<"7.添加职工工资数据："<<endl;	
	cout<<"8.计算个人所得税："<<endl;	
	cout<<"你的选择是："<<endl;	
	ch=getche();	
	switch(ch)	
	{    	case '1':write();break;		
	        case '2':find();break;		
			case '3':list();break;	
			case '4':modify();break;	
			case '5':del();break;	
			case '6':add();break;	
			case '7':return;	 
	}
   }	
     return;
}



/*********读取职工工资数据**********/
//从数据文件gx.dat中读取职工工资数据到结构数组zggz中

void read(){	FILE *file;  //声明文件指针	
if((file=fopen("gz.dat","rb"))==NULL)//rb以二进制方式打开职工工资数据文件并进行判断是否失败	
{		cout<<"文件无法打开，或为空\n";	
        cout<<"按任意键进入主菜单\n";	
		getch();		
		return;	
}	else  //文件打开成功时
{		n++;		
        while(fread(&zggz[n],sizeof(zggz[n]),1,file)==1)	
		{			
			n++;	
		}		
		fclose(file);		
		cout<<"职工工资数据读取完毕，共有"<<n<<"人\n";		n--;  // 计算职工记录总数
}

/**********保存职工工资数据**************/

void write()
{	
	FILE *file;  //声明文件指针	
if(n=-1)   //职工数为0	
{		cout<<"没有数据可存，请返回主菜单\n";		
        getch();		
		return;	
}	
if((file=fopen("gz.dat","wb"))!=NULL)//打开职工工资数据文件		
	fwrite(&zggz[0],sizeof(zggz[0]),n+1,file);  //所有记录一次写入文件	
fclose(file);	cout<<n+1<<"条记录保存完毕!\n";	
else   //若文件打开不成功	
{		
	cout<<"无法打开职工数据文件。\n";	
}	cout<<"按任意键进入主菜单\n";		
getch();
}



/**********查询职工工资数据**************/

void find()
{
	char gh[10];
	int i;

	if (n==-1)
	{
		cout<<"现在还没有工资记录"<<endl;
		getch();
		return;
	}
	cout<<"请输入职工编号"<<endl;
	gets(ch);   //从键盘输入工号

	for(n=0;i<=n;i++)
	{
		if(strcmp(zggz[i].gonghao,gh)==0)
		{
			cout<<"该职工的工资情况为："<<endl;
			cout<<"岗位工资:"<<zggz[i].moy1<<endl;
			cout<<"薪级工资："<<zggz[i].moy2<<endl;
			cout<<"职务津贴："<<zggz[i].moy3<<endl;
			cout<<"绩效工资："<<zggz[i].moy4<<endl;
			cout<<"应发工资："<<zggz[i].moy5<<endl;
			cout<<"个人所得税："<<zggz[i].moy6<<endl;
			cout<<"实发工资："<<zggz[i].moy7<<endl;
			cout<<"按任意键返回主菜单\n";
			getch();
			return;
		}
	}
	if(i==n+1)
	{
		cout<<"您输入的职工工号有误或不存在"<<endl;
		cout<<"按任意键返回主菜单\n";
		getch();
		return;
	}
}


/**********浏览职工工资数据**************/





/**********修改职工工资数据**************/

void modify()
{
	char gh[10];  //接受职工工号
	int i;    //循环控制变量
	if(n==-1)
	{
		printf("\n\n\t\t没有职工工资记录，按任意键返回主菜单\n")
		getch();
		return;
	}
		printf("请输入职工编号");
		gets(ch);   //从键盘输入工号
}
for(n=0;i<=n;i++)
	{
		if(strcmp(zggz[i].gonghao,gh)==0)   //显示职工工资情况
		{
			printf("该职工的工资情况为：");
			printf("\t%s\t%s\t%s\t%s\t%s","职工工号","职工姓名","岗位工资","薪级工资","职务津贴");
			printf("\t%s\t%s\t%s\t%s","绩效工资","应发工资","个人所得税","实发工资");

			printf("\t%s\t%s\t%.2f\t%.2f\t%.2f",zggz[i].gonghao,zggz[i].name,zggz[i].moy1,zggz[i].moy2,zggz[i].moy3);
			printf("\t%.2f\t%.2f\t%.2f\t%.2f",zggz[i].moy4,zggz[i].moy5,zggz[i].moy6,zggz[i].moy7); 

			//接收新的工资数据
			printf("\n\t\t请输入该职工新的岗位工资");
			fflush(stdin);
			scanf("%f",&zggz[i].moy1);

			printf("\n\t\t请输入该职工新的薪级工资");
			fflush(stdin);
			scanf("%f",&zggz[i].moy2);
			
			printf("\n\t\t请输入该职工新的职务津贴");
			fflush(stdin);
			scanf("%f",&zggz[i].moy3);

			printf("\n\t\t请输入该职工新的绩效工资");
			fflush(stdin);
			scanf("%f",&zggz[i].moy4);

//计算应发工资，个人所得税，实发工资
//应发=岗位+薪级+职务+绩效
			zggz[i].moy5=zggz[i].moy1+zggz[i].moy2+zggz[i].moy3+zggz[i].moy4;
				
//计算个人所得税
			zggz[i].moy6=moy6(zggz[i].moy1);
//计算实发工资=应发-个人所得税
			zggz[i].moy7=zggz[i].moy5-zggz[i].moy6;

			printf("\n\n\t\t该职工的应发工资为：%.2f",zgga[i].moy5);
			printf("\n\n\t\t该职工的个人所得税为：%.2f",zgga[i].moy6);
			printf("\n\n\t\t该职工的实发工资为：%.2f",zgga[i].moy7);

			printf("\n\n\t\t该职工工资数据修改成功，按任意键返回主菜单");

			getch();
			return;
		}
	}
     printf("\n\t\t您所输入的职工工号有误或不存在")；		
	 printf("按任意键返回主菜单");
	 getch();
	 return;
}



/**********删除职工工资数据**************/


void del()
{
	char gh[10];  //接收职工工号字符数组
	int i,j;  //循环控制变量
	char d;   //接收确认删除字符

	printf("请输入待删除的职工工号");
	gets(gh);
	for(i=0;i<=n;i++)   //在职工数组范围内循环
	{

	}
}