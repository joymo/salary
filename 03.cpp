
#include <stdlib.h>#include <conio.h>//����getch()��getche()
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
//���������
struct zhigong   //�����ṹ��
{	char gonghao[10];  //����	
char name[10];//����	
float moy1;//��λ����	
float moy2;//н������	
float moy3;//ְ�����	
float moy4;//��Ч����	
float moy5;//Ӧ������	
float moy6;//��������˰	
float moy7;//ʵ������
};   
struct zhigong zggz[100];  //������¼ְ�����������100��Ԭ���Ľṹ������	
int n=-1;  //�������˸�����ȫ�ֱ���
nvoid main()
{	char ch;	
while(TRUE)	{	
	system( "cls" ); //����	
	cout<<"1.��ȡְ���������ݣ�"<<endl;	
	cout<<"2.����ְ���������ݣ�"<<endl;	
	cout<<"3.��ѯְ���������ݣ�"<<endl;	
	cout<<"4.���ְ���������ݣ�"<<endl;	
	cout<<"5.�޸�ְ���������ݣ�"<<endl;	
	cout<<"6.ɾ��ְ���������ݣ�"<<endl;	
	cout<<"7.���ְ���������ݣ�"<<endl;	
	cout<<"8.�����������˰��"<<endl;	
	cout<<"���ѡ���ǣ�"<<endl;	
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



/*********��ȡְ����������**********/
//�������ļ�gx.dat�ж�ȡְ���������ݵ��ṹ����zggz��

void read(){	FILE *file;  //�����ļ�ָ��	
if((file=fopen("gz.dat","rb"))==NULL)//rb�Զ����Ʒ�ʽ��ְ�����������ļ��������ж��Ƿ�ʧ��	
{		cout<<"�ļ��޷��򿪣���Ϊ��\n";	
        cout<<"��������������˵�\n";	
		getch();		
		return;	
}	else  //�ļ��򿪳ɹ�ʱ
{		n++;		
        while(fread(&zggz[n],sizeof(zggz[n]),1,file)==1)	
		{			
			n++;	
		}		
		fclose(file);		
		cout<<"ְ���������ݶ�ȡ��ϣ�����"<<n<<"��\n";		n--;  // ����ְ����¼����
}

/**********����ְ����������**************/

void write()
{	
	FILE *file;  //�����ļ�ָ��	
if(n=-1)   //ְ����Ϊ0	
{		cout<<"û�����ݿɴ棬�뷵�����˵�\n";		
        getch();		
		return;	
}	
if((file=fopen("gz.dat","wb"))!=NULL)//��ְ�����������ļ�		
	fwrite(&zggz[0],sizeof(zggz[0]),n+1,file);  //���м�¼һ��д���ļ�	
fclose(file);	cout<<n+1<<"����¼�������!\n";	
else   //���ļ��򿪲��ɹ�	
{		
	cout<<"�޷���ְ�������ļ���\n";	
}	cout<<"��������������˵�\n";		
getch();
}



/**********��ѯְ����������**************/

void find()
{
	char gh[10];
	int i;

	if (n==-1)
	{
		cout<<"���ڻ�û�й��ʼ�¼"<<endl;
		getch();
		return;
	}
	cout<<"������ְ�����"<<endl;
	gets(ch);   //�Ӽ������빤��

	for(n=0;i<=n;i++)
	{
		if(strcmp(zggz[i].gonghao,gh)==0)
		{
			cout<<"��ְ���Ĺ������Ϊ��"<<endl;
			cout<<"��λ����:"<<zggz[i].moy1<<endl;
			cout<<"н�����ʣ�"<<zggz[i].moy2<<endl;
			cout<<"ְ�������"<<zggz[i].moy3<<endl;
			cout<<"��Ч���ʣ�"<<zggz[i].moy4<<endl;
			cout<<"Ӧ�����ʣ�"<<zggz[i].moy5<<endl;
			cout<<"��������˰��"<<zggz[i].moy6<<endl;
			cout<<"ʵ�����ʣ�"<<zggz[i].moy7<<endl;
			cout<<"��������������˵�\n";
			getch();
			return;
		}
	}
	if(i==n+1)
	{
		cout<<"�������ְ����������򲻴���"<<endl;
		cout<<"��������������˵�\n";
		getch();
		return;
	}
}


/**********���ְ����������**************/





/**********�޸�ְ����������**************/

void modify()
{
	char gh[10];  //����ְ������
	int i;    //ѭ�����Ʊ���
	if(n==-1)
	{
		printf("\n\n\t\tû��ְ�����ʼ�¼����������������˵�\n")
		getch();
		return;
	}
		printf("������ְ�����");
		gets(ch);   //�Ӽ������빤��
}
for(n=0;i<=n;i++)
	{
		if(strcmp(zggz[i].gonghao,gh)==0)   //��ʾְ���������
		{
			printf("��ְ���Ĺ������Ϊ��");
			printf("\t%s\t%s\t%s\t%s\t%s","ְ������","ְ������","��λ����","н������","ְ�����");
			printf("\t%s\t%s\t%s\t%s","��Ч����","Ӧ������","��������˰","ʵ������");

			printf("\t%s\t%s\t%.2f\t%.2f\t%.2f",zggz[i].gonghao,zggz[i].name,zggz[i].moy1,zggz[i].moy2,zggz[i].moy3);
			printf("\t%.2f\t%.2f\t%.2f\t%.2f",zggz[i].moy4,zggz[i].moy5,zggz[i].moy6,zggz[i].moy7); 

			//�����µĹ�������
			printf("\n\t\t�������ְ���µĸ�λ����");
			fflush(stdin);
			scanf("%f",&zggz[i].moy1);

			printf("\n\t\t�������ְ���µ�н������");
			fflush(stdin);
			scanf("%f",&zggz[i].moy2);
			
			printf("\n\t\t�������ְ���µ�ְ�����");
			fflush(stdin);
			scanf("%f",&zggz[i].moy3);

			printf("\n\t\t�������ְ���µļ�Ч����");
			fflush(stdin);
			scanf("%f",&zggz[i].moy4);

//����Ӧ�����ʣ���������˰��ʵ������
//Ӧ��=��λ+н��+ְ��+��Ч
			zggz[i].moy5=zggz[i].moy1+zggz[i].moy2+zggz[i].moy3+zggz[i].moy4;
				
//�����������˰
			zggz[i].moy6=moy6(zggz[i].moy1);
//����ʵ������=Ӧ��-��������˰
			zggz[i].moy7=zggz[i].moy5-zggz[i].moy6;

			printf("\n\n\t\t��ְ����Ӧ������Ϊ��%.2f",zgga[i].moy5);
			printf("\n\n\t\t��ְ���ĸ�������˰Ϊ��%.2f",zgga[i].moy6);
			printf("\n\n\t\t��ְ����ʵ������Ϊ��%.2f",zgga[i].moy7);

			printf("\n\n\t\t��ְ�����������޸ĳɹ�����������������˵�");

			getch();
			return;
		}
	}
     printf("\n\t\t���������ְ����������򲻴���")��		
	 printf("��������������˵�");
	 getch();
	 return;
}



/**********ɾ��ְ����������**************/


void del()
{
	char gh[10];  //����ְ�������ַ�����
	int i,j;  //ѭ�����Ʊ���
	char d;   //����ȷ��ɾ���ַ�

	printf("�������ɾ����ְ������");
	gets(gh);
	for(i=0;i<=n;i++)   //��ְ�����鷶Χ��ѭ��
	{

	}
}