#ifndef _STUCOU_H
#define _STUCOU_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct
{
	char stuid[50];
	char name[50];
	char select[50];
	float credit;
}stu[100];
struct
{
	char couid[50];
	char couname[50];
	char counature[50];
	int hour;
	float credit;
	int chosen;
	int max;

}cou[100];
char student[4][50],course[7][50];
int n1,n2;
FILE *fplog;
void outputcou(void);
void outputstu(void);
void rtitleinput(void);
void fileinput(void);
void nowtime(void);
void keyboardinput(void);
int menu(void);
#endif
