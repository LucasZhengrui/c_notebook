//Ԥ�����֣�������Ҫʹ�ú�����Ӧ��ͷ�ļ����߳����ļ����Լ����ų����Ķ���
#include<stdio.h>
#define N 5
//����ʹ�õĺ�����ԭ��
void Input(int a[N]);
void Output(int a[N]);
void Select_Sort(int a[N]);
//���п���ʹ�õĺ����Ķ��岿��
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
//������
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
