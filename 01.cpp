#include <stdlib.h>
#include <conio.h>//����getch()��getche()
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
float grsds(float m);//���������

struct emploee
{
	char gonghao[10];  //����
	char name[10];//����
	float moy1;//��λ����
	float moy2;//н������
	float moy3;//ְ�����
	float moy4;//��Ч����
	float moy5;//Ӧ������
	float moy6;//��������˰
	float moy7;//ʵ������
};   //����ṹ��

	/*list list1[9]={"A1001","����",100,99,98,97,96,95,94,};
	ofstream out("gx.dat",ios::binary);
	if(!out)
	{
		cout<<"��ʧ��\n";
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
//	cout<<".��ȡְ���������ݣ�"<<endl;
	cout<<".����ְ���������ݣ�"<<endl;
	cout<<".��ѯְ���������ݣ�"<<endl;
	cout<<".���ְ���������ݣ�"<<endl;
	cout<<".�޸�ְ���������ݣ�"<<endl;
	cout<<".ɾ��ְ���������ݣ�"<<endl;
	cout<<".���ְ���������ݣ�"<<endl;
	cout<<".�����������˰��"<<endl;
	cout<<"���ѡ���ǣ�"<<endl;
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

/*********�������ļ�gx.dat�ж�ȡְ���������ݵ��ṹ����zggz��**********/


struct zhigong *read()
{
	FILE*file;
	int n=0;
	struct zhigong *first,*readdate;//��¼�׵�ַ���·����ڴ��ַ
	struct zhigong *p;//�м����

	if((file=fopen("gz.dat","rb"))==NULL)//�Զ����Ʒ�ʽ��ְ�����������ļ��������ж��Ƿ�ʧ��
	{
		cout<<"�ļ��޷��򿪣���Ϊ��\n";
		cout<<"��������������˵�\n";
		getch();
		return 0;
	}
	else  //�ļ��򿪳ɹ�ʱ
	{
		readdate=(struct zhigong *)malloc(sizeof(struct zhigong));//ѭ����ȡ
//		readdate=( struct zhigong *)malloc(sizeof( zhigong));
	}
	while(fread(readdate,sizeof(struct zhigong),1,file)==1)
		if(n==0)   //˵����Ҫ����������ʼ��
		{
			first=readdate;
			first->front=NULL;
		}
}