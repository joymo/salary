#include <stdlib.h>
#include <conio.h>//包含getch()和getche()
#include<stdio.h>
#include<string.h>
#define TRUE 1

//定义各函数
void read();
void write();
void find();
void list();
void modify();
void del();
void add();
float grsds(float m);

struct zhigong   //声明结构体
{	
	char gonghao[10];  //工号	
	char name[10];//姓名	
	float moy1;//岗位工资	
	float moy2;//薪级工资	
	float moy3;//职务津贴	
	float moy4;//绩效工资	
	float moy5;//应发工资	
	float moy6;//个人所得税	
	float moy7;//实发工资
};   
struct zhigong zggz[100];  //声明记录职工工资情况的100个元素的结构体数组	
int n=-1;  //声明统计工人个数的全局变量

void main()
{	char ch;	
while(TRUE)
{	
	system( "cls" ); //清屏	
	printf("\t\t 请选择1~7:\n"); 

	printf("\t\t\t 1.查询职工工资数据：\n");
	printf("\t\t\t 2.修改职工工资数据：\n");
	printf("\t\t\t 3.添加职工工资数据：\n");
	printf("\t\t\t 4.删除职工工资数据：\n");
	printf("\t\t\t 5.保存职工工资数据：\n");
	printf("\t\t\t 6.浏览职工工资数据：\n");
	printf("\t\t\t 7.退出系统\n");

	printf("\t\t你的选择是：");
	ch=getche();	
	switch(ch)	
	{    	case '1':find();break;		
	        case '2':modify();break;		
			case '3':add();break;	
			case '4':del();break;	
			case '5':write();break;	
			case '6':list();break;	
			case '7':return;
			
			default:printf("\t\t请按任意键返回从新选择（1-3）\n");
				getch();
	}
}	
     return;
}



/*********.读取职工工资数据**********/
//从数据文件gz.dat中读取职工工资数据到结构数组zggz中

void read()
{	
	FILE *fp;  //声明文件指针	
	if((fp=fopen("gz.dat","rb"))==NULL)//rb"只读"以二进制方式打开职工工资数据文件并进行判断是否失败	
	{
		printf("\n\n\t\t 职工工资数据文件无法打开，或不存在！");
		printf("\n\t\t 按任意键返回主菜单！");
		getch();		
		return;	
	}	
	else  //文件打开成功时
	{		n++;		
        while(fread(&zggz[n],sizeof(zggz[n]),1,fp)==1)	
		{			
			n++;	
		}		
		fclose(fp);
		printf("\n\n\t\t 职工工资数据读取完毕，共有%d人！\n",n); // 计算职工记录总数
		n--;   //计算职工记录总数
	}
}
/**********.保存职工工资数据**************/

void write()
{	
	FILE *file;  //声明文件指针	
	if(n=-1)   //职工数为0	
	{	
		printf("\t 没有数据可存，请按任意键返回主菜单！\n");		
        getch();		
		return;	
	}	
	if((file=fopen("gz.dat","wb"))!=NULL)  //"wb"读和写，打开职工工资数据文件
	{
		fwrite(&zggz[0],sizeof(zggz[0]),n+1,file);  //所有记录一次写入文件	
		fclose(file);
		printf("\n\n\t\t\t %d 条职工记录保存完毕！\n",n+1);

	}
	else   //若文件打开不成功	
	{		
		printf("\t\t\t无法打开职工数据文件。\n");	
	}
	
	printf("\n\t\t\t 按任意键返回主菜单！");
	getch();
}



/**********.查询职工工资数据**************/

