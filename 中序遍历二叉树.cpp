#include<stdio.h>
#include <stdlib.h>
#define M 100

typedef struct node
{
  char data;// 数据域
  int left_tag;// 左标志
  int right_tag;// 右标志
  struct node *leftChild,*rightChild;// 左孩子，右孩子
}BiTree;// 树

BiTree *pre=NULL;// 刚处理过的结点

// 用扩展先序遍历序列创建二叉链表（初始化）
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
    bt->leftChild=CreateBiTree();
    bt->rightChild=CreateBiTree();
  }
  return bt;
}

// 中序遍历二叉树非递归算法初步
void inorder_Thread(BiTree *p)
{
  if(p!=NULL)
  {
    inorder_Thread(p->leftChild);
    if(p->leftChild==NULL)
    {
      p->left_tag=1;
    }

    if(p->rightChild==NULL)
    {
      p->right_tag=1;
    }

    if(p->left_tag==1)
    {
      p->leftChild=pre;
    }

    if(pre!=NULL&&pre->right_tag==1)
    {
      pre->rightChild=p;
    }

    inorder_Thread(p->rightChild);
  }
}

// 中序遍历二叉树非递归算法1
void InOrder1(BiTree *bt)
{
  if(bt==NULL)
  {
    return;
  }
  InOrder1(bt->leftChild);
  putchar(bt->data);
  InOrder1(bt->rightChild);
}

// 中序遍历二叉树非递归算法2
void InOrder2(BiTree *bt)
{
  int i=0;
  BiTree *p,*s[M];
  p=bt;
  do {
    while (p!=NULL) {
      s[i++]=p;
      p=p->leftChild;
      if(i>0)
      {
        p=s[-i];
        printf("%d\t",p->data);
        p=p->rightChild;
      }
    }
  } while(i>0||p!=NULL);
}

BiTree *Inorder_Next(BiTree *p)
{
  BiTree *q;
  if(p)
  {
    if(p->right_tag==1)
    {
      return p->rightChild;
    }
    else
    {
      q=p->rightChild;
      while (q->left_tag==0) {
        q=q->leftChild;
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
    while (p->left_tag==0) {
      p=p->leftChild;
    }
    while (p) {
      putchar(p->data);
      p=Inorder_Next(p);
    }
  }
}
