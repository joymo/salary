#include <stdlib.h>
#include <conio.h>//����getch()��getche()
#include<stdio.h>
#include<string.h>
#define TRUE 1

//���������
void read();
void write();
void find();
void list();
void modify();
void del();
void add();
float grsds(float m);

struct zhigong   //�����ṹ��
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
};   
struct zhigong zggz[100];  //������¼ְ�����������100��Ԫ�صĽṹ������	
int n=-1;  //����ͳ�ƹ��˸�����ȫ�ֱ���

void main()
{	char ch;	
while(TRUE)
{	
	system( "cls" ); //����	
	printf("\t\t ��ѡ��1~7:\n"); 

	printf("\t\t\t 1.��ѯְ���������ݣ�\n");
	printf("\t\t\t 2.�޸�ְ���������ݣ�\n");
	printf("\t\t\t 3.���ְ���������ݣ�\n");
	printf("\t\t\t 4.ɾ��ְ���������ݣ�\n");
	printf("\t\t\t 5.����ְ���������ݣ�\n");
	printf("\t\t\t 6.���ְ���������ݣ�\n");
	printf("\t\t\t 7.�˳�ϵͳ\n");

	printf("\t\t���ѡ���ǣ�");
	ch=getche();	
	switch(ch)	
	{    	case '1':find();break;		
	        case '2':modify();break;		
			case '3':add();break;	
			case '4':del();break;	
			case '5':write();break;	
			case '6':list();break;	
			case '7':return;
			
			default:printf("\t\t�밴��������ش���ѡ��1-3��\n");
				getch();
	}
}	
     return;
}



/*********.��ȡְ����������**********/
//�������ļ�gz.dat�ж�ȡְ���������ݵ��ṹ����zggz��

void read()
{	
	FILE *fp;  //�����ļ�ָ��	
	if((fp=fopen("gz.dat","rb"))==NULL)//rb"ֻ��"�Զ����Ʒ�ʽ��ְ�����������ļ��������ж��Ƿ�ʧ��	
	{
		printf("\n\n\t\t ְ�����������ļ��޷��򿪣��򲻴��ڣ�");
		printf("\n\t\t ��������������˵���");
		getch();		
		return;	
	}	
	else  //�ļ��򿪳ɹ�ʱ
	{		n++;		
        while(fread(&zggz[n],sizeof(zggz[n]),1,fp)==1)	
		{			
			n++;	
		}		
		fclose(fp);
		printf("\n\n\t\t ְ���������ݶ�ȡ��ϣ�����%d�ˣ�\n",n); // ����ְ����¼����
		n--;   //����ְ����¼����
	}
}
/**********.����ְ����������**************/

void write()
{	
	FILE *file;  //�����ļ�ָ��	
	if(n=-1)   //ְ����Ϊ0	
	{	
		printf("\t û�����ݿɴ棬�밴������������˵���\n");		
        getch();		
		return;	
	}	
	if((file=fopen("gz.dat","wb"))!=NULL)  //"wb"����д����ְ�����������ļ�
	{
		fwrite(&zggz[0],sizeof(zggz[0]),n+1,file);  //���м�¼һ��д���ļ�	
		fclose(file);
		printf("\n\n\t\t\t %d ��ְ����¼������ϣ�\n",n+1);

	}
	else   //���ļ��򿪲��ɹ�	
	{		
		printf("\t\t\t�޷���ְ�������ļ���\n");	
	}
	
	printf("\n\t\t\t ��������������˵���");
	getch();
}



/**********.��ѯְ����������**************/

void find()
{
	char gh[10];
	int i;

	if (n==-1)
	{
		printf("\n\n\t\t���ڻ�û�й��ʼ�¼,��������������˵���\n");
		getch();
		return;
	}
	printf("������ְ�����:");
	gets(gh);   //�Ӽ������빤��

	for(n=0;i<=n;i++)
	{
		if(strcmp(zggz[i].gonghao,gh)==0)
		{
			printf("\n\\t\t ��ְ������������£�\n");

			printf("\t%s\t%s\t%s\t%s\t%s","ְ������","ְ������","��λ����","н������","ְ�����");
			printf("\t%s\t%s\t%s\t%s","��Ч����","Ӧ������","��������˰","ʵ������");

			printf("\t%s\t%s\t%.2f\t%.2f\t%.2f",zggz[i].gonghao,zggz[i].name,zggz[i].moy1,zggz[i].moy2,zggz[i].moy3);
			printf("\t%.2f\t%.2f\t%.2f\t%.2f",zggz[i].moy4,zggz[i].moy5,zggz[i].moy6,zggz[i].moy7); 

			printf("\n\t ��������������˵���\n");
			getch();
			return;
		}
	}
	if(i==n+1)
	{
		printf("\n\t\t\t�������ְ����������򲻴���\n");
		printf("\n\t��������������˵�\n");
		getch();
		return;
	}
}


/**********.���ְ����������**************/

