#include <stdlib.h>
#include <conio.h>//����getch()��getche()
#include<stdio.h>
#include<string.h>
#include<windows.h>
#define TRUE 1
//���������
void write();
void find();
void list();
void modify();
void del();
void add();
float grsds(float m);

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
void main()
{	char ch;	
while(TRUE)	{	
	system( "cls" ); //����	
	printf("\t\t��ѡ��1~7:\n");
	printf("\t\t1.����ְ���������ݣ�\n");
	printf("\t\t2.��ѯְ���������ݣ�\n");
	printf("\t\t3.���ְ���������ݣ�\n");
	printf("\t\t4.�޸�ְ���������ݣ�\n");
	printf("\t\t5.ɾ��ְ���������ݣ�\n");
	printf("\t\t6.���ְ���������ݣ�\n");
	printf("\t\t\n7.�˳�ϵͳ��");
	printf("\t\t\n����ѡ���ǣ�");
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



/*********1.��ȡְ����������**********/
//�������ļ�gx.dat�ж�ȡְ���������ݵ��ṹ����zggz��

void read(){	
	FILE *file;  //�����ļ�ָ��	
	if((file=fopen("gz.dat","rb"))==NULL)//rb�Զ����Ʒ�ʽ��ְ�����������ļ��������ж��Ƿ�ʧ��	
	{	printf("")	
		cout<<"�ļ��޷��򿪣���Ϊ��\n";	
        cout<<"��������������˵�\n";	
		getch();		
		return;	
	}	
	else  //�ļ��򿪳ɹ�ʱ
	{		n++;		
        while(fread(&zggz[n],sizeof(zggz[n]),1,file)==1)	
		{			
			n++;	
		}		
		fclose(file);		
		cout<<"ְ���������ݶ�ȡ��ϣ�����"<<n<<"��\n";		n--;  // ����ְ����¼����
	}

/**********2.����ְ����������**************/

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



/**********3.��ѯְ����������**************/

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


/**********4.���ְ����������**************/

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



/**********5.�޸�ְ����������**************/

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

//���������
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



/**********6.ɾ��ְ����������**************/


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
			d=getch();
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
	printf(\n\t\t\t  �Ҳ����ʹ��ţ������������)
	getch();
}
}


/*************7.���ְ����������*******************/

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
			zggz[n].moy6=moy6(zggz[n].moy1);
//����ʵ������=Ӧ��-��������˰
			zggz[n].moy7=zggz[n].moy5-zggz[n].moy6;

//���������
			printf("\n\n\t\t\t��ְ����Ӧ������Ϊ��%.2f",zgga[n].moy5);
			printf("\n\t\t\t��ְ���ĸ�������˰Ϊ��%.2f",zgga[n].moy6);
			printf("\n\t\t\t��ְ����ʵ������Ϊ��%.2f",zgga[n].moy7);

			printf("\n\n\t\t\t��Ӹ�ְ���������ݳɹ�����������������˵�");
			getch();
}



/*************8.�����������˰*******************/

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