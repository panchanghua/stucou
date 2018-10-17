#include"cou.h"
#include"../include/stucou.h"
void addcou()			//添加课程
{
	int x=0,i=0;
	system("clear");
	addcou:
	if((fplog=fopen("log.log","a+"))==NULL)
		printf("write log.log error");
	printf("                    请输入要增加的课程个数:");
	scanf("%d",&x);
	if(x>0)
		printf("                    请输入依次%s %s %s %s %s %s %s\n",course[0],course[1],course[2],course[3],course[4],course[5],course[6]);
	else
	{
		printf("                    输入错误\n");
		goto addcou;
	}
	for(i=0;i<x;i++)
	{
		printf("                    ");
		scanf("%s%s%s%d%f%d%d",cou[i+n2].couid,cou[i+n2].couname,cou[i+n2].counature,&cou[i+n2].hour,&cou[i+n2].credit,&cou[i+n2].chosen,&cou[i+n2].max);
		nowtime();
		fprintf(fplog,"add cou %s %s %s %d %f %d %d",cou[i+n2].couid,cou[i+n2].couname,cou[i+n2].counature,cou[i+n2].hour,cou[i+n2].credit,cou[i+n2].chosen,cou[i+n2].max);
		fprintf(fplog,"============================================\n");
	}
	n2=n2+x;
	fclose(fplog);
	printf("                    是否继续增加(输入1增加否则退出):");
	scanf("%d",&x);
	if(x==1)
		goto addcou;
}
void delcou()			//删除课程信息
{
	char s[50]={0},stusel[50]={0};
	int i=0,x=0,j=0,k=0,t=0,flag=0;
	system("clear");
	printf("                    课程信息如下:\n");
	outputcou();
	del:
	if((fplog=fopen("log.log","a+"))==NULL)
		printf("write log.log error");
	j=0;
	if(n2==0)
	{
		printf("                    已无课程信息!按任意键返回");
		getchar();
		getchar();
		return;
	}
	printf("                    输入要删除的课程编号:");
	scanf("%s",s);
	for(i=0;i<n2;i++)
		if(strcmp(s,cou[i].couid)==0)
			break;

	while(j<n1)
	{
		t=0;
		flag=1;
		while(stu[j].select[t]&&flag)
		{
			k=0;			
			while(stu[j].select[t]&&stu[j].select[t]!=','&&flag)
			{
				stusel[k]=stu[j].select[t];
				t++;
				k++;
			}
			stusel[k]=0;
			x=0;
			if(strcmp(stusel,s)==0)
			{
				puts(stusel);
				if(t==2)
					if(stu[j].select[t]==0)
					{
						stu[j].select[0]=0;
					}
					else		
						while(stu[j].select[t+x])
						{
							stu[j].select[x]=stu[j].select[t+x+1];
							x++;
						}
				else if(t>2)
						while(stu[j].select[t+x])
						{
							stu[j].select[t+x-2]=stu[j].select[t+x+1];
							x++;
						}					
				stu[j].credit-=cou[i].credit;
				flag=0;
			}
			t++;
		}
		j++;
	}
	if(i>=n2)
	{	
		printf("                    输入课程编号错误!\n");
		fclose(fplog);
		goto del;
	}
	else
		n2--;
	nowtime();
	fprintf(fplog,"del cou %s\n",cou[i].couid);
	fprintf(fplog,"============================================\n");
	fclose(fplog);
	for(;i<n2;i++)
		cou[i]=cou[i+1];
	printf("                    删除后结果如下:\n");
	outputcou();
	puts(stu[0].select);
	printf("                    是否要继续删除(输入1继续,输入其他退出):");
	scanf("%d",&x);
	if(x==1)
		goto del;
}
void modcouinfo()			//修改课程信息
{
	char s[50]={0},modify[50]={0},couname[50]={0},stusel[50]={0};
	int i=0,x=0,j=0,data1=0,k=0,t=0,y=0,flag=0;
	float coucredit=0;
	system("clear");
	printf("                    课程信息如下:\n");
	outputcou();
	mod:
	printf("                    输入要修改的课程编号:");
	scanf("%s",s);
	for(i=0;i<n2;i++)
		if(strcmp(s,cou[i].couid)==0)
			break;
	if(i>=n2)
	{
		printf("                    输入课程编号错误!\n");
		goto mod;
	}
	mod1:
	printf("                    输入要修改的信息类别:");
	scanf("%s",modify);
	for(j=0;j<7;j++)
		if(strcmp(modify,course[j])==0)
		{
			printf("                    输入修改后的数据:");

			if(j==6)
			{
				nowtime();
				fprintf(fplog,"mod cou %d",cou[i].max);
				scanf("%d",&cou[i].max);
				fprintf(fplog," %d\n",cou[i].max);
				fprintf(fplog,"============================================\n");
			}
			else if(j==5)
			{
				nowtime();
				fprintf(fplog,"mod cou %d",cou[i].chosen);
				scanf("%d",&cou[i].chosen);
				fprintf(fplog," %d\n",cou[i].chosen);
				fprintf(fplog,"============================================\n");
			}
			else if(j==4)
				{
					nowtime();
					fprintf(fplog,"mod cou %.1f",cou[i].credit);
					coucredit=cou[i].credit;
					scanf("%f",&cou[i].credit);
					fprintf(fplog," %.1f\n",cou[i].credit);
					fprintf(fplog,"============================================\n");
					for(k=0;k<n1;k++)
					{
						t=0;
						while(stu[k].select[t])
						{
							y=0;			
							while(stu[k].select[t]&&stu[k].select[t]!=',')
							{
								stusel[y]=stu[k].select[t];
								t++;
								y++;
							}
							stusel[y]=0;
							x=0;
							if(strcmp(stusel,cou[i].couid)==0)
								stu[k].credit=stu[k].credit-coucredit+cou[i].credit;
							t++;
						}
					}
				}
			else if(j==3)
			{
				nowtime();
				fprintf(fplog,"mod cou %d",cou[i].hour);
				scanf("%d",&cou[i].hour);
				fprintf(fplog," %d\n",cou[i].hour);
				fprintf(fplog,"============================================\n");
			}
			else if(j==2)
			{
				nowtime();
				fprintf(fplog,"mod cou %s",cou[i].counature);
				scanf("%s",cou[i].counature);
				fprintf(fplog," %s\n",cou[i].counature);
				fprintf(fplog,"============================================\n");
			}
			else if(j==1)
			{
				nowtime();
				fprintf(fplog,"mod cou %s",cou[i].couname);
				scanf("%s",cou[i].couname);
				fprintf(fplog," %s\n",cou[i].couname);
				fprintf(fplog,"============================================\n");
			}
			else
			{//修改课程编号
				nowtime();
				fprintf(fplog,"mod cou %s",cou[i].couid);
				strcpy(couname,cou[i].couid);
				scanf("%s",cou[i].couid);
				fprintf(fplog," %s\n",cou[i].couid);
				fprintf(fplog,"============================================\n");
				for(k=0;k<n1;k++)
				{
					t=0;
					flag=1;
					while(stu[k].select[t]&&flag)
					{
						y=0;			
						while(stu[k].select[t]&&stu[k].select[t]!=','&&flag)
						{
							stusel[y]=stu[k].select[t];
							t++;
							y++;
						}
						stusel[y]=0;
						x=0;
						if(strcmp(stusel,s)==0)
						{
							if(t==2)
								if(stu[k].select[t]==0)
								{
									stu[k].select[0]=0;
								}
								else		
									while(stu[k].select[t+x])
									{
										stu[k].select[x]=stu[k].select[t+x+1];
										x++;
									}
							else if(t>2)
								while(stu[k].select[t+x])
								{
									stu[k].select[t+x-2]=stu[k].select[t+x+1];
									x++;
								}
							flag=0;
							if(stu[k].select[0]!=0)
								strcat(stu[k].select,",");
							strcat(stu[k].select,cou[i].couid);
						}
						t++;
					}
				}
			}
			break;
		}
	fclose(fplog);
	if(j>=7)
	{
		printf("                    输入信息类型错误!\n");
		goto mod1;
	}
	printf("                    修改后结果如下:\n");
	outputcou();
	printf("                    是否要继续修改(输入1继续,输入其他退出):");
	scanf("%d",&x);
	if(x==1)
		goto mod;
}
void seecouinfo()			//查看课程信息
{
	int x,i=0;
	char s[50]={0};
	system("clear");
	see:
	printf("                    输入要查看的课程编号:");
	scanf("%s",s);
	for(i=0;i<n2;i++)
		if(strcmp(s,cou[i].couid)==0)
			break;
	if(i<n2)
		printf("                    %s %13s %11s %7d %10.1f %4d %13d\n",cou[i].couid,cou[i].couname,cou[i].counature,cou[i].hour,cou[i].credit,cou[i].chosen,cou[i].max);
	else
	{
		printf("                    输入课程编号错误!\n");
		goto see;
	}
	printf("                    是否要修改信息(输入1修改否则退出):");
	scanf("%d",&x);
	if(x==1)
		modcouinfo();
}
