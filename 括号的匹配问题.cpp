#include"D:\code\c_notebook\Stack.h"
void BracketMatch(StackElementType *str)
{
    SeqStack S;
    int i;
    StackElementType ch;//char ch;
    InitStack(&S);//初始化栈S
    for(i = 0;str[i] != '\0';i++)
    {
      switch (str[i]) {
        case '(':
        case '[':
        case '{':
        {
          Push(&S,str[i]);//进栈
          break;
        }
        case ')':
        case ']':
        case '}':
        {
          if(IsEmpty(&S))//判空
          {
            printf("\n右括号多余！");
          }
          else
          {
            GetTop(&S,&ch);//读栈顶元素
            if(Match(ch,str[i]))//用match判断两个括号是否匹配
            {
              pop(&S,&ch);
            }
            else
            {
              printf("\n对应的左右括号不同类！");
              return;
            }
          }
        }
      }
    }
    if (IsEmpty(&S))
    {
      printf("\n括号匹配！");
    }
    else
    {
      printf("\n左括号多余！");
    }
}
//IsEmpty(头文件中)和Match未正确
