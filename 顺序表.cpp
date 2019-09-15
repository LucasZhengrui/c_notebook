#include "stdio.h"
#include "stdlib.h"
#define M  20


typedef char datatype;//datatype在下方相当于char
typedef struct
{
	datatype data[M];//相当于char data[M]
	int last;
}Seq;//顺序表

Seq *Init();
Seq *Create();
int Len(Seq *L);
int Full(Seq *L);
int Empty(Seq *L);
datatype Get(Seq *L,int i);
int Loca(Seq *L,datatype x);
Seq *Insert(Seq *L,int i,datatype x);
Seq *Dele(Seq *L,int i);

Seq *Init()
{
	Seq *LA;

	LA=malloc(sizeof(Seq));
	LA->last=-1;

	return LA;
}

Seq *Create()
{
	datatype x;
	Seq *LA;

	LA=Init();
	x=getchar();

	while(x!='$'&&!Full(LA))
	{
		LA->last++;
		LA->data[L->last]=x;
		x=getchar();
    }

    return LA;
}

int Len(Seq *L)
{
	return L->last+1;
}

int Full(Seq *L)
{
	return L->last==M-1;
}

int Empty(Seq *L)
{
	return L->last==-1;
}

datatype Get(Seq *L,int i)
{
	if(i<1||i>L->last+1)
	   printf("位置非法!");
	else
	   return L->data[i-1];
}

int Loca(Seq *L,datatype x)
{
	int i;

	for(i=0;i<=L->last;i++)
	    if(L->data[i]==x)
	       return i+1;

	return 0;
}

Seq *Insert(Seq *L,int i,datatype x)
{
}

Seq *Dele(Seq *L,int i)
{
}


int main()
{
	return 0;
}
