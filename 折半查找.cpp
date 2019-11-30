#include<stdio.h>
#define N 11

void input(int R[N])// ���뺯��
{
  for(int i=1;i<=N;i++)
  {
    scanf("%d",&R[i]);
  }
}

void output(int R[N])// �������
{
  for(int i=1;i<=N;i++)
  {
    printf("%d ",R[i]);
  }
  printf("\n");
}

void sort(int R[N])// ð��������
{
  int temp=0;// �����м����
  for(int i=1;i<=N;i++)
  {
    for(int j=i+1;j<=N;j++)
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

int Mid_Search(int R[N],int key)// �۰���Һ���
{
  int temp=0;// �����м����
  for(int i=1;i<=N;i++)
  {
    for(int j=i+1;j<=N;j++)
    {
      if(R[i]>R[j])
      {
        temp=R[i];
        R[i]=R[j];
        R[j]=temp;
      }
    }
  }

  int low=1;
  int high=N-1;
  int mid;
  while(low<=high)
  {
    mid=(low+high)/2;
    if(key==R[mid])
    {
      return mid;
    }
    else if(key<R[mid])
    {
      high=mid-1;
    }
    else
    {
      low=mid+1;
    }
  }
  return -1;
}

// ����������
void input(int R[N]);// ���뺯��
void output(int R[N]);// �������
int Mid_Search(int R[N],int key);// �۰���Һ���

int main(int argc, char const *argv[]) {
  int R[N];
  int key;
  int ret;
  printf("Please input the data!\n");
  input(R);
  printf("The data you input after sort are:\n");
  sort(R);
  output(R);
  printf("Please input the data you want to search!\n");
  scanf("%d",&key);
  ret=Mid_Search(R,key);
  if(ret!=-1)
  {
    printf("���ҳɹ�\n");
  }
  else
  {
    printf("����ʧ��\n");
  }
  return 0;
}
