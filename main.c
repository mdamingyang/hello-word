#include<stdio.h>
#include<stdlib.h>
#include"data.h"
#include"menu.h"
#include"func.h"
/*主函数*/
int main()
{	
	int n=0,s,x=1;		        //定义总人数n
	int *pn;             
	TEXT info[N];			   //定义结构体数组info,储存通讯录信息
	pn=&n;				       //指针pn指向n
	while(x)
	{
		mainmenu();		      //打印主菜单
		scanf("%d",&s);
		while(s>6||s<0)	      //输入错误后的判断
		{ 
			printf("输入错误，请重新输入：");
			fflush(stdin);
			scanf("%d",&s);
		}
		switch(s)        //选择函数
		{
			case 1:submenu1();      //打印子菜单1	
				scanf("%d",&s);
				if(s==1)
				{
					readdata1(info,pn);          //从键盘读取数据
					sort(info,n); break;               //调用排序函数
				}
				else if(s==2)
				{
					readdata2(info,pn);         //从文件读取数据
					sort(info,n);break;
				}
				else
					printf("输入错误！\n");break;
			case 2:submenu2();
				putdata(info,n);break;           //输出数据
			case 3:submenu3();
				serchdata(info,n);break;         //按姓名查找
			case 4:submenu4();
			     scanf("%d",&s);
				 if(s==1)
				 {
					 adddata(info,pn);           //添加数据
				     sort(info,n);
				 }
				 else if(s==2)
				 {
					 deledata(info,pn);           //删除数据
					 sort(info,n);
				 }
				 else if(s==3)
				 {
					 replacedata(info,n);         //替换数据
				     sort(info,n);
				 }
				 else
					printf("输入错误!\n"); break;
			case 5:x=0;
				savedata(info,n);                 //结束程序并保存文件
				printf("保存成功！程序结束。\n");break;      
		}
	}
	return 0;
}