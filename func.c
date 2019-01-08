#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"data.h"
void readdata1(TEXT info[],int *pn)//从键盘读取数据
{
	int i,b=1;
   for(i=0;b!=0;i++)
   {
		printf("姓名：");
		scanf("%s",&info[i].name);
		printf("籍贯：");
		scanf("%s",&info[i].nat);
		printf("电话号码1:");
		scanf("%s",&info[i].tel1);
		printf("电话号码2：");
		scanf("%s",&info[i].tel2);
		printf("电子邮箱：");
		scanf("%s",&info[i].mail);
		printf("\n");
		printf("继续输入请按1,退出请按0\n");
		scanf("%d",&b);
   }
   *pn=i;
   printf("共录入%d人。\n\n",*pn);
}
void readdata2(TEXT info[],int *pn)//从文件读取数据
{
	FILE *fp;
	int i;
	if((fp=fopen("C:\\address list.txt","r"))==NULL)		//打开文件
	{
		printf("Failure to open address list.txt!\n");
		exit(0);
	}
	for(i=0;!feof(fp);i++)					//读取文件
	{
		fscanf(fp,"%s%s%s%s%s",&info[i].name,&info[i].nat,&info[i].tel1,&info[i].tel2,&info[i].mail);
	}
	fclose(fp);			//关闭文件
	*pn=i;
	printf("文件导入成功！共有%d人。\n\n",*pn);
}
void putdata(TEXT info[],int n)						//输出数据
{
	int i;
	printf("姓名\t籍贯\t电话1\t\t电话2\t\t邮箱\n");
	for(i=0;i<n;i++)					
	{
		printf("%s\t%s\t%s\t%s\t%s\n",info[i].name,info[i].nat,info[i].tel1,info[i].tel2,info[i].mail);
	}
	printf("\n");
}
void serchdata(TEXT info[],int n)				//按姓名查找
{
	int i;
	char name[100];
	printf("请输入查询联系人姓名：");
	scanf("%s",name);
	for(i=0;i<n;i++)
	{
		if(!strcmp(name,info[i].name))			//字符串比较
		{
			printf("姓名\t籍贯\t电话1\t电话2\t邮箱\n");			//相等则打印数据
			printf("%s\t%s\t%s\t%s\t%s\n\n",info[i].name,info[i].nat,info[i].tel1,info[i].tel2,info[i].mail);
			break;
		}
	}
	if(i==n)
		printf("未找到该联系人\n");
}
void adddata(TEXT info[],int *pn)				//添加数据
{
	int i;
	printf("请输入添加联系人信息：\n");
	i=*pn;
		printf("姓名：");
		scanf("%s",&info[i].name);
		printf("籍贯：");
		scanf("%s",&info[i].nat);
		printf("电话号码1:");
		scanf("%s",&info[i].tel1);
		printf("电话号码2：");
		scanf("%s",&info[i].tel2);
		printf("电子邮箱：");
		scanf("%s",&info[i].mail);
		printf("\n");
	(*pn)++;								//总人数加1
	printf("添加成功\n");
}
void deledata(TEXT info[],int *pn)				//删除数据
{
	int i,n;
	char name[100];
	printf("请输入要删除联系人姓名：");
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
			info[i]=info[i+1];					//用i+1项替换i项
		*pn=*pn-1;								//总人数减1
		printf("删除成功!\n");
	}
	else
		printf("未找到该联系人\n");
}
void replacedata(TEXT info[],int n)				//替换数据
{
	int i;
	char name[100];
	printf("请输入要替换联系人姓名：");
	scanf("%s",name);
	for(i=0;i<n;i++)
	{
		if(!strcmp(name,info[i].name))
		{
			printf("姓名\t籍贯\t电话1\t\t电话2\t\t邮箱\n");
			printf("%s\t%s\t%s\t%s\t%s\n",info[i].name,info[i].nat,info[i].tel1,info[i].tel2,info[i].mail);
			printf("找到该联系人，请输入新联系人信息。\n");
			printf("姓名：");
			scanf("%s",&info[i].name);
			printf("籍贯：");
			scanf("%s",&info[i].nat);
			printf("电话号码1:");
			scanf("%s",&info[i].tel1);
			printf("电话号码2：");
			scanf("%s",&info[i].tel2);
			printf("电子邮箱：");
			scanf("%s",&info[i].mail);
			printf("\n替换成功！\n");
			break;
		}
	}
	if(i==n)
		printf("未找到该联系人!\n");
}
void savedata(TEXT info[],int n)			//保存文件
{
	FILE *fp;
	int i;
	if((fp=fopen("C:\\address list.txt","w"))==NULL)			//打开文件
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
void sort(TEXT info[],int n)				//排序
{
	int i,j;
	TEXT *p=info,t;
	p=info;
	for(i=0;i<n-1;i++)						//冒泡排序
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