#include<stdio.h>
#include<stdlib.h>

#define MAXVALUE 10000// 叶子结点的最大值,最大权值
#define MAXLEAF 30// 最多有30个叶子结点
#define MAXNODE 2*MAXVALUE-1// 因哈夫曼树无度为1的结点，总结点数
#define MAXBIT 10// 定义各名字哈夫曼编码的
// n=n0+n2.当n0=30时，根据二叉树系性质n0=n2+1,n2=n0-1=29,所以哈夫曼树
// 最多有30+29=59个结点

// 用静态三叉链表实现的哈夫曼树类型定义如下

typedef struct
{
  int weight;// 结点的权值
  int parent;// 双亲的下标
  int LeftChild;// 左孩子结点的下标
  int RightChild;// 右孩子结点的下标
}HtNode;// HuffmanTree是一个结构数组类型，0号单元不用

typedef struct
{
  int bit[MAXBIT];// 保存各字符哈夫曼编码的空间
  int start;// 保存各字符哈夫曼编码的开始位置
}HCodeType;

// 哈夫曼编码的算法实现
typedef char * HtCode[MAXVALUE+1];// 存储哈夫曼编码串的头指针数组

// 输入叶子结点的函数
int scan()
{
  int n;
  scanf("%d",&n);// 输入叶子的节点数
  return n;
}

// 创建哈夫曼树算法
void CreateHuffmanTree(HtNode HuffNode[])
{
  int i,j;
  int m1,m2;// 叶子结点
  int x1,x2;
  int a;// 定义叶子的结点数
  a=scan();// 将“输入叶子结点函数”中输入的叶子结点赋值给a

  // 初始化二叉树

  for(i=0;i<2*a-1;i++)// 2*a-1是哈夫曼树的深度
  {
    HuffNode[i].weight=0;// 初始化权值为0
    HuffNode[i].parent=-1;// 初始化双亲下标
    HuffNode[i].LeftChild=-1;// 初始化左孩子
    HuffNode[i].RightChild=-1;// 初始化右孩子
  }

  //初始化完成！

  for(i=0;i<a;i++)
  {
    scanf("%d",&HuffNode[i].weight);// 输入权值
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
        x1=j;// 输出x1（表示深度）
      }
      else if(HuffNode[j].parent==-1&&HuffNode[j].weight<m2)
      {
        m2=HuffNode[j].weight;
        x2=j;// 输出深度
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
// // 构造哈夫曼树ht[M+1]，w[]存放n个权值
// {
//   int m,i;
//   for(i=1;i<=n;i++)
//   {
//     ht[i]={w[i],0,0,0};// 1~n号单元存放叶子结点，初始化
//   }
//   m=2*n-1;
//   for(i=n+1;i<=m;i++)
//   {
//     ht[i]={0,0,0,0};// n+1~m号单元存放非叶结点，初始化
//   }
//   // 初始化完毕！对应算法步骤1
//
//   //开始建树
//   for(i=n+1;i<=m;i++)
//   {
//     select
//   }
// }

// 哈夫曼编码的实现
void HuffmanCode()
{
  HtNode HuffNode[MAXNODE];
  HCodeType HuffCode[MAXLEAF],cd;
  int i,j;
  int c,p;
  int b;// 定义叶子的结点数
  b=scan();// 将“输入叶子结点函数”中输入的叶子结点赋值给b

  CreateHuffmanTree(HuffNode);
  // 建立哈夫曼树
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

// 函数的声明
int scan();// 输入叶子的结点数的函数
void CreateHuffmanTree(HtNode HuffNode[]);// 创建一个哈夫曼树
void HuffmanCode();// 哈夫曼编码的实现

int main(int argc, char const *argv[]) {
  int e;
  e=scan();
  printf("叶子的结点数为 %d\n",e);
  HuffmanCode();
  
  return 0;
}
