#include<stdio.h>
#include<stdlib.h>
#include"data.h"
#include"menu.h"
#include"func.h"
/*������*/
int main()
{	
	int n=0,s,x=1;		        //����������n
	int *pn;             
	TEXT info[N];			   //����ṹ������info,����ͨѶ¼��Ϣ
	pn=&n;				       //ָ��pnָ��n
	while(x)
	{
		mainmenu();		      //��ӡ���˵�
		scanf("%d",&s);
		while(s>6||s<0)	      //����������ж�
		{ 
			printf("����������������룺");
			fflush(stdin);
			scanf("%d",&s);
		}
		switch(s)        //ѡ����
		{
			case 1:submenu1();      //��ӡ�Ӳ˵�1	
				scanf("%d",&s);
				if(s==1)
				{
					readdata1(info,pn);          //�Ӽ��̶�ȡ����
					sort(info,n); break;               //����������
				}
				else if(s==2)
				{
					readdata2(info,pn);         //���ļ���ȡ����
					sort(info,n);break;
				}
				else
					printf("�������\n");break;
			case 2:submenu2();
				putdata(info,n);break;           //�������
			case 3:submenu3();
				serchdata(info,n);break;         //����������
			case 4:submenu4();
			     scanf("%d",&s);
				 if(s==1)
				 {
					 adddata(info,pn);           //�������
				     sort(info,n);
				 }
				 else if(s==2)
				 {
					 deledata(info,pn);           //ɾ������
					 sort(info,n);
				 }
				 else if(s==3)
				 {
					 replacedata(info,n);         //�滻����
				     sort(info,n);
				 }
				 else
					printf("�������!\n"); break;
			case 5:x=0;
				savedata(info,n);                 //�������򲢱����ļ�
				printf("����ɹ������������\n");break;      
		}
	}
	return 0;
}