#include<stdio.h>
#include<stdlib.h>
#define ERROR 1
#define OK 0
#define N 40   //The max length

//Define the funtions
typedef struct {
	char ch[N];
	int len;   //length
}string; //The funtion of the initialization of the string

void StrAssign(SqString &str,char cstr[])  
{
	int i;
    for (i=0;cstr[i]!='\0';i++)
    {
		str.data[i]=cstr[i];
    }
	str.len=i;
}
