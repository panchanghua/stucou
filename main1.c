#include"./include/stucou.h"
#include"./modulea/stu.h"
#include"./moduleb/cou.h"
void nowtime(void)			//当前系统时间
{    	
	time_t now ;

        struct tm *tm_now ;

        time(&now) ;

        tm_now = localtime(&now) ;

        printf("time: %d-%d-%d %d:%d:%d\n",tm_now->tm_year+1900, tm_now->tm_mon+1, tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec) ;
}
void outputcou(void)		//输出课程信息表
{
	int i=0;
	printf("                    %s %s %s %s %s %s %s\n",course[0],course[1],course[2],course[3],course[4],course[5],course[6]);
	for(i=0;i<n2;i++)
		printf("                    %s %13s %11s %7d %10.1f %4d %13d\n",cou[i].couid,cou[i].couname,cou[i].counature,cou[i].hour,cou[i].credit,cou[i].chosen,cou[i].max);
}
void outputstu(void)		//输出学生信息表
{
	int i=0;
	printf("                    %s  %s  %s    %s\n",student[0],student[1],student[2],student[3]);
	for(i=0;i<n1;i++)
		printf("                    %s  %s  %-12s    %.1f\n",stu[i].stuid,stu[i].name,stu[i].select,stu[i].credit);
}
void rtitleinput(void)			//读入行标题
{
	FILE *fp;
	if((fp=fopen("rtitle.txt","r+"))==NULL)
	{
		printf("open student.txt error!\n");
		return;
	}
	fscanf(fp,"%s%s%s%s",student[0],student[1],student[2],student[3]);
	fscanf(fp,"%s%s%s%s%s%s%s",course[0],course[1],course[2],course[3],course[4],course[5],course[6]);
	fclose(fp);
}
void keyboardinput(void)		//从键盘输入数据
{
	int i=0;
	printf("输入要输入的学生个数:");
	scanf("%d",&n1);
	printf("请输入依次%s %s %s %s\n",student[0],student[1],student[2],student[3]);
	for(i=0;i<n1;i++)
		scanf("%s%s%s%f",stu[i].stuid,stu[i].name,stu[i].select,&stu[i].credit);
	printf("输入要输入的课程个数:");
	scanf("%d",&n2);
	printf("请输入依次%s %s %s %s %s %s %s\n",course[0],course[1],course[2],course[3],course[4],course[5],course[6]);
	for(i=0;i<n2;i++)
		scanf("%s%s%s%d%f%d%d",cou[i].couid,cou[i].couname,cou[i].counature,&cou[i].hour,&cou[i].credit,&cou[i].chosen,&cou[i].max);	
}
int menu(void)				//菜单
{
	int x=0;
	a:
	system("clear");
	printf("                    *******************************************************\n");
	printf("                    *******************************************************\n");
	printf("                    **                                                   **\n");
	printf("                    **           学  生  选  课  管  理  系  统          **\n");
	printf("                    **                                                   **\n");
	printf("                    **              1.学生信息管理                       **\n");
	printf("                    **              2.课程信息管理                       **\n");
	printf("                    **              3.退出                               **\n");
	printf("                    **                                                   **\n");
	printf("                    *******************************************************\n");
	printf("                    *******************************************************\n");
	printf("                    请按照提示输入:");
	scanf("%d",&x);
	while(x!=1&&x!=2&&x!=3)
		{
			printf("                    输入错误!\n                    请重新输入:");
			scanf("%d",&x);
		}
	if(x==1)
		goto b;
	else if(x==2)
		goto c;
	else
		return 0;
	b:
	system("clear");
	printf("                    *******************************************************\n");
	printf("                    *******************************************************\n");
	printf("                    **                                                   **\n");
	printf("                    **           学   生   信   息   管   理             **\n");
	printf("                    **                                                   **\n");
	printf("                    **              1.新增学生信息                       **\n");
	printf("                    **              2.修改学生信息                       **\n");
	printf("                    **              3.删除学生信息                       **\n");
	printf("                    **              4.查看学生信息                       **\n");
	printf("                    **              5.退出                               **\n");
	printf("                    **                                                   **\n");
	printf("                    *******************************************************\n");
	printf("                    *******************************************************\n");
	printf("                    请按照提示输入:");
	scanf("%d",&x);
	while(x>5&&x<1)
		{
			printf("                    输入错误!\n                    请重新输入:");
			scanf("%d",&x);
		}
	if(x==1)
		{
			addstuinfo();
			goto b;
		}
	else if(x==2)
		{
			modstuinfo();
			goto b;
		}
	else if(x==3)
		{
			delstuinfo();
			goto b;
		}
	else if(x==4)
		{	
			seestuinfo();
			goto b;
		}
	else
		goto a;
	c:
	system("clear");
	printf("                    *******************************************************\n");
	printf("                    *******************************************************\n");
	printf("                    **                                                   **\n");
	printf("                    **           课   程   信    息   管   理            **\n");
	printf("                    **                                                   **\n");
	printf("                    **              1.新增课程                           **\n");
	printf("                    **              2.删除课程                           **\n");
	printf("                    **              3.查看课程详细信息                   **\n");
	printf("                    **              4.修改课程信息                       **\n");
	printf("                    **              5.退出                               **\n");
	printf("                    **                                                   **\n");
	printf("                    *******************************************************\n");
	printf("                    *******************************************************\n");
	printf("                    请按照提示输入:");
	scanf("%d",&x);
	while(x>5&&x<1)
		{
			printf("                    输入错误!\n                    请重新输入:");
			scanf("%d",&x);
		}
	if(x==1)
		{
			addcou();
			goto c;
		}
	else if(x==2)
		{	
			delcou();
			goto c;
		}
	else if(x==3)
		{
			seecouinfo();
			goto c;
		}
	else if(x==4)
		{
			modcouinfo();
			goto c;
		}
	else
		goto a;
}
void main()
{
	int flag=0,x=0;
	rtitleinput();
	keyboardinput();
	printf("是否进入学生选课管理菜单(输入1进入否则退出):");
	scanf("%d",&x);
	if(x==1)
		menu();
	else
		return;
}
