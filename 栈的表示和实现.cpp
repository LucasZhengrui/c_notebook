#include<stdio.h>
#include <stdlib.h>
#define Stack_Size 50 // 设栈中元素个数为50
#define false 0
#define true 1
typedef char StackElementType;
// 顺序栈的定义
typedef struct
{
  StackElementType elem[Stack_Size]; // 用来存放栈中元素的一维数组
  int top; // 用来存放栈顶元素的下标，top为-1表示空栈
}SeqStack;

// 初始化顺序栈
void InitStack(SeqStack *S)
{
  // 构造一个空栈
  S->top=-1;
}

// 进栈
int Push(SeqStack *S,StackElementType x)
{
  // 将x置入S栈新栈顶
  if(S->top==Stack_Size-1)
  {
    return false;
  }
  S->top++;
  S->elem[S->top]=x;
  return true;
}

//出栈
int pop(SeqStack *S,StackElementType *x)
{//将S栈顶元素弹出，放到x所指的存储空间中带出
  if(S->top==-1)//如果栈为空
  {
    return 0;
  }
  else
  {
    *x=S->elem[S->top];//将栈顶元素赋给x
    S->top--;//修改栈顶指针
    return 1;
  }
}

//读栈顶元素
int GetTop(SeqStack *S,StackElementType *x)
{//将栈S栈顶元素读出，放到x所指的存储空间中，栈顶指针保持不变
  if(S->top==-1)//栈为空
  {
    return 0;
  }
  else
  {
    *x=S->elem[S->top];//栈顶元素赋给x
    return 1;
  }
}
