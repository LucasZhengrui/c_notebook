#include<stdio.h>
#define N 11

void input(int R[N])// 输入函数
{
  for(int i=1;i<=N-1;i++)
  {
    scanf("%d",&R[i]);
  }
}

void SeqSearch(int R[N],int key)// 顺序查找函数
{
  // scanf("%d",&key);
  for(int i=1;i<=N-1;i++)
  {
    if(R[i]==key)
    {
      printf("%d\n",i);
      break;
    }
    else
    {
      continue;
    }
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

// 函数的声明
void input(int R[N]);// 输入函数
void SeqSearch(int R[N],int key);// 顺序查找函数
void output(int R[N]);// 输出函数

int main(int argc, char const *argv[]) {
  int R[N];
  int key;
  printf("Please input the data!\n");
  input(R);
  printf("The data you input are:\n");
  output(R);
  printf("Please input the data you want to search!\n");
  scanf("%d",&key);
  printf("The data you want to search is NO.");
  SeqSearch(R,key);
  return 0;
}