void find()
{
	char gh[10];
	int i;

	if (n==-1)
	{
		printf("\n\n\t\t现在还没有工资记录,按任意键返回主菜单！\n");
		getch();
		return;
	}
	printf("请输入职工编号:");
	gets(gh);   //从键盘输入工号

	for(n=0;i<=n;i++)
	{
		if(strcmp(zggz[i].gonghao,gh)==0)
		{
			printf("\n\\t\t 该职工工资情况如下：\n");

			printf("\t%s\t%s\t%s\t%s\t%s","职工工号","职工姓名","岗位工资","薪级工资","职务津贴");
			printf("\t%s\t%s\t%s\t%s","绩效工资","应发工资","个人所得税","实发工资");

			printf("\t%s\t%s\t%.2f\t%.2f\t%.2f",zggz[i].gonghao,zggz[i].name,zggz[i].moy1,zggz[i].moy2,zggz[i].moy3);
			printf("\t%.2f\t%.2f\t%.2f\t%.2f",zggz[i].moy4,zggz[i].moy5,zggz[i].moy6,zggz[i].moy7); 

			printf("\n\t 按任意键返回主菜单！\n");
			getch();
			return;
		}
	}
	if(i==n+1)
	{
		printf("\n\t\t\t您输入的职工工号有误或不存在\n");
		printf("\n\t按任意键返回主菜单\n");
		getch();
		return;
	}
}


/**********.浏览职工工资数据**************/

void list()
{
	int i;
	system("cls");
	printf("\n\n\t\t\t\t 全体职工工资情况如下：\n");
	printf("\t%s\t%s\t%s\t%s\t%s","职工工号","职工姓名","岗位工资","薪级工资","职务津贴");
	printf("\t%s\t%s\t%s\t%s","绩效工资","应发工资","个人所得税","实发工资");

	for(i=0;i<=n;i++)   //在职工范围内循环输出
	{
		printf("\t%s\t%s\t%.2f\t%.2f\t%.2f",zggz[i].gonghao,zggz[i].name,zggz[i].moy1,zggz[i].moy2,zggz[i].moy3);
		printf("\t%.2f\t%.2f\t%.2f\t%.2f",zggz[i].moy4,zggz[i].moy5,zggz[i].moy6,zggz[i].moy7); 
	}
	printf("\n\t 按任意键返回主菜单 ");
	getch();
	return;
}



/**********.修改职工工资数据**************/

void modify()
{
	char gh[10];  //接受职工工号
	int i;    //循环控制变量
	if(n==-1)
	{
		printf("\n\n\t\t没有职工工资记录，按任意键返回主菜单\n");
		getch();
		return;
	}
		printf("请输入职工编号");
		gets(gh);   //从键盘输入工号

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
			zggz[i].moy6=grsds(zggz[i].moy5);
//计算实发工资=应发-个人所得税
			zggz[i].moy7=zggz[i].moy5-zggz[i].moy6;

//输出计算结果
			printf("\n\n\t\t该职工的应发工资为：%.2f",zggz[i].moy5);
			printf("\n\n\t\t该职工的个人所得税为：%.2f",zggz[i].moy6);
			printf("\n\n\t\t该职工的实发工资为：%.2f",zggz[i].moy7);

			printf("\n\n\t\t该职工工资数据修改成功，按任意键返回主菜单");

			getch();
			return;
		}
	}
     printf("\n\t\t您所输入的职工工号有误或不存在");		
	 printf("按任意键返回主菜单");
	 getch();
	 return;
}



/**********.删除职工工资数据**************/


