#include <stdlib.h>#include <conio.h>//����getch()��getche()
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
//���������
struct zhigong   //�����ṹ��{	char gonghao[10];  //����	char name[10];//����	float moy1;//��λ����	float moy2;//н������	float moy3;//ְ�����	float moy4;//��Ч����	float moy5;//Ӧ������	float moy6;//��������˰	float moy7;//ʵ������};   struct zhigong zggz[100];  //������¼ְ�����������100��Ԭ���Ľṹ������	int n=-1;  //�������˸�����ȫ�ֱ���nvoid main(){	char ch;	while(TRUE)	{	system( "cls" ); //����	cout<<"1.��ȡְ���������ݣ�"<<endl;	cout<<"2.����ְ���������ݣ�"<<endl;	cout<<"3.��ѯְ���������ݣ�"<<endl;	cout<<"4.���ְ���������ݣ�"<<endl;	cout<<"5.�޸�ְ���������ݣ�"<<endl;	cout<<"6.ɾ��ְ���������ݣ�"<<endl;	cout<<"7.���ְ���������ݣ�"<<endl;	cout<<"8.�����������˰��"<<endl;	cout<<"���ѡ���ǣ�"<<endl;	ch=getche();	switch(ch)	  {    	case '1':write();break;		case '2':find();break;		case '3':list();break;		case '4':modify();break;		case '5':del();break;		case '6':add();break;		case '7':return;	  }	}	return;}/*********��ȡְ����������**********///�������ļ�gx.dat�ж�ȡְ���������ݵ��ṹ����zggz��void read(){	FILE *file;  //�����ļ�ָ��	if((file=fopen("gz.dat","rb"))==NULL)//rb�Զ����Ʒ�ʽ��ְ�����������ļ��������ж��Ƿ�ʧ��	{		cout<<"�ļ��޷��򿪣���Ϊ��\n";		cout<<"��������������˵�\n";		getch();		return;	}	else  //�ļ��򿪳ɹ�ʱ	{		n++;		while(fread(&zggz[n],sizeof(zggz[n]),1,file)==1)		{			n++;		}		fclose(file);		cout<<"ְ���������ݶ�ȡ��ϣ�����"<<n<<"��\n";		n--;  // ����ְ����¼����	}/**********����ְ����������**************/void write(){	FILE *file;  //�����ļ�ָ��	if(n=-1)   //ְ����Ϊ0	{		cout<<"û�����ݿɴ棬�뷵�����˵�\n";		getch();		return;	}	if((file=fopen("gz.dat","wb"))!=NULL)//��ְ�����������ļ�		fwrite(&zggz[0],sizeof(zggz[0]),n+1,file);  //���м�¼һ��д���ļ�	fclose(file);	cout<<n+1<<"����¼�������!\n";	else   //���ļ��򿪲��ɹ�	{		cout<<"�޷���ְ�������ļ���\n";	}	cout<<"��������������˵�\n";		getch();}