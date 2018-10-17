#include"stu.h"
#include"../include/stucou.h"
#include"../modulea/stu.h"
void addstuinfo()			//添加学生信息
{
	int x=0,i=0,k=0,t=0,j=0;
	char couname[50]={0};
	addstu:
	if((fplog=fopen("log.log","a+"))==NULL)
		printf("write log.log error");
	system("clear");
	printf("                    请输入要增加的学生个数:");
	scanf("%d",&x);
	if(x>0)
		printf("                    请输入依次%s %s %s %s\n",student[0],student[1],student[2],student[3]);
	else
	{
		printf("                    输入错误;\n");
		goto addstu;
	}
	for(i=0;i<x;i++)
	{
		printf("                    ");
		scanf("%s%s%s%f",stu[i+n1].stuid,stu[i+n1].name,stu[i+n1].select,&stu[i+n1].credit);
		nowtime();
		fprintf(fplog,"add stu %s %s %s %f\n",stu[i+n1].stuid,stu[i+n1].name,stu[i+n1].select,stu[i+n1].credit);
		fprintf(fplog,"============================================\n");
		j=0;
		while(stu[i+n1].select[j])
		{
			t=0;
			while(stu[i+n1].select[j]&&stu[i+n1].select[j]!=',')
			{
				couname[t]=stu[i+n1].select[j];
				j++;
				t++;
			}
			couname[t]=0;
			for(k=0;k<n2;k++)
				if(strcmp(couname,cou[k].couid)==0)
					break;
			cou[k].chosen+=1;
			j++;
		}
	}
	fclose(fplog);
	printf("                    是否继续增加(输入1增加否则退出):");
	scanf("%d",&x);
	if(x==1)
		goto addstu;
}
void modstuinfo()			//修改学生信息
{
	char s[50]={0},modify[50]={0},stusel[50]={0},couname[50]={0};
	int i=0,x=0,j=0,data1=0,t=0,k=0;
	system("clear");
	if(n1<=0)
	{
		printf("                    没有任何学生信息!\n");
		printf("                    按任意键退出");
		getchar();
		getchar();
		return;
	}
	printf("                    学生信息如下:\n");
	outputstu();
	mod:
	if((fplog=fopen("log.log","a+"))==NULL)
		printf("write log.log error");
	printf("                    输入要修改的学生学号:");
	scanf("%s",s);
	for(i=0;i<n1;i++)
		if(strcmp(s,stu[i].stuid)==0)
			break;
	mod1:
	if(i>=n1)
	{
		printf("                    输入错误!\n");
		goto mod;
	}
	else
		printf("                    输入要修改的信息类别:");
	scanf("%s",modify);
	for(j=0;j<4;j++)
		if(strcmp(modify,student[j])==0)
		{
			printf("                    输入修改后的数据:");

			if(j==3)
			{
				nowtime();
				fprintf(fplog,"mod stu %f",stu[i].credit);
				scanf("%f",&stu[i].credit);
				fprintf(fplog," %f\n",stu[i].credit);
				fprintf(fplog,"============================================\n");
			}
			else if(j==0)
			{
				nowtime();
				fprintf(fplog,"mod stu %s",stu[i].stuid);
				scanf("%s",stu[i].stuid);
				fprintf(fplog," %s\n",stu[i].stuid);
				fprintf(fplog,"============================================\n");
			}
			else if(j==1)
			{
				nowtime();
				fprintf(fplog,"mod stu %s",stu[i].name);
				scanf("%s",stu[i].name);
				fprintf(fplog," %s\n",stu[i].name);
				fprintf(fplog,"============================================\n");
			}
			else
			{
				nowtime();
				fprintf(fplog,"mod stu %s",stu[i].select);
				strcpy(stusel,stu[i].select);
				stu[i].credit=0;
				scanf("%s",stu[i].select);
				fprintf(fplog," %s\n",stu[i].select);
				fprintf(fplog,"============================================\n");
				x=0;
				while(stusel[x])
				{
					t=0;
					while(stusel[x]&&stusel[x]!=',')
					{		
						couname[t]=stusel[x];
						x++;
						t++;
					}	
					couname[t]=0;
					for(k=0;k<n2;k++)
						if(strcmp(couname,cou[k].couid)==0)
							break;
					cou[k].chosen-=1;
					x++;
				}
				x=0;
				while(stu[i].select[x])
				{
					t=0;
					while(stu[i].select[x]&&stu[i].select[x]!=',')
					{
						couname[t]=stu[i].select[x];
						x++;
						t++;
					}
					couname[t]=0;
					for(k=0;k<n2;k++)
						if(strcmp(couname,cou[k].couid)==0)
							break;
					cou[k].chosen+=1;
					stu[i].credit+=cou[k].credit;
					x++;
				}
			}
			break;
		}
	fclose(fplog);
	if(j>=4)
	{
		printf("                    输入错误!\n");
		goto mod1;
	}
	printf("                    修改后结果如下:\n");
	outputstu();
	printf("                    是否要继续修改(输入1继续,输入其他退出):");
	scanf("%d",&x);
	if(x==1)
		goto mod;
}
void delstuinfo()			//删除学生信息
{
	char s[50]={0},couname[50]={0};
	int i=0,x=0,j=0,t=0,k=0;
	system("clear");
	printf("                    学生信息如下:\n");
	outputstu();
	del:
	if((fplog=fopen("log.log","a+"))==NULL)
		printf("write log.log error");
	if(n1==0)
		{
			printf("                    已无学生信息!按任意键返回");
			getchar();
			getchar();
			return;
		}
	j=0;
	printf("                    输入要删除的学生学号:");
	scanf("%s",s);
	for(i=0;i<n1;i++)
		if(strcmp(s,stu[i].stuid)==0)
			break;
	while(stu[i].select[j])
	{
		t=0;
		while(stu[i].select[j]&&stu[i].select[j]!=',')
		{
			couname[t]=stu[i].select[j];
			j++;
			t++;
		}
		couname[t]=0;
		for(k=0;k<n2;k++)
			if(strcmp(couname,cou[k].couid)==0)
				break;
		cou[k].chosen-=1;
		j++;
	}
	if(i>=n1)
	{	
		printf("                    输入学生学号错误！\n");
		fclose(fplog);
		goto del;
	}
	else
		n1--;
	nowtime();
	fprintf(fplog,"del stu %s\n",stu[i].stuid);
	fprintf(fplog,"============================================\n");
	fclose(fplog);
	for(;i<n1;i++)
		stu[i]=stu[i+1];
	
	printf("                    删除后结果如下:\n");
	outputstu();
	printf("                    是否要继续删除(输入1继续,输入其他退出):");
	scanf("%d",&x);
	if(x==1)
		goto del;
}
void seestuinfo()		//查看学生信息
{
	int x,i=0;
	char s[50]={0};
	system("clear");
	see:
	printf("                    输入要查找的学生学号:");
	scanf("%s",s);
	for(i=0;i<n1;i++)
		if(strcmp(s,stu[i].stuid)==0)
			break;
	if(i>=n1)
	{
		printf("                    未找到!\n");
		goto see;
	}
	else	
		printf("                    %s  %s  %-12s    %.1f\n",stu[i].stuid,stu[i].name,stu[i].select,stu[i].credit);
	printf("                    是否要修改信息(输入1修改否则退出):");
	scanf("%d",&x);
	if(x==1)
		modstuinfo();
}
