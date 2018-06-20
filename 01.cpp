#include <stdlib.h>
#include <conio.h>//包含getch()和getche()
#include <fstream>
#define TRUE 1;
#include <iostream>
using namespace std;

struct zhigong *read();
void write(struct zhigong *first);
void find(struct zhigong *first);
void list(struct zhigong *first);
void modify(struct zhigong *first);
struct zhigong del(struct zhigong *first);
struct zhigong add(struct zhigong *first);
float grsds(float m);//定义各函数

struct emploee
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
};   //定义结构体

	/*list list1[9]={"A1001","张三",100,99,98,97,96,95,94,};
	ofstream out("gx.dat",ios::binary);
	if(!out)
	{
		cout<<"打开失败\n";
		abort();
	}
	for(int i=0;i<9;i++)
		out.write((char *) &list1[i],sizeof(list1[i]));
	out.close();*/
/*	char ch;
	int n;
	struct zhigong *first;
	first=read();*/
void main()
{
	char ch;
	struct zhigong *first;
	first=read();
	
	while(TRUE)
	{
//	cout<<".读取职工工资数据："<<endl;
	cout<<".保存职工工资数据："<<endl;
	cout<<".查询职工工资数据："<<endl;
	cout<<".浏览职工工资数据："<<endl;
	cout<<".修改职工工资数据："<<endl;
	cout<<".删除职工工资数据："<<endl;
	cout<<".添加职工工资数据："<<endl;
	cout<<".计算个人所得税："<<endl;
	cout<<"你的选择是："<<endl;
	ch=getche();

	switch(ch)
	  {
    	case '1':write(first);break;
		case '2':find(first);break;
		case '3':list(first);break;
		case '4':modify(first);break;
		case '5':del(first);break;
		case '6':add(first);break;
		case '7':return;
	  }
	}
	return;
}

/*********从数据文件gx.dat中读取职工工资数据到结构数组zggz中**********/


struct zhigong *read()
{
	FILE*file;
	int n=0;
	struct zhigong *first,*readdate;//记录首地址及新分配内存地址
	struct zhigong *p;//中间变量

	if((file=fopen("gz.dat","rb"))==NULL)//以二进制方式打开职工工资数据文件并进行判断是否失败
	{
		cout<<"文件无法打开，或为空\n";
		cout<<"按任意键进入主菜单\n";
		getch();
		return 0;
	}
	else  //文件打开成功时
	{
		readdate=(struct zhigong *)malloc(sizeof(struct zhigong));//循环读取
//		readdate=( struct zhigong *)malloc(sizeof( zhigong));
	}
	while(fread(readdate,sizeof(struct zhigong),1,file)==1)
		if(n==0)   //说明需要建立链表起始项
		{
			first=readdate;
			first->front=NULL;
		}
}