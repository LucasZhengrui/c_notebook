#include "stdio.h"
#include "stdlib.h"

// 先序遍历二叉树

void PreOrder(BiTree root)
// 先序遍历二叉树，root为指向二叉树（或某一子树）根结点的指针
{
  if(root!=NULL)
  {
    Visit(root->data);// 访问根结点
    PreOrder(root->LChild);// 先序遍历左子树（左孩子）
    PreOrder(root->RChild);// 先序遍历右子树（右孩子）
  }
}

// 中序遍历二叉树

void InOrder(BiTree root)
// 中序遍历二叉树，root为指向二叉树（或某一子树）根结点的指针
{
  if(root!=NULL)
  {
    InOrder(root->LChild);// 中序遍历左子树
    Visit(root->data);// 访问根结点
    InOrder(root->RChild);// 中序遍历右子树
  }
}

// 后序遍历二叉树

void PostOrder(BiTree root)
// 后序遍历二叉树，root为指向二叉树（或某一子树）根结点的指针
{
  if(root!=NULL)
  {
    PostOrder(root->LChild);// 后序遍历左子树
    PostOrder(root->RChild);// 后序遍历右子树
    Visit(root->data);// 访问根结点
  }
}
