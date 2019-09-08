//预处理部分，包含所要使用函数对应的头文件或者程序文件，以及符号常量的定义
#include<stdio.h>
#define N 5
//可能使用的函数的原型
void Input(int a[N]);
void Output(int a[N]);
void Select_Sort(int a[N]);
//所有可能使用的函数的定义部分
void Input(int a[N])
{
	int i;
	
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);	
	}	
}
void Output(int a[N])
{
	int i;
	
	for(i=0;i<N;i++)
	{
		printf("%d  ",a[i]);	
	}		
}
void Select_Sort(int a[N])
{
	int i,j,t,min;
	
	for(i=0;i<N-1;i++)
	{
		min=i;
		for(j=i+1;j<N;j++)
		{
			if(a[min]>a[j])
			{
				min=j;
			}
		}
		if(i!=min)
		{
			t=a[i];
			a[i]=a[min];
			a[min]=t;
		}
	}
}
//主函数
int main()
{
	int b[N];
	
	Input(b);
	Output(b);
	Select_Sort(b);
	printf("\n");
	Output(b);
	
	return 0;	
} 
