#include<stdio.h>
#include<stdlib.h>
#define N 20
#define ERROR 1
#define OK 0
 
typedef struct 
{
	ElemType data[N];
  	int top;  //Indicator of the stack
}SqStack; //Define the type of the stack

//Define the funtions

void Init_Stack(SqStack *&s)
{     
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;
} // Initialization of the stack 

void Release_Stack(SqStack *&s)
{
	free(s); // The sentense of the release
} // Release the stack

int Length_stack(SqStack *s)
{
	return(s->top+1);
} // Calculate the length of the stack

int Judge_Empty(SqStack *s)
{
	return(s->top==-1);
} // Judge whether the stack is empty or not

int Push(SqStack *&s,ElemType e)
{	
	if (s->top==MaxSize-1) return 0;
	/*栈满的情况,即栈上溢出*/
	s->top++;	
	s->data[s->top]=e;
	return 1;
}




