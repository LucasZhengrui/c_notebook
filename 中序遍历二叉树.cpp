#include<stdio.h>
#include <stdlib.h>
#define M 100


typedef enum{ Link, Thread } PointerTag;

typedef struct node
{
  char data;// 数据域
  int LeftTag;// 左标志
  int RightTag;// 右标志
  struct node *LeftChild,*RightChild;// 左孩子，右孩子
}BiTree;// 树

BiTree *pre=NULL;// 刚处理过的结点

// 用扩展中序遍历序列创建二叉链表
BiTree *CreateBiTree()
{
  BiTree *bt;
  char ch;
  ch=getchar();
  if(ch=='.')
  {
    bt=NULL;
  }
  else
  {
    bt=(BiTree*)malloc(sizeof(BiTree));
    bt->LeftChild=CreateBiTree();
    bt->data=ch;
    bt->RightChild=CreateBiTree();
  }
  return bt;
}

// 中序遍历二叉树非递归算法初步
void inorder_Thread(BiTree *p)
{
  if(p!=NULL)
  {
    inorder_Thread(p->LeftChild);
    if(p->LeftChild==NULL)
    {
      p->LeftTag=1;
    }

    if(p->RightChild==NULL)
    {
      p->RightTag=1;
    }

    if(p->LeftTag==1)
    {
      p->LeftChild=pre;
    }

    if(pre!=NULL&&pre->RightTag==1)
    {
      pre->RightChild=p;
    }

    inorder_Thread(p->RightChild);
  }
}

// 中序遍历二叉树递归算法
void InOrder(BiTree *bt)
{
  if(bt==NULL)
  {
    return;
  }
  InOrder(bt->LeftChild);
  putchar(bt->data);
  InOrder(bt->RightChild);
}

// 中序遍历二叉树非递归算法
// void InOrder2(BiTree *bt)
// {
//  int i=0;
//  BiTree *p,*s[M];
//  p=bt;
//  do {
//    while (p!=NULL) {
//      s[i++]=p;
//      p=p->LeftChild;
//      if(i>0)
//      {
//        p=s[-i];
//        printf("%d\t",p->data);
//        p=p->RightChild;
//      }
//    }
//  } while(i>0||p!=NULL);
// }
// 修改
void InOrder3(BiTree *bt)
{
  int i=0;
  BiTree *s[M];
  while(bt)// 将根节点赋值给bt
  {
    while(bt->LeftChild)// 如果有左孩子，继续
    {
      s[i++]=bt;
      bt=bt->LeftChild;// 将根节点的左孩子赋值给bt
    }
    printf("%c ",bt->data);// 打印出根节点的左孩子
    if(bt->RightChild)// 如果该左孩子有右孩子
    {
      bt=bt->RightChild;// 则将该左孩子的右孩子赋值给bt
      continue;
    }
    while(!bt->RightChild && i>0)// 如果此时的bt没有右孩子，且此时bt不是根节点
    {
      bt=s[--i];// 将bt退回根节点，并循环回去判断根节点的右孩子
      printf("%c ",bt->data);// 打印根节点
    }
    bt=bt->RightChild;
  }
  printf("\n");
}

// void InThreding(BiTree *BT)
// {
// 	if (BT)
// 	{
// 		InThreding(BT->LeftChild);//递归左孩子线索化
// 		//结点处理
// 		if (!BT->LeftChild)      //如果该结点没有左孩子，
// 		{
// 			BT->LeftTag = 1;
// 			BT->LeftChild = pre;
// 		}
// 		if (!pre->RightChild)
// 		{
// 			pre->RightTag = 1;
// 			pre->RightChild = BT;
// 		}
// 		pre = BT;
// 		InThreding(BT->RightChild);//递归右孩子线索化
// 	}
// }

BiTree *Inorder_Next(BiTree *p)
{
  BiTree *q;
  if(p)
  {
    if(p->RightTag==1)
    {
      return p->RightChild;
    }
    else
    {
      q=p->RightChild;
      while (q->LeftTag==0) {
        q=q->LeftChild;
      }
      return q;
    }
  }
  return NULL;
}

// 线索化二叉树
void Travel_inorder(BiTree *b)
{
  BiTree *p=b;
  if(p)
  {
    while (p->LeftTag==0) {
      p=p->LeftChild;
    }
    while (p) {
      putchar(p->data);
      p=Inorder_Next(p);
    }
  }
}

// 求二叉树的高度，即层深参数nlayer
int TreeDepth(BiTree *bt)
{
  int LeftDepth;// 左子树的深度
  int RightDepth;// 右子树的深度
  int Max;// 定义一个变量，表示左右子树的较大深度
  if(bt!=NULL)
  {
    LeftDepth=TreeDepth(bt->LeftChild);// 求左子树的深度
    RightDepth=TreeDepth(bt->RightChild);// 求右子树的深度
    Max=LeftDepth>RightDepth?LeftDepth:RightDepth;// 得到较大值
    return Max+1;
  }
  else
  {
    return 0;
  }
}

// 按树状打印二叉树
void PrintTree(BiTree *bt,int nLayer)// 按竖向树状打印的二叉树,nLayer为层深参数
{
  if(bt==NULL)
  {
    return;
  }
  PrintTree(bt->LeftChild,nLayer+1);
  for(int i=0;i<nLayer;i++)
  {
    printf("   ");
  }
  printf("%c\n",bt->data);
  PrintTree(bt->RightChild,nLayer+1);
}

// 函数的声明

BiTree *CreateBiTree();// 创建二叉树
void inorder_Thread(BiTree *p);// 中序线索化
void InOrder(BiTree *bt);// 中序递归遍历算法结果
void InOrder3(BiTree *bt);// 中序非递归遍历算法结果
BiTree *Inorder_Next(BiTree *p);
void Travel_inorder(BiTree *b);// 线索化二叉树
int TreeDepth(BiTree *bt);//深度函数
void PrintTree(BiTree *bt,int nLayer);// 按树状打印二叉树

//主函数

int main()
{
  int nLayer;
  BiTree *root;

  root=CreateBiTree();
  nLayer=TreeDepth(root);
  inorder_Thread(root);// 中序线索化

  printf("\n中序递归遍历算法结果：");
  InOrder(root);
  printf("\n中序非递归遍历算法结果：");
  InOrder3(root);
  printf("\n中序线索化二叉树遍历算法结果：");
  Travel_inorder(root);
  printf("\n中序遍历二叉树的高度：");
  printf("%d",nLayer);
  printf("\n中序遍历二叉树的打印：\n");
  PrintTree(root,nLayer);
  printf("\n");
}
