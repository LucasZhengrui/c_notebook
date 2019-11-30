#include<stdio.h>
#define N 11

void input(int R[N])// 输入函数
{
  for(int i=1;i<=N-1;i++)
  {
    scanf("%d",&R[i]);
  }
}

void output(int R[N])// 输出函数
{
  for(int i=1;i<=N-1;i++)
  {
    printf("%d ",R[i]);
  }
  printf("\n");
}

void sort(int R[N])// 冒泡排序函数
{
  int temp=0;// 定义中间变量
  for(int i=1;i<=N-1;i++)
  {
    for(int j=i+1;j<=N-1;j++)
    {
      if(R[i]>R[j])
      {
        temp=R[i];
        R[i]=R[j];
        R[j]=temp;
      }
    }
  }
}

// 函数的声明
void input(int R[N]);// 输入函数
void output(int R[N]);// 输出函数
void sort(int R[N]);// 冒泡排序函数

int main(int argc, char const *argv[]) {
  int b[N];

  input(b);
  output(b);
  sort(b);
  printf("\n");
  output(b);
  return 0;
}
