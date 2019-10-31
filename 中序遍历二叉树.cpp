#include<stdio.h>
#include <stdlib.h>
#define M 100

typedef struct node
{
  char data;// 数据域
  int LeftTag;// 左标志
  int RightTag;// 右标志
  struct node *LeftChild,*RightChild;// 左孩子，右孩子
}BiTree;// 树

BiTree *pre=NULL;// 刚处理过的结点

// 用扩展先序遍历序列创建二叉链表
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
    bt->data=ch;
    bt->LeftChild=CreateBiTree();
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

// 中序遍历二叉树非递归算法1
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

// 中序遍历二叉树非递归算法2
//void InOrder2(BiTree *bt)
//{
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
//}

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

// 按树状打印二叉树
void PrintTree(BiTree *bt,int nLayer)// 按竖向树状打印的二叉树,Layer为层 
{
  if(bt==NULL)
  {
	PrintTree(bt->RightChild,nLayer);
  }
  for(int i=0;i<nLayer;i++)
  {
    printf(" ");		
  }
  printf("%c\n",bt->data);
  PrintTree(bt->LeftChild,nLayer+1);
} 

// 函数的声明

BiTree *CreateBiTree();// 创建二叉树 
void inorder_Thread(BiTree *p); 
void InOrder(BiTree *bt);
BiTree *Inorder_Next(BiTree *p);
void Travel_inorder(BiTree *b);
void PrintTree(BiTree *bt,int nLayer);// 按树状打印二叉树 

//主函数

int main()
{
  int nLayer;	
  BiTree *root;

  root=CreateBiTree();
//  Travel_inorder(root);
//  PrintTree(root,nLayer);
  printf("\n中序非递归遍历算法结果：");
  InOrder(root);
//  printf("\n中序递归遍历算法结果：");
  inorder_Thread(root);
  printf("\n中序线索二叉树遍历算法结果：");
  Travel_inorder(root);
}
