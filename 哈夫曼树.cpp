#include<stdio.h>
#include<stdlib.h>

#define MAXVALUE 10000// Ҷ�ӽ������ֵ,���Ȩֵ
#define MAXLEAF 30// �����30��Ҷ�ӽ��
#define MAXNODE 2*MAXVALUE-1// ����������޶�Ϊ1�Ľ�㣬�ܽ����
#define MAXBIT 10// ��������ֹ����������
// n=n0+n2.��n0=30ʱ�����ݶ�����ϵ����n0=n2+1,n2=n0-1=29,���Թ�������
// �����30+29=59�����

// �þ�̬��������ʵ�ֵĹ����������Ͷ�������

typedef struct
{
  int weight;// ����Ȩֵ
  int parent;// ˫�׵��±�
  int LeftChild;// ���ӽ����±�
  int RightChild;// �Һ��ӽ����±�
}HtNode;// HuffmanTree��һ���ṹ�������ͣ�0�ŵ�Ԫ����

typedef struct
{
  int bit[MAXBIT];// ������ַ�����������Ŀռ�
  int start;// ������ַ�����������Ŀ�ʼλ��
}HCodeType;

// ������������㷨ʵ��
typedef char * HtCode[MAXVALUE+1];// �洢���������봮��ͷָ������

// ����Ҷ�ӽ��ĺ���
int scan()
{
  int n;
  scanf("%d",&n);// ����Ҷ�ӵĽڵ���
  return n;
}

// �������������㷨
void CreateHuffmanTree(HtNode HuffNode[])
{
  int i,j;
  int m1,m2;// Ҷ�ӽ��
  int x1,x2;
  int a;// ����Ҷ�ӵĽ����
  a=scan();// ��������Ҷ�ӽ�㺯�����������Ҷ�ӽ�㸳ֵ��a

  // ��ʼ��������

  for(i=0;i<2*a-1;i++)// 2*a-1�ǹ������������
  {
    HuffNode[i].weight=0;// ��ʼ��ȨֵΪ0
    HuffNode[i].parent=-1;// ��ʼ��˫���±�
    HuffNode[i].LeftChild=-1;// ��ʼ������
    HuffNode[i].RightChild=-1;// ��ʼ���Һ���
  }

  //��ʼ����ɣ�

  for(i=0;i<a;i++)
  {
    scanf("%d",&HuffNode[i].weight);// ����Ȩֵ
  }

  for(i=0;i<a-1;i++)
  {
    m1=m2=MAXVALUE;
    x1=x2=0;
    for(j=0;j<a+i;j++)
    {
      if (HuffNode[j].parent==-1&&HuffNode[j].weight<m1)
      {
        m2=m1;
        x2=x1;
        m1=HuffNode[j].weight;
        x1=j;// ���x1����ʾ��ȣ�
      }
      else if(HuffNode[j].parent==-1&&HuffNode[j].weight<m2)
      {
        m2=HuffNode[j].weight;
        x2=j;// ������
      }
    }
    HuffNode[x1].parent=a+i;
    HuffNode[x2].parent=a+i;
    HuffNode[a+i].weight=HuffNode[x1].weight+HuffNode[x2].weight;
    HuffNode[a+i].LeftChild=x1;
    HuffNode[a+i].RightChild=x2;
  }
}
// void CreateHuffmanTree(HuffmanTree ht,int w[],int n)
// // �����������ht[M+1]��w[]���n��Ȩֵ
// {
//   int m,i;
//   for(i=1;i<=n;i++)
//   {
//     ht[i]={w[i],0,0,0};// 1~n�ŵ�Ԫ���Ҷ�ӽ�㣬��ʼ��
//   }
//   m=2*n-1;
//   for(i=n+1;i<=m;i++)
//   {
//     ht[i]={0,0,0,0};// n+1~m�ŵ�Ԫ��ŷ�Ҷ��㣬��ʼ��
//   }
//   // ��ʼ����ϣ���Ӧ�㷨����1
//
//   //��ʼ����
//   for(i=n+1;i<=m;i++)
//   {
//     select
//   }
// }

// �����������ʵ��
void HuffmanCode()
{
  HtNode HuffNode[MAXNODE];
  HCodeType HuffCode[MAXLEAF],cd;
  int i,j;
  int c,p;
  int b;// ����Ҷ�ӵĽ����
  b=scan();// ��������Ҷ�ӽ�㺯�����������Ҷ�ӽ�㸳ֵ��b

  CreateHuffmanTree(HuffNode);
  // ������������
  for(i=0;i<b;i++)
  {
    cd.start=b-1;
    c=i;
    p=HuffNode[c].parent;
    while(p!=-1)
    {
      if(HuffNode[p].LeftChild==c)
      {
        cd.bit[cd.start]=0;
      }
      else
      {
        cd.bit[cd.start]=1;
      }
      cd.start--;
      c=p;
      p=HuffNode[c].parent;
    }
    for(j=cd.start+1;j<b;j++)
    {
      HuffCode[i].bit[i]=cd.bit[j];
    }
    HuffCode[i].start=cd.start;
  }
  for(i=0;i<b;i++)
  {
    for(j=HuffCode[i].start+1;j<b;j++)
    {
      printf("%d",HuffCode[i].bit[j]);
    }
    printf("\n");
  }
}

// ����������
int scan();// ����Ҷ�ӵĽ�����ĺ���
void CreateHuffmanTree(HtNode HuffNode[]);// ����һ����������
void HuffmanCode();// �����������ʵ��

int main(int argc, char const *argv[]) {
  int e;
  e=scan();
  printf("Ҷ�ӵĽ����Ϊ %d\n",e);
  HuffmanCode();
  
  return 0;
}