void del()
{
	char gh[10];  //接收职工工号字符数组
	int i,j;  //循环控制变量
	char d;   //接收确认删除字符

	printf("请输入待删除的职工工号");
	gets(gh);
	for(i=0;i<=n;i++)   //在职工数组范围内循环查找
	{	
		if(strcmp(zggz[i].gonghao,gh)==0)  //进行比较匹配
		{
			printf("\n\t\t\t 您确认要删除 %s 号职工的信息吗？(y}(是)\n(否))",zggz[i].gonghao);
			d=getche();
			if(d=='y'||d=='Y')    //确认删除
			{
				if(i==n)   //到最后一条记录
					n--;
				else       //不是最后一条记录
				{
					for(j=0;j<=n;i++)    //从记录开始后续记录更新前一条记录
					{
						strcpy(zggz[i].gonghao,zggz[j+1].gonghao);
						strcpy(zggz[i].name,zggz[j+1].name);
						zggz[j].moy1=zggz[j+1].moy1;
						zggz[j].moy2=zggz[j+1].moy2;
						zggz[j].moy3=zggz[j+1].moy3;
						zggz[j].moy4=zggz[j+1].moy4;
						zggz[j].moy5=zggz[j+1].moy5;
						zggz[j].moy6=zggz[j+1].moy6;
						zggz[j].moy7=zggz[j+1].moy7;
					}
					n--;
				}
			printf("\n\n\t\t\t 成功删除该职工工资记录,按任意键返回主菜单");
			getch();
			break;
		}
		else       //放弃删除该职工记录
		{
			printf("\n\n 您选择不删除该职工工资记录，按任意键返回主菜单");
			getch();
			return;
		}
}
	}
if(i==n+1)    //未找到或未删除记录
{
	printf("\n\t\t\t找不到词工号，按任意键返回！");
	getch();
}
}


/*************.添加职工工资数据*******************/

void add()
{
	printf("\n\t\t\t请输入该职工工号：");
	fflush(stdin);   //清除缓冲区
	scanf("%f",&zggz[++n].gonghao);

	printf("\n\t\t\t 请输入该职工的岗位工资");
	fflush(stdin);     //清除缓冲区
	scanf("%f",&zggz[n].moy1);

	printf("\n\t\t\t 请输入该职工的薪级工资");
	fflush(stdin);     //清除缓冲区
	scanf("%f",&zggz[n].moy2);

	printf("\n\t\t\t 请输入该职工的职务津贴");
	fflush(stdin);     //清除缓冲区
	scanf("%f",&zggz[n].moy3);

	printf("\n\t\t\t 请输入该职工的绩效工资");
	fflush(stdin);     //清除缓冲区
	scanf("%f",&zggz[n].moy4);

//计算应发工资，个人所得税，实发工资
//应发=岗位+薪级+职务+绩效
			zggz[n].moy5=zggz[n].moy1+zggz[n].moy2+zggz[n].moy3+zggz[n].moy4;
				
//计算个人所得税
			zggz[n].moy6=grsds(zggz[n].moy1);
//计算实发工资=应发-个人所得税
			zggz[n].moy7=zggz[n].moy5-zggz[n].moy6;

//输出计算结果
			printf("\n\n\t\t\t该职工的应发工资为：%.2f",zggz[n].moy5);
			printf("\n\t\t\t该职工的个人所得税为：%.2f",zggz[n].moy6);
			printf("\n\t\t\t该职工的实发工资为：%.2f",zggz[n].moy7);

			printf("\n\n\t\t\t添加该职工工资数据成功，按任意键返回主菜单");
			getch();
}



/*************.计算个人所得税*******************/

float grsds(float m) 
{
	float x;        //当月应纳税所得额
	float y=0;      //当月应纳税额
	int n;

	x=m-2000;

	if(x>0)
	{
		if(x<500) n=1;
		  else if(x<2000) n=2;
		  else if(x<5000) n=3;
		  else if(x<20000) n=4;
		  else if(x<40000) n=5;
		  else if(x<60000) n=6;
		  else if(x<80000) n=7;
		  else if(x<100000) n=8;
	}
	switch(n)
	{
	case 1:y+=x*0.05;
		  case 2:y+=(x-500)*0.10; x=500;
		  case 3:y+=(x-2000)*0.15; x=2000;
		  case 4:y+=(x-5000)*0.20; x=5000;
		  case 5:y+=(x-20000)*0.25; x=20000;
		  case 6:y+=(x-60000)*0.30; x=60000;
		  case 7:y+=(x-80000)*0.35; x=80000;
		  case 8:y+=(x-100000)*0.45; x=100000;

	}
	return y;
}