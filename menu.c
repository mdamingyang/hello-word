#include<stdio.h>
//打印菜单函数
void mainmenu()
{
	printf("     实用的小型通讯录程序\n");
	printf("  ***************************\n");
	printf("  *       1.信息录入.       *\n"
		   "  *       2.信息浏览.       *\n"
		   "  *       3.信息查询.       *\n"
		   "  *       4.信息修改.       *\n"
		   "  *       5.退出系统.       *\n"
		   "  ***************************\n");
	printf("请输入序号选择：");
}
void submenu1()
{
	printf("           信息录入\n");
	printf("  ***************************\n"
		   "  *      1.从键盘录入       *\n"
		   "  *      2.从文件导入       *\n"
		   "  ***************************\n");
	printf("请输入序号选择：");
}
void submenu2()
{
	printf("           信息浏览\n");
	printf("  ***************************\n");
}
void submenu3()
{
	printf("           信息查询\n");
	printf("  ***************************\n");
}
void submenu4()
{
	printf("           信息修改\n");
	printf("  ***************************\n"
		   "  *      1.添加             *\n"
		   "  *      2.删除             *\n"
		   "  *      3.替换             *\n"
		   "  ***************************\n");
	printf("请输入序号选择：");
}