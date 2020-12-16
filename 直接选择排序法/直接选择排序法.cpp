 // 预处理部分，包含所要使用函数对应的头文件或者程序文件，以及符号常量的定义
#include<stdio.h>
#define N 5 // 定义五个数字的直接选择排序
 // 可能使用的函数的原型
void Input(int a[N]); // 定义输入函数
void Output(int a[N]); // 定义输出函数
void Select_Sort(int a[N]); // 定义目标函数（排序）
 // 所有可能使用的函数的定义部分
void Input(int a[N]) // 输入
{
	int i;

	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
}
void Output(int a[N]) // 输出
{
	int i;

	for(i=0;i<N;i++)
	{
		printf("%d  ",a[i]);
	}
}
void Select_Sort(int a[N]) // 排序
{
	int i,j,t,min;

	for(i=0;i<N-1;i++)
	{
		min=i; // 假设第一个元素就是最小的（有序区）
		for(j=i+1;j<N;j++)
		{
			if(a[min]>a[j]) // 如果最小的元素大于其后面（无序区）的某一个元素（即该最小的元素不是最小的）
			{
				min=j; // 则j为最小元素的下标
			}
		} // for循环结束
		if(i!=min)
		{
			t=a[i];
			a[i]=a[min];
			a[min]=t; // 交换a[i]与a[min]的值
		}
	}
}
//主函数
int main()
{
	int b[N];

	Input(b); // 输入
	Output(b); // 样例（照例）输出
	Select_Sort(b); // 对输入的五个数字进行排序
	printf("\n");
	Output(b);// 输出完成排序的五个数据

	return 0;
}