void list()
{
	int i;
	system("cls");
	printf("\n\n\t\t\t\t ȫ��ְ������������£�\n");
	printf("\t%s\t%s\t%s\t%s\t%s","ְ������","ְ������","��λ����","н������","ְ�����");
	printf("\t%s\t%s\t%s\t%s","��Ч����","Ӧ������","��������˰","ʵ������");

	for(i=0;i<=n;i++)   //��ְ����Χ��ѭ�����
	{
		printf("\t%s\t%s\t%.2f\t%.2f\t%.2f",zggz[i].gonghao,zggz[i].name,zggz[i].moy1,zggz[i].moy2,zggz[i].moy3);
		printf("\t%.2f\t%.2f\t%.2f\t%.2f",zggz[i].moy4,zggz[i].moy5,zggz[i].moy6,zggz[i].moy7); 
	}
	printf("\n\t ��������������˵� ");
	getch();
	return;
}



/**********.�޸�ְ����������**************/

void modify()
{
	char gh[10];  //����ְ������
	int i;    //ѭ�����Ʊ���
	if(n==-1)
	{
		printf("\n\n\t\tû��ְ�����ʼ�¼����������������˵�\n");
		getch();
		return;
	}
		printf("������ְ�����");
		gets(gh);   //�Ӽ������빤��

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
			zggz[i].moy6=grsds(zggz[i].moy5);
//����ʵ������=Ӧ��-��������˰
			zggz[i].moy7=zggz[i].moy5-zggz[i].moy6;

//���������
			printf("\n\n\t\t��ְ����Ӧ������Ϊ��%.2f",zggz[i].moy5);
			printf("\n\n\t\t��ְ���ĸ�������˰Ϊ��%.2f",zggz[i].moy6);
			printf("\n\n\t\t��ְ����ʵ������Ϊ��%.2f",zggz[i].moy7);

			printf("\n\n\t\t��ְ�����������޸ĳɹ�����������������˵�");

			getch();
			return;
		}
	}
     printf("\n\t\t���������ְ����������򲻴���");		
	 printf("��������������˵�");
	 getch();
	 return;
}



/**********.ɾ��ְ����������**************/


void del()
{
	char gh[10];  //����ְ�������ַ�����
	int i,j;  //ѭ�����Ʊ���
	char d;   //����ȷ��ɾ���ַ�

	printf("�������ɾ����ְ������");
	gets(gh);
	for(i=0;i<=n;i++)   //��ְ�����鷶Χ��ѭ������
	{	
		if(strcmp(zggz[i].gonghao,gh)==0)  //���бȽ�ƥ��
		{
			printf("\n\t\t\t ��ȷ��Ҫɾ�� %s ��ְ������Ϣ��(y}(��)\n(��))",zggz[i].gonghao);
			d=getche();
			if(d=='y'||d=='Y')    //ȷ��ɾ��
			{
				if(i==n)   //�����һ����¼
					n--;
				else       //�������һ����¼
				{
					for(j=0;j<=n;i++)    //�Ӽ�¼��ʼ������¼����ǰһ����¼
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
			printf("\n\n\t\t\t �ɹ�ɾ����ְ�����ʼ�¼,��������������˵�");
			getch();
			break;
		}
		else       //����ɾ����ְ����¼
		{
			printf("\n\n ��ѡ��ɾ����ְ�����ʼ�¼����������������˵�");
			getch();
			return;
		}
}
	}
if(i==n+1)    //δ�ҵ���δɾ����¼
{
	printf("\n\t\t\t�Ҳ����ʹ��ţ�����������أ�");
	getch();
}
}


/*************.���ְ����������*******************/

void add()
{
	printf("\n\t\t\t�������ְ�����ţ�");
	fflush(stdin);   //���������
	scanf("%f",&zggz[++n].gonghao);

	printf("\n\t\t\t �������ְ���ĸ�λ����");
	fflush(stdin);     //���������
	scanf("%f",&zggz[n].moy1);

	printf("\n\t\t\t �������ְ����н������");
	fflush(stdin);     //���������
	scanf("%f",&zggz[n].moy2);

	printf("\n\t\t\t �������ְ����ְ�����");
	fflush(stdin);     //���������
	scanf("%f",&zggz[n].moy3);

	printf("\n\t\t\t �������ְ���ļ�Ч����");
	fflush(stdin);     //���������
	scanf("%f",&zggz[n].moy4);

//����Ӧ�����ʣ���������˰��ʵ������
//Ӧ��=��λ+н��+ְ��+��Ч
			zggz[n].moy5=zggz[n].moy1+zggz[n].moy2+zggz[n].moy3+zggz[n].moy4;
				
//�����������˰
			zggz[n].moy6=grsds(zggz[n].moy1);
//����ʵ������=Ӧ��-��������˰
			zggz[n].moy7=zggz[n].moy5-zggz[n].moy6;

//���������
			printf("\n\n\t\t\t��ְ����Ӧ������Ϊ��%.2f",zggz[n].moy5);
			printf("\n\t\t\t��ְ���ĸ�������˰Ϊ��%.2f",zggz[n].moy6);
			printf("\n\t\t\t��ְ����ʵ������Ϊ��%.2f",zggz[n].moy7);

			printf("\n\n\t\t\t��Ӹ�ְ���������ݳɹ�����������������˵�");
			getch();
}



/*************.�����������˰*******************/

float grsds(float m) 
{
	float x;        //����Ӧ��˰���ö�
	float y=0;      //����Ӧ��˰��
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