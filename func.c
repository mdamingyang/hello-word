#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"data.h"
void readdata1(TEXT info[],int *pn)//�Ӽ��̶�ȡ����
{
	int i,b=1;
   for(i=0;b!=0;i++)
   {
		printf("������");
		scanf("%s",&info[i].name);
		printf("���᣺");
		scanf("%s",&info[i].nat);
		printf("�绰����1:");
		scanf("%s",&info[i].tel1);
		printf("�绰����2��");
		scanf("%s",&info[i].tel2);
		printf("�������䣺");
		scanf("%s",&info[i].mail);
		printf("\n");
		printf("���������밴1,�˳��밴0\n");
		scanf("%d",&b);
   }
   *pn=i;
   printf("��¼��%d�ˡ�\n\n",*pn);
}
void readdata2(TEXT info[],int *pn)//���ļ���ȡ����
{
	FILE *fp;
	int i;
	if((fp=fopen("C:\\address list.txt","r"))==NULL)		//���ļ�
	{
		printf("Failure to open address list.txt!\n");
		exit(0);
	}
	for(i=0;!feof(fp);i++)					//��ȡ�ļ�
	{
		fscanf(fp,"%s%s%s%s%s",&info[i].name,&info[i].nat,&info[i].tel1,&info[i].tel2,&info[i].mail);
	}
	fclose(fp);			//�ر��ļ�
	*pn=i;
	printf("�ļ�����ɹ�������%d�ˡ�\n\n",*pn);
}
void putdata(TEXT info[],int n)						//�������
{
	int i;
	printf("����\t����\t�绰1\t\t�绰2\t\t����\n");
	for(i=0;i<n;i++)					
	{
		printf("%s\t%s\t%s\t%s\t%s\n",info[i].name,info[i].nat,info[i].tel1,info[i].tel2,info[i].mail);
	}
	printf("\n");
}
void serchdata(TEXT info[],int n)				//����������
{
	int i;
	char name[100];
	printf("�������ѯ��ϵ��������");
	scanf("%s",name);
	for(i=0;i<n;i++)
	{
		if(!strcmp(name,info[i].name))			//�ַ����Ƚ�
		{
			printf("����\t����\t�绰1\t�绰2\t����\n");			//������ӡ����
			printf("%s\t%s\t%s\t%s\t%s\n\n",info[i].name,info[i].nat,info[i].tel1,info[i].tel2,info[i].mail);
			break;
		}
	}
	if(i==n)
		printf("δ�ҵ�����ϵ��\n");
}
void adddata(TEXT info[],int *pn)				//�������
{
	int i;
	printf("�����������ϵ����Ϣ��\n");
	i=*pn;
		printf("������");
		scanf("%s",&info[i].name);
		printf("���᣺");
		scanf("%s",&info[i].nat);
		printf("�绰����1:");
		scanf("%s",&info[i].tel1);
		printf("�绰����2��");
		scanf("%s",&info[i].tel2);
		printf("�������䣺");
		scanf("%s",&info[i].mail);
		printf("\n");
	(*pn)++;								//��������1
	printf("��ӳɹ�\n");
}
void deledata(TEXT info[],int *pn)				//ɾ������
{
	int i,n;
	char name[100];
	printf("������Ҫɾ����ϵ��������");
	scanf("%s",name);
	n=*pn;
	for(i=0;i<n;i++)
	{
		if(!strcmp(name,info[i].name))
			break;
	}
	if(i<n)
	{
		for(;i<n-1;i++)
			info[i]=info[i+1];					//��i+1���滻i��
		*pn=*pn-1;								//��������1
		printf("ɾ���ɹ�!\n");
	}
	else
		printf("δ�ҵ�����ϵ��\n");
}
void replacedata(TEXT info[],int n)				//�滻����
{
	int i;
	char name[100];
	printf("������Ҫ�滻��ϵ��������");
	scanf("%s",name);
	for(i=0;i<n;i++)
	{
		if(!strcmp(name,info[i].name))
		{
			printf("����\t����\t�绰1\t\t�绰2\t\t����\n");
			printf("%s\t%s\t%s\t%s\t%s\n",info[i].name,info[i].nat,info[i].tel1,info[i].tel2,info[i].mail);
			printf("�ҵ�����ϵ�ˣ�����������ϵ����Ϣ��\n");
			printf("������");
			scanf("%s",&info[i].name);
			printf("���᣺");
			scanf("%s",&info[i].nat);
			printf("�绰����1:");
			scanf("%s",&info[i].tel1);
			printf("�绰����2��");
			scanf("%s",&info[i].tel2);
			printf("�������䣺");
			scanf("%s",&info[i].mail);
			printf("\n�滻�ɹ���\n");
			break;
		}
	}
	if(i==n)
		printf("δ�ҵ�����ϵ��!\n");
}
void savedata(TEXT info[],int n)			//�����ļ�
{
	FILE *fp;
	int i;
	if((fp=fopen("C:\\address list.txt","w"))==NULL)			//���ļ�
	{
		printf("Faillure to open address list.txt!\n");
		exit(0);
	}
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%s\t%s\t%s\t%s\t%s",info[i].name,info[i].nat,info[i].tel1,info[i].tel2,info[i].mail);		
		if(i<n-1)
			fprintf(fp,"\n");
	}
		fclose(fp);
}
void sort(TEXT info[],int n)				//����
{
	int i,j;
	TEXT *p=info,t;
	p=info;
	for(i=0;i<n-1;i++)						//ð������
	{
		for(j=0;j<n-i-1;j++)
		if(strcmp((p+j)->name,(p+j+1)->name)>0)
		{
			t=*(p+j);
			*(p+j)=*(p+j+1);
			*(p+j+1)=t;
		}
	}
}