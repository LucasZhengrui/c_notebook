#include<stdio.h>
#include <stdlib.h>
#define M 100


typedef enum{ Link, Thread } PointerTag;

typedef struct node
{
  char data;// ������
  int LeftTag;// ���־
  int RightTag;// �ұ�־
  struct node *LeftChild,*RightChild;// ���ӣ��Һ���
}BiTree;// ��

BiTree *pre=NULL;// �մ�����Ľ��

// ����չ����������д�����������
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

// ��������������ǵݹ��㷨����
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

// ��������������ݹ��㷨
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

// // ��������������ǵݹ��㷨
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

// void InThreding(BiTree *BT)
// {
// 	if (BT)
// 	{
// 		InThreding(BT->LeftChild);//�ݹ�����������
// 		//��㴦��
// 		if (!BT->LeftChild)      //����ý��û�����ӣ�
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
// 		InThreding(BT->RightChild);//�ݹ��Һ���������
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

// ������������
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

// ��������ĸ߶ȣ����������nlayer
int TreeDepth(BiTree *bt)
{
  int LeftDepth;// �����������
  int RightDepth;// �����������
  int Max;// ����һ����������ʾ���������Ľϴ����
  if(bt!=NULL)
  {
    LeftDepth=TreeDepth(bt->LeftChild);// �������������
    RightDepth=TreeDepth(bt->RightChild);// �������������
    Max=LeftDepth>RightDepth?LeftDepth:RightDepth;// �õ��ϴ�ֵ
    return Max+1;
  }
  else
  {
    return 0;
  }
}

// ����״��ӡ������
void PrintTree(BiTree *bt,int nLayer)// ��������״��ӡ�Ķ�����,nLayerΪ�������
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

// ����������

BiTree *CreateBiTree();// ����������
void inorder_Thread(BiTree *p);
void InOrder(BiTree *bt);// ����ݹ�����㷨���
void InOrder2(BiTree *bt);// ����ǵݹ�����㷨���
BiTree *Inorder_Next(BiTree *p);
void Travel_inorder(BiTree *b);// ������������
int TreeDepth(BiTree *bt);//��Ⱥ���
void PrintTree(BiTree *bt,int nLayer);// ����״��ӡ������

//������

int main()
{
  int nLayer;
  BiTree *root;

  root=CreateBiTree();
  nLayer=TreeDepth(root);
  inorder_Thread(root);

  printf("\n����ݹ�����㷨�����");
  InOrder(root);
  printf("\n����ǵݹ�����㷨�����");
  // InThreding(root);
  printf("\n���������������������㷨�����");
  Travel_inorder(root);
  printf("\n��������������ĸ߶ȣ�");
  printf("%d",nLayer);
  printf("\n��������������Ĵ�ӡ��\n");
  PrintTree(root,nLayer);
  printf("\n");
}
